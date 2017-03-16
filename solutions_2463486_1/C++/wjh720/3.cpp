#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define For(i,x,y) for (i=x;i<=y;i++)
#define int64 long long
using namespace std;
int64 i,j,k,n,m,T,re[40];
inline bool judge(int64 x) {
	int64 g[100]={0},i;
	for (;x;g[++g[0]]=x%10,x/=10);
	for (i=1;i<=g[0]/2;i++) if (g[i]!=g[g[0]-i+1]) return 0;
	return 1;
}
int main() {
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	scanf("%I64d",&T);
	for (i=1;i*i<=(int64)1e14;i++)
	if (judge(i)&&judge(i*i)) {
		re[++re[0]]=i*i;
	}
	for (j=1;j<=T;j++) {
		printf("Case #%d: ",j);
		scanf("%I64d%I64d",&n,&m);
		int64 an=0,s1=0,s2=0;
		For(i,1,re[0]) if (re[i]<n) s1=i;
		For(i,1,re[0]) if (re[i]<=m) s2=i;
		printf("%I64d\n",s2-s1);
	}return 0;
}
