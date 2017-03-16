#include<stdio.h>
#include<algorithm>
#define MAXN 10000000
using namespace std;
int ispalin(long long x){
	long long tmp = x;
	long long tmp2 = 0;
	for( ; tmp != 0 ; ){
		tmp2 *= 10;
		tmp2 += tmp%10;
		tmp/=10;
	}
	//printf("%lld %lld\n",x,tmp2);
	return x == tmp2 ;
}
long long res[MAXN];
int num = 0;
int main(){
	int t;
	scanf("%d",&t);
	//ispalin(121);
	for(long long k = 1; k <= MAXN ; k++ ){
		if( ispalin(k) && ispalin(k*k) ){
			res[num++] = k*k;
			//printf("- %lld\n",k);
		}
	}
	for(int e=0; e < t ;e++ ){
		long long a,b;
		scanf("%lld %lld",&a,&b);
		long long *ptr = upper_bound(res,res+num,b);
		int ib = ptr-res;
		ptr = lower_bound(res,res+num,a);
		int ia = ptr-res;
		printf("Case #%d: %d\n",e+1,ib-ia);
	}
	//printf("%d\n",num);
}
