#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int _,__;
int n;
int ff(int x) {
	if (x==0) return 0;
	else return ff(x/10)|(1<<(x%10));
}
void gao() {
	scanf("%d",&n);
	if (n==0) {
		puts("INSOMNIA");
		return;
	}
	int S=0,x=0;
	while (S!=(1<<10)-1) {
		x+=n;
		S|=ff(x);
	}
	printf("%d\n",x);
}
int main() {
	for (scanf("%d",&_);_;_--) {
		printf("Case #%d: ",++__);
		gao();
	}
}
