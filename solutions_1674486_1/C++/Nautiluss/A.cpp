#include<fstream>
#include<vector>
using namespace std;
#define NMAX 1010

int n,m;
vector<int>g[NMAX];
int sol;
bool viz[NMAX];

void parcurgere(int nod)
{
 int i;

 for (i=0; i<(int)g[nod].size(); ++i)
  if (sol == 0)
	{
	 if (viz[g[nod][i]] == 1)
		{
		 sol = 1;
		 break;
		}
	 else
		{
		 viz[g[nod][i]] = 1;
		 parcurgere(g[nod][i]);
		}
	}
}

void solve()
{
 int i;

 for (i=1; i<=n; ++i)
	{
	 parcurgere(i);
	 memset(viz,0,n+1);
	 if (sol == 1)
		 break;
	}

}

void read()
{
 int i,j,k,x,t;
 ifstream fin("A.in");
 ofstream fout("A.out");

 fin>>t;
 for (i=1; i<=t; ++i)
	{
	 fin>>n;
	 for (j=1; j<=n; ++j)
		{
		 fin>>m;
		 for (k=1; k<=m; ++k)
			{
			 fin>>x;
			 g[j].push_back(x);
			}
		}

	 solve();

	 if (sol == 1)
		 fout<<"Case #"<<i<<": Yes\n";
	 else
		 fout<<"Case #"<<i<<": No\n";

	 for (j=1; j<=n; ++j)
		 g[j].clear();
	 sol = 0;
	}

 fin.close();
 fout.close();
}

int main()
{
 read();
 return 0;
}
