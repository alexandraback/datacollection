#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int,int> PII;
const double eps = 1e-7;
const double PI = acos(-1.0);
const int oo = 1<<29;

const int N = 10111;

int E,R,n;
int v[N];
int use[N];

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.ou","w",stdout);
	
	int T; scanf("%d",&T);
	for(int ka=1;ka<=T;ka++) {
		printf("Case #%d: ",ka);
		scanf("%d%d%d",&E,&R,&n);
		for(int i=0;i<n;i++) {
			scanf("%d",&v[i]);
			use[i]=R;
		}
		use[0]=E;
		for(int i=n-1;i>0;i--) {
			int p=i-1;
			while(p>=0 && v[p]<v[i] && use[i]<E) {
				int d=min(E-use[i],use[p]);
				use[p]-=d;
				use[i]+=d;
				p--;
			}
		}
		ll ans=0;
		for(int i=0;i<n;i++) ans+=(ll)use[i]*v[i];
		cout<<ans<<endl;
	}

	return 0;
}
