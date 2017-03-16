#include <stdio.h>
#include <math.h>

int main() {
	int T, inter, acc;
	 long double dist, tm[10], len[10], ac[10], speed, delta;
	scanf("%d",&T);

	for(int i=1;i<=T;++i) {
		printf("Case #%d:\n",i);

		scanf("%Lf %d %d",&dist,&inter,&acc);

		for(int j=0;j<inter;++j) {
			scanf("%Lf %Lf",&tm[j],&len[j]);
		}
		for(int j=0;j<acc;++j) {
			scanf("%Lf",&ac[j]);
		}

		for(int k=0;k<acc;++k) {
			
			if(inter==1)
			{
				printf("%.10Lf\n",sqrt(2*dist)/ac[k]);		
			}
			else
			{
			delta = len[0];
			speed = (len[1] - len[0])/(tm[1] - tm[0]);
		//	printf("speed %lf\n",speed);
	//		printf("sridhar %lf\n",sqrt(4*(speed*speed) - 8*delta*ac[k]));
			long double t1 = (sqrt(4*(speed*speed) + 8*delta*ac[k]) + 2*speed)/(2*ac[k]);

         //   printf("t1 %lf\n",t1);

			long double t2 = (2*speed - sqrt(4*(speed*speed) + 8*delta*ac[k]))/(2*ac[k]);
		//	printf("t2 %lf\n",t2);
            
			long double crosspoint = ac[k]*t1*t1*0.5;
          // printf("cross %Lf\n",crosspoint);
			if(crosspoint>dist) {
				printf("%.10Lf\n",sqrt(2*dist)/ac[k]);
			}
			else {
				printf("%.10Lf\n",t1+(dist-crosspoint)/speed);
			}
		}
		}
	}
	return 0;
}