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
		ll p=pw(k,c-1),p2=pw(k,c);
		printf("Case #%d:",C+1);
		for(ll i=1;i<=p2;i+=p){
			printf(" %lld",i);
		}
		puts("");
	}
}
