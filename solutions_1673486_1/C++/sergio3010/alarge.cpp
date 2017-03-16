#include <bits/stdc++.h>
using namespace std;


#define Fr(i,a,b) for(int i=a;i<b;++i)

long double dp[1000000], dp2[1000000];
int a,b,t;
double vet[1000000];
long double p2[1000000];


int main(){
	p2[0] = 1.0;
	Fr(i,1,1000000) p2[i] = p2[i-1]*2.0;
	scanf("%d",&t);
	Fr(cas,1,t+1){
		scanf("%d %d",&a,&b);
		Fr(i,0,a){
			scanf("%lf",&vet[i]);
		}
		dp[0] = 1-vet[0];
		Fr(i,1,a+1){
			dp[i] = dp[i-1] + (1-dp[i-1])*(1-vet[i]);
		}
		long double re = 1000000000.0;
		Fr(i,0,a+1){
			long double tmp = (2*(a-i)+b+(b-a)+2)*((i == 0)?0:dp[i-1]) + (2*(a-i)+(b-a)+1)*((i==0)?1:(1-dp[i-1]));
			re = min(re, tmp);
		}
		long double chancecerto = 1.0;
		Fr(i,0,a){
			chancecerto = chancecerto*vet[i];
		}
		re = min(re, (b-a+1)*chancecerto + (b-a+2+b)*(1-chancecerto));
		re = min(re, (long double)b+2);
		printf("Case #%d: %.6Lf\n",cas,re);
	}
	return 0;
}
