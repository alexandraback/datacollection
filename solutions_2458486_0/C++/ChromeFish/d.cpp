#include<fstream>
#include<cstring>
using namespace std;
ifstream in("d.in");
ofstream out("d.out");
#define fo(i,j,k) for (i=j; i<=k; i++)
int f[1<<20], key[210], g[21][41] ,col[21], ans[21], n;
int dfs(int now, int m, int fa)
{
	int i, j;
	if (f[now]) return 0;
	f[now]=fa;
	if (m>n)
		return 1;
	fo(i, 1, n)
		if (!(now & (1<<(i-1))) && key[col[i]])
	{
		key[col[i]]--;
		fo(j, 1, g[i][0])
			key[g[i][j]]++;
		if (dfs(now+(1<<(i-1)), m+1, i))
			return 1;
		key[col[i]]++;
		fo(j, 1, g[i][0])
			key[g[i][j]]--;
	}
	return 0;
}
int main()
{
	int t, k, i, j, p;
	in>>t;
	fo(i, 1, t)
	{
		in>>k>>n;
		fo(j, 1, 200)
			key[j]=0;
		fo(j, 1, k)
		{
			int x;
			in>>x;
			key[x]++;
		}
		fo(j, 1, n)
		{
			in>>col[j];
			in>>g[j][0];
			fo(p, 1, g[j][0])
				in>>g[j][p];
		}
		memset(f,0,sizeof(f));
		out<<"Case #"<<i<<": ";
		if (dfs(0, 1, -1))
		{
			int now=(1<<n)-1;
			j=0;
			while (f[now]>0)
			{
				ans[j++]=f[now];
				now-=1<<(f[now]-1);
			}
			do {
			  j--;
			  out<<ans[j]<<' ';
			}
			while (j>1);
			if (j>0) out<<ans[0]<<endl;
			else out<<endl;
		}
		else out<<"IMPOSSIBLE"<<endl;
	}
}