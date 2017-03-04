#include <stdio.h>
#include <string.h>
#include <strings.h>

int main(int argc,char **argv){
	double max_CPU=-1.0;
	double cpu =0.0;
	char command[127];
	double max_MEM= -1.0;
	double mem = 0.0 ;
	int PID = 0;
	int max_PID;
	char max_command[127];
	char username[127];
	int i = 127;

	if (argc == 1){
	 while (scanf("%s %d %lf %lf %*d %*d %*c %*s %*s %*s %127[^\n]%*[^\n]" ,username,&PID,&cpu,&mem,command) != EOF){
		if ( cpu > max_CPU){
		max_CPU = cpu;
		max_PID = PID;
		strncpy(max_command,command,i);
		}
		if (cpu == max_CPU){
			if ( strcasecmp(command,max_command)< 0 ){
     			   max_CPU = cpu;
	                   max_PID = PID;
           	           strncpy(max_command,command,i);

			}
	        }

	}
	printf("%d\t%.1f\t%s\n",max_PID, max_CPU, max_command);
	printf("Use the arguments [-m or -c] with a username to get a more defined result\n");
	return 1;
	}
	if (argc == 2){
	 while (scanf("%s %d %lf %lf %*d %*d %*c %*s %*s %*s %127[^\n]%*[^\n]" ,username,&PID,&cpu,&mem,command) != EOF){

		if (strncmp(argv[1],username,i) == 0){
		 	if (cpu > max_CPU){
				max_CPU = cpu;
                		max_PID = PID;
                		strncpy(max_command,command,i);
			}
		}
		   if (cpu == max_CPU){
                        if ( strcasecmp(command,max_command)< 0 ){
                           max_CPU = cpu;
                           max_PID = PID;
                           strncpy(max_command,command,i);

                        }
                }


	}}
	if (argc == 3){
	 while (scanf("%s %d %lf %lf %*d %*d %*c %*s %*s %*s %127[^\n]%*[^\n]" ,username,&PID,&cpu,&mem,command) != EOF){

		if ( strncmp(argv[2],username,i) == 0){
		if (strcmp(argv[1],"-m") == 0){
			if (mem > max_MEM){
				max_MEM = mem;
				max_PID = PID;
				strncpy(max_command,command,i);
			}
			   if (cpu == max_CPU){
                        if ( strcasecmp(command,max_command)< 0 ){
                           max_CPU = cpu;
                           max_PID = PID;
                           strncpy(max_command,command,i);

                        }
                }


		}
		if (strcmp(argv[1],"-c") == 0 ){
                        if (cpu > max_CPU){
                                max_CPU = cpu;
                                max_PID = PID;
                               	strncpy(max_command,command,i);
                        }
			   if (cpu == max_CPU){
                        if ( strcasecmp(command,max_command)< 0 ){
                           max_CPU = cpu;
                           max_PID = PID;
                           strncpy(max_command,command,i);

                        }
                }


		}
	}}}
   	if (argc > 3){
		printf("Too many argurments\n");
		return 0;}

	if (max_CPU == -1.0 && max_MEM == -1.0){
		return 0;}
	if (strcmp(argv[1],"-m") == 0){
	printf("%d\t%.1f\t%s\n",max_PID, max_MEM, max_command);}
	else {printf("%d\t%.1f\t%s\n",max_PID, max_CPU, max_command);}
}

