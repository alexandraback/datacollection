#include <cstdio>
#define EPS 0.0000000001
int t,i=0;
double c,f,x,ans,sum;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lf %lf %lf",&c,&f,&x);
		sum=0.0;
		ans=x/2.0;
		for(int y=0;;y++){
			sum+=c/(2.0+f*double(y));
			if(sum+x/(2.0+f*(double(y+1)))-ans>EPS){
				printf("Case #%d: %.7lf\n",++i,ans);
				break;
			}
			ans=sum+x/(2.0+f*(double(y+1)));
		}
	}
	return 0;
}
