#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int T;
int N,x,y;

int main(void){
	int t,i,j,uk,lk,k,m,h,c;
	double p,in;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d %d %d",&N,&x,&y);
		p = 0.0;
		x = abs(x);
		y = abs(y);
		if((x+y)%2!=0){
			p=0.0;
		}
		else{
			m=(N+2)/4;
			j=(x+y)/2;
			for(c=0,uk=0;c<=j;c++){
				uk+=(4*c)+1;
			}
			/*printf("j:%d m:%d k:%d\n",j,m,uk);*/
			if(N>=uk){
				p=1.0;
			}
			else if(j>m){
				p=0.0;
			}
			else if(x==0 && N<uk){
				p=0.0;
			}
			else{
				in=1.0/pow(2,y+1);
				for(c=0,lk=0;c<j;c++){
					lk+=(4*c)+1;
				}
				k=lk+y+1;
				h=x+y+y+1+lk;
				if(N<k) p=0.0;
				else if(N>=h) p=1.0;
				else if(N>=h-1 && y!=0)p=0.5;
				else if(y==0 && N==lk+1)p=0.5;
				else{
					p=0.0;
					if(k<=N) p=in;
					for(i=k+1;i<=N;i++){
						p+=(in/2.0);
						in=in/2.0;
					}
					if(p>1.0)p=1.0;
				}
			}
		}
		printf("Case #%d: %lf\n",t,p);
	
	}
	return 0;
}
