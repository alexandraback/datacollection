#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
template<class T> T sqr(T x) {return x*x;}
#define pi acos(-1)
#define INF 100000000
#define debug(x) cerr<<#x"="<<(x)<<"\n";
#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

int v[1100000];
int f[1100000];

ll gao(ll n) {
	if (v[n]) return f[n];
	v[n]=1;
	if (n<10) {
		f[n]=n;
		return f[n];
	}
	ll x=n;
	int a[20];
	int cnt=0;
	while (x) {
		a[cnt++]=x%10;
		x/=10;
	}
	ll u=0;
	for (int i=0;i<cnt;i++) u=u*10+a[i];
	if (u>=n || a[0]==0) {
		f[n]=gao(n-1)+1;
	}
	else {
		f[n]=min(gao(n-1),gao(u))+1;
	}
	return f[n];
}

int main() {
	int tt;
	scanf("%d",&tt);
	for (int te=1;te<=tt;te++) {
		ll n;
		scanf("%lld",&n);
		printf("Case #%d: %lld\n",te,gao(n));
	}
}
