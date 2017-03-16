#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
const int Maxn=1000;
struct Node {int a,b;} o[Maxn];
int n,ans;
bool u[Maxn],u1[Maxn];

bool operator<(Node x,Node y) {return x.b<y.b;}

bool check()
{
	int k=0,i,j;
	bool flag;
	memcpy(u1,u,sizeof u);
	for (i=0; i<n; ++i)
	{
		if (k>=o[i].b)
		{
			if (u[i] && !u1[i]) ++k; else k+=2,u1[i]=false;
			continue;
		}
		do{
			flag=false;
			for (j=0; j<n; ++j)
				if (u1[j] && k>=o[j].a) ++k, flag=true,u1[j]=false;
		}while (flag);
		if (k<o[i].b) return false;
		if (u[i] && !u1[i]) ++k; else k+=2,u1[i]=false;
	}
	return true;
}

void dfs(int p,int k)
{
	if (k>=ans) return;
	if (p==n)
	{
		if (check()) ans=k;
		return;
	}
	u[p]=false;
	dfs(p+1,k);
	u[p]=true;
	dfs(p+1,k+1);
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int T,t,i;
	scanf("%d",&T);
	for (t=1; t<=T; ++t)
	{
		scanf("%d",&n);
		for (i=0; i<n; ++i) scanf("%d%d",&o[i].a,&o[i].b);
		sort(o,o+n);
		ans=INT_MAX;
		dfs(0,n);
		printf("Case #%d: ",t);
		if (ans==INT_MAX) puts("Too Bad"); else printf("%d\n",ans);
	}
	return 0;
}
