#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for (int i = a;i <= b;i ++)

using namespace std;

const int maxn = 1005;
int T,cas,n,ans,two,A[maxn],Q[maxn],f[maxn],D[maxn],ind[maxn];

int Work()
{
	ans = two = 0;		
	fo(i,1,n)
	{
		if (!ind[i]) continue;
		int p = 0, u = i;
		D[++p] = u;
		ind[u] --;
		for (int v = A[u];v != u;v = A[v])
		{
			D[++p] = v;
			ind[v] --;
		}
		if (p <= 2) two += 2 + f[D[1]] + f[D[2]];
		else ans = max(ans,p);			
	}
	return max(ans,two);
}

void FindLoop()
{
	fo(i,1,n) ind[A[i]]++;
	int L = 0, R = 0;
	fo(i,1,n) if (!ind[i]) Q[++R] = i;
	while (L < R)
	{
		int x = Q[++L];
		ind[A[x]] --;
		f[A[x]] = max(f[A[x]],f[x]+1);
		if (!ind[A[x]]) Q[++R] = A[x];
	}
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	for (scanf("%d",&T);T;T --)
	{
		memset(ind,0,sizeof ind);
		memset(f,0,sizeof f);
		printf("Case #%d: ",++cas);
		scanf("%d",&n);
		fo(i,1,n) scanf("%d",&A[i]);
		FindLoop();
		printf("%d\n",Work());
	}
	return 0;
}
