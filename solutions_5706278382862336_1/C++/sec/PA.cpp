#include <cstdio>
#include <cmath>
long long gcd(long long a, long long b)
{
	while((a%=b)&&(b%=a)){
		
	}
	return (a+b);
}
int main()
{
	freopen("A-large.in", "r", stdin);
	
	freopen("A-large.out", "w", stdout);
	
	//freopen("PA.txt", "r", stdin);
	long long x, y;
	int TN, ca=1;
	scanf("%d", &TN);
	while(TN--){
		scanf("%lld/%lld", &x, &y);
		long long g=gcd(x, y);
		x/=g;y/=g;
		printf("Case #%d: ", ca++);
		if((y&-y)!=y){
			puts("impossible");
		}
		else{
			int i;
			double a=(double)x/y;
			for(i=1;i<=40;i++){
				a*=2;
				//printf("%lf\n", a);
				if(a>=1){
					break;
				}
			}
			printf("%d\n", i);
		}
	}
	return 0;
}