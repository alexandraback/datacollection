#include<bits/stdc++.h>
using namespace std;

#define scl(x) scanf("%lld",&x)
#define sc(x)  scanf("%d",&x)
#define ll long long
#define lop(i,n) for(int i=0;i<n;++i)
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

bool seen[10];
int main(){
#ifndef ONLINE_JUDGE
	freopen("i.txt","r",stdin);
	freopen("o.txt","w",stdout);
#endif
	int t;
	sc(t);
	lop(C,t){
		ll n,m=1;
		scl(n);
		if(!n){
			printf("Case #%d: INSOMNIA\n",C+1);
			continue;
		}
		int cnt=0;
		memset(seen,0,sizeof seen);
		while(cnt<10){
			ll tmp=n*m;
			m++;
			while(tmp){
				if(!seen[tmp%10])++cnt;
				seen[tmp%10]=1;
				tmp/=10;
			}
		}
		printf("Case #%d: %lld\n",C+1,n*(m-1));

	}
}
