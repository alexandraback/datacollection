#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

//		#define out stdout
//		#define in stdin


	int T,t,max,temp;
	int E,oE,R,N;
	int value[100];
	
void run(int L)
{
	int i;
	if(L==N){
		if(temp>max){
			max=temp;
//			std::cout<<"max "<<max<<std::endl;
		}
	}
	else{
		for(i=0;i<=E;++i){
			E-=i;
			temp+=(value[L]*i);
			E+=R;
			if(L==N-1 || E<=oE)
			{	
//				std::cout<<"at "<<L<<" consume "<<i<<" gain "<<temp<<std::endl;
					run(L+1);
			}
			E-=R;
			temp-=(value[L]*i);
			E+=i;
		}
	}
	return;
} 
int main(void)
{
#ifndef in
	FILE *in;
	in=fopen("B-small-attempt3.in","rt");
	if(in==NULL){
		printf("\a");
		return -1;
	}
#endif
#ifndef out
	FILE *out;
	out=fopen("b.txt","wt");
	if(out==NULL){
		printf("\a");
		return -1;
	}
#endif
	int i;
	fscanf(in,"%d",&T);
	for(t=1;t<=T;++t){
		fscanf(in,"%d %d %d",&E,&R,&N);
		oE=E;
//		printf("%d %d %d\n",E,R,N);
		for(i=0;i<N;++i){
			fscanf(in,"%d",&value[i]);
//			printf("%d ",value[i]);
		}
//		printf("\n");
		max=0;
		temp=0;
		run(0);
		fprintf(out,"Case #%d: %d\n",t,max);
	}

#ifndef in
	fclose(in);
#endif
#ifndef out
	fclose(out);
#endif
	return 0;
}
