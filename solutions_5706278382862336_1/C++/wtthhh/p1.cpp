#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define FOR(i,l,r) for(int i=l; i<=r; i++)
typedef long long LL;
int n;
LL a[50],p,q;
LL gcd(LL a, LL b){
	return b == 0? a : gcd(b, a%b);
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	a[0] = 1;
	FOR(i,1,41) a[i] = a[i-1]*2;
	scanf("%d",&n);
	FOR(i,1,n){
		scanf("%lld/%lld",&p,&q);
		LL d = gcd(p,q);
		p /= d;
		q /= d;
		bool f = false;
		FOR(j,0,40) if(q == a[j]) f = true;
		if(!f || p == 0){
			printf("Case #%d: impossible\n",i);
			continue;
		}
		FOR(j,0,40){
			if(p >= q){
				printf("Case #%d: %d\n",i,j);
				break;
			}
			p = p*2;
		}
	}
	return 0;
}
