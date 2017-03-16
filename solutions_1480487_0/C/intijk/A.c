#include <stdio.h>
#include <string.h>
#define eps 1e-9
int input[1000];
double p[1000];
int main()
{
	int N,T,i;
	scanf("%d",&T);
	int ca=0;
	while(ca++<T){
		double sum=0,psum=0;	
		scanf("%d",&N);
		for(i=0;i<N;i++){
			scanf("%d",input+i);
			sum+=input[i];
		}


		double l=0,r=20200,m=(l+r)/2;
		while((r-l)>(1e-7))
		{
			psum=0;

			for(i=0;i<N;i++){
				if(input[i]>=m) p[i]=0;
				else{
					p[i]=(m-input[i])/sum*100;
					psum+=p[i];
				}
			}
			if(psum>100+eps) {r=m;m=(l+r)/2;}
			else if(psum<100-eps){l=m;m=(l+r)/2;}
		}
		printf("Case #%d:", ca);
		for(i=0;i<N;i++){
			printf(" %f", p[i]);
		}
		puts("");
	}
	return 0;
}
