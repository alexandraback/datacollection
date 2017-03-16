#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
	int t;
	scanf("%d",&t);
	for(int tt=0;tt<t;){
		tt++;
		double c,f,x;
		scanf("%lf%lf%lf",&c,&f,&x);
		double mint=x/2.0;
		double income=2.0;
		double passt=0;
		while(true){
			double newFt=c/income;
			income+=f;
			double newt=passt+newFt+x/income;
			if(newt>mint)
				break;
			else{
				passt+=newFt;
				mint=newt;
			}
		}
		printf("Case #%d: %0.7lf\n",tt,mint);
	}
	return 0;
}