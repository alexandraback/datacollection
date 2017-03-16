#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

unsigned long int suma(unsigned long int v[],long int l){
unsigned long int s=0;
int i;

	for(i=0; i<20; i++)
		if( l & 1<<i)
			s+=v[i];
	return s;
}

void mostrar_vector(unsigned long int v[], long int l) {
int i;

	for(i=0; i<20; i++)
		if( l & 1<<i)
			printf("%lu ",v[i]);
	printf("\n");
}

int main(){
int i,j,f;
int T;
int N;
unsigned long int S[20];	// conj numeros
long int I0,I1;	// conj indices (en binario)

	scanf("%d", &T);		// cant casos
	for(i=0;i<T;i++){
		scanf("%d",&N);	
		f=1;
		for(j=0;j<N;j++) 
			scanf("%lu",&S[j]);	// numeros

		for(I0=1;f && I0<pow(2,20);I0++)
			for(I1=1;I1<pow(2,20);I1++)
				if( ! (I0 & I1) ) // los indices son excluyentes
					if( suma(S,I0) == suma(S,I1) ) { 
						//printf("--- %lu %lu\n",I0,I1);
						f=0;	
						break;
					}		
		
		printf("Case #%d:\n", i+1);
		mostrar_vector(S,I0-1);
		mostrar_vector(S,I1);
	}

	return 0;
}
