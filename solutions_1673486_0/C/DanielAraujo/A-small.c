#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void solve(){
	float a, b; int i; double res ,resA;
	double pActual = 1.0;
	char *my_string; char aux[20];
	size_t nbytes = 1000000; 
	my_string = (char *) malloc (nbytes + 1);
	getline (&my_string, &nbytes, stdin);
	sscanf(my_string, "%f %f", &a, &b);
	res = b+2;


		for(i=0; my_string[i]!='\0'; i++){ my_string[i] = '\0';}  
	
	getline (&my_string, &nbytes, stdin);
	for(i=1; i<=a; i++){  	
		sscanf(my_string, "%s", aux);
		pActual *=  atof(aux);
			
			resA = pActual*((b-i)+(a-i)+1) + (1-pActual)*((b-i)+(a-i)+1+b+1);
			
		if(res >  resA) res = resA;
		my_string += (strlen(aux)+1);
	}
	
		printf("%.6f\n",res);
}

int main()
{
  	int bytes_read;
  	size_t nbytes = 20; int n, i;
  	char *my_string;
	my_string = (char *) malloc (nbytes + 1);
  	bytes_read = getline (&my_string, &nbytes, stdin);
  	n = atoi(my_string);
	for(i=0; i<n; i++){
		printf("Case #%d: ",(i+1));
	    solve();		
	}
  return 0;
}