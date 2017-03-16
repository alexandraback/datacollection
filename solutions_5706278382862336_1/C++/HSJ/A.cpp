#include<stdio.h>
#include<algorithm>
using namespace std;
__int64 a,b,c;

__int64 gcd(__int64 p, __int64 q){
	if(p<q) swap(p,q);
	while(p%q){
		p %= q;
		swap(p,q);
	}
	return q;
}
bool is_two(__int64 p){
	while(p%2==0) p/=2;
	if(p!=1) return false;
	return true;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t,t2,i;
	scanf("%d",&t2);
	for(t=1;t<=t2;t++){
		scanf("%I64d/%I64d",&a,&b);
		if(b==0){
			printf("Case #%d: impossible\n",t);
			continue;
		}
		c = gcd(a,b);
		a /= c, b /= c;
		if(a<=0 || a>b || !is_two(b)){
			printf("Case #%d: impossible\n",t);
			continue;
		}
		for(i=1;;i++){
			if(a*2>=b) break;
			b/=2;
		}
		printf("Case #%d: %d\n",t,i);
	}
	return 0;
}