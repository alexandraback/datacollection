#include<bits/stdc++.h>
#define int64 long long
#define sqr(x) (x)*(x)
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define VI vector<int>
#define VI64 vector<int64>
#define VS vector<string>
#define PII pair<int,int>
#define PDD pair<double,double>
#define VPII vector< PII >
#define SZ(x) ((int)(x).size())
using namespace std;
const double pi=acos(-1);
int T,a[1200],ans,tim,n;
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		rep(i,1,n)scanf("%d",&a[i]);
		ans=1<<30;
		rep(x,1,1000){
			int u=0;
			rep(i,1,n)u+=(a[i]+x-1)/x-1;
			ans=min(ans,x+u);
		}
		printf("Case #%d: %d\n",++tim,ans);
	}
}
