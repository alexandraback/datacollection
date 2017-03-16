#include<stdio.h>
#include<string.h>
#include<math.h>

int fun(const void *pp,const void *qq){return *(int*)pp-*(int*)qq;}

int main(){
	long long t,z,a,b,m,count;
	char ch;
	scanf("%lld",&t);
	for(z=1;z<=t;z++){
		scanf("%lld%c%lld",&a,&ch,&b);
		
		m=b;
		while(m%2==0)
			m=m/2;//printf("m=%lld..",m);
		if(a%m==0){
			a=a/m;
			b=b/m;
			count=1;
			while((2*a)<b){
				a=a*2;
				count++;
			}
			printf("Case #%lld: %lld\n",z,count);
		}
		else
			printf("Case #%lld: impossible\n",z);
	}	
	return 0;
}
