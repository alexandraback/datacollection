#include <stdio.h>
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test,testt;
	double c,f,x,print,curr,speed;
	scanf("%d",&testt);
	for(test=1;test<=testt;test++){
		scanf("%lf %lf %lf",&c,&f,&x);
		curr=0;
		speed=2;
		print=x/2;
		while(1){
			if(print>curr+c/speed+x/(speed+f))
				print=curr+c/speed+x/(speed+f);
			else break;
			curr+=c/speed;
			speed+=f;
		}
		printf("Case #%d: %.10lf\n",test,print);
	}
	return 0;
}
