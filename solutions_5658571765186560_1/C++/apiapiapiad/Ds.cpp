#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int _,__;
int t,n,m;
bool check(int t,int n,int m) {
	if (n*m%t!=0) return 0;
	if (t>=7) return 0;
	if (t<=2) return 1;
	if (t==3) return n>=2&&m>=2;
	if (t==4) return n>=3&&m>=3;
	if (n>m) swap(n,m);
	// n<=m
	if (t==5) {
		return (n>=4||(n==3&&m>=10));
	}
	if (t==6) {
		return n>=4;
	}
	return 0;
}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d%d",&t,&n,&m);
		printf("Case #%d: %s\n",++__,check(t,n,m)?"GABRIEL":"RICHARD");
	}
}
