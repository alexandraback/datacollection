#include<bits/stdc++.h>
using namespace std;

#define scl(x) scanf("%lld",&x)
#define sc(x)  scanf("%d",&x)
#define ll long long
#define lop(i,n) for(int i=0;i<n;++i)
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

ll pw(ll b,ll p){
	ll ret=1,m=b;
	while(p){
		if(p&1)ret*=m;
		m*=m;
		p>>=1;
	}
	return ret;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("i.txt","r",stdin);
	freopen("o.txt","w",stdout);
#endif
	int t,k,c,s;
	sc(t);
	lop(C,t){
		sc(k),sc(c),sc(s);
		if(s<(k+c-1)/c){
			printf("Case #%d: IMPOSSIBLE\n",C+1);
			continue;
		}
		printf("Case #%d:",C+1);
		for(int l=1,r=c;l<=k;l+=c,r+=c){

			ll out=l;
			if(r>k){
				for(int i=l+1;i<=k;++i){
					out=(out-1)*k+i;
				}
				lop(i,r-k){
					out=(out-1)*k+k;
				}
			}
			else for(int i=l+1;i<=r;++i){
				out=(out-1)*k+i;
			}
			printf(" %lld",out);
		}
		puts("");
	}
}
