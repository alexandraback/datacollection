#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF=-1999999999;
int T,m,r,n,v[11],f[11][6];

int main() {
	freopen("B-small-attempt0.in","r",stdin);
	freopen("1.txt","w",stdout);
	scanf("%d",&T);
	for (int T_T=1;T_T<=T;++T_T) {
		scanf("%d%d%d",&m,&r,&n);
		for (int i=1;i<=n;++i) scanf("%d",&v[i]);
		r=min(m,r);
		memset(f,128,sizeof(f));
		f[0][m]=0;
		for (int i=0;i<n;++i)
			for (int j=0;j<=m;++j) if (f[i][j]>INF)
				for (int k=0;k<=j;++k)
					f[i+1][min(m,j-k+r)]=max(f[i+1][min(m,j-k+r)],f[i][j]+v[i+1]*k);
		printf("Case #%d: %d\n",T_T,f[n][r]);
	}
	return 0;
}
