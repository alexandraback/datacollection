#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=1005;
int a[N];int n;
int main(){
	freopen("gcjB.in","r",stdin);
	freopen("gcjB.out","w",stdout);
	int T;scanf("%d",&T);
	rep(Cas,1,T){
		scanf("%d",&n);
		rep(i,1,n)scanf("%d",&a[i]);
		int ans=233333333;
		rep(i,1,1000){
			int res=0;
			rep(j,1,n)if(a[j])res+=((a[j]+i-1)/i)-1;
			
			res+=i;
			if(res<ans)ans=res;
		}
		printf("Case #%d: %d\n",Cas,ans);
	}
	return 0;
}



