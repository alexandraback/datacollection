#include<fstream>
#include<cstring>
using namespace std;
ifstream in("b.in");
ofstream out("b.out");
#define fo(i,j,k) for (i=j; i<=k; i++)
int g[110][110],  f[110][110], vis[110], fa[110];
int check(int n, int m)
{
	int i, j, k ;
	fo(k, 1 ,100)
	{
		fo(i, 1, n)
			fo(j, 1, m)
			f[i][j]=0;
		fo(i, 1, n)
		{
			int ok=1;
		    fo(j, 1, m)
			if (g[i][j]>k)
			{
				ok=0;
				break;
			}
			if (ok)
				 fo(j, 1, m)
				 f[i][j]=1;
		}
		fo(i, 1, m)
		{
			int ok=1;
		    fo(j, 1, n)
			if (g[j][i]>k)
			{
				ok=0;
				break;
			}
			if (ok)
				 fo(j, 1, n)
				 f[j][i]=1;
		}
		fo(i, 1, n)
			fo(j, 1, m)
			if (g[i][j]<=k)
				if (!f[i][j])
					return 0;
	}
	return 1;
}
int main()
{
	int t, i ,j, k;
	in>>t;
	fo(i, 1, t)
	{
		int n, m;
		in>>n>>m;
		fo(j, 1, n)
			fo(k, 1, m)
			in>>g[j][k];
		out<<"Case #"<<i<<": ";
		if (check(n ,m))
			out<<"YES"<<endl;
		else
			out<<"NO"<<endl;
	}
}