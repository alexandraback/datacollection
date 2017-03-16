#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define int64 long long
using namespace std;
int64 i,j,k,n,m,T;
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
	for (j=1;j<=T;j++) {
		printf("Case #%d: ",j);
		scanf("%I64d%I64d",&n,&m);
		int64 an=0;
		for (i=1;i*i<=m;i++)
		if (i*i>=n&&i*i<=m&&judge(i)&&judge(i*i)) {
			an++; //printf("%I64d %I64d %I64d\n",an,i,i*i);
		}
		printf("%I64d\n",an);
	}return 0;
}
