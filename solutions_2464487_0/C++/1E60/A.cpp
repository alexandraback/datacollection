#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(void)
{
	int tc,T;
	scanf("%d\n",&T);
	for (tc=1;tc<=T;tc++){
		long long r,t,y;
		double rd,td;
		scanf("%lld %lld\n",&r,&t);
		rd=(double)r;td=(double)t;
		double B,S;
		double nd;
		B=(rd-0.5);
		S=sqrt(B*B+2.0*td);
		nd=(-B+S)/2.0;
		//近似的な解を得る
		//fprintf(stderr,"%lf %lf %lf\n",rd,td,nd);
		y=(long long)nd;
		while (1){
			//OKならbreak
			long long tt1,tt2;
			tt1=y*(2*y+2*r-1);
			tt2=(y+1)*(2*(y+1)+2*r-1);
			if (tt1<=t && t<tt2)break;
			else if (t<tt1){
				y--;
			}
			else if (tt2<=t){
				y++;
			}
		}
		printf("Case #%d: %lld\n",tc,y);
	}
	return 0;
}
