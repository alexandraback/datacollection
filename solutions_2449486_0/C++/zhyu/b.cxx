#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 111;
int g[N][N];
int r[N],c[N];

int main(void) {
	int n,m,t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++) {
		memset(r,255,sizeof(r));
		memset(c,255,sizeof(c));
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				scanf("%d",&g[i][j]);
				r[i]=max(r[i],g[i][j]);
				c[j]=max(c[j],g[i][j]);
			}
		}
		bool flag=1;
		for(int i=0;i<n&&flag;i++) for(int j=0;j<m&&flag;j++)
			if(g[i][j]<r[i] && g[i][j]<c[j]) {
				flag=0;
			}
		printf("Case #%d: ",cas);
		puts(flag?"YES":"NO");
	}
	return 0;
}
