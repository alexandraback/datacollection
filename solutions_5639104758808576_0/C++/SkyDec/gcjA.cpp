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
const int N=2005;
char a[N];int n;
int main(){
	freopen("gcjA.in","r",stdin);
	freopen("gcjA.out","w",stdout);
	int t;
	scanf("%d",&t);
	rep(Cas,1,t){
		scanf("%d",&n);
		scanf("%s",a);
		int ans=0;
		int now=0;
		rep(i,0,n)if(a[i]!='0'){
			if(now<i){
				ans+=i-now;
				now=i;
			}
			now+=a[i]-'0';
		}
		printf("Case #%d: %d\n",Cas,ans);
	}
	return 0;
}




