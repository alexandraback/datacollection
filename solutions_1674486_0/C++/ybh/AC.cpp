#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

#define PB push_back

#define MAXN 1010

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;

int map[MAXN][15],q[MAXN];
bool b[MAXN];

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	int TT;
	cin>>TT;
	for (int T=1;T<=TT;T++)
	{
		cout<<"Case #"<<T<<": ";
		int n;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>map[i][0];
			for (int j=1;j<=map[i][0];j++)
				cin>>map[i][j];
		}
		bool bb=true;
		for (int i=1;i<=n && bb;i++)
		{
			for (int j=1;j<=n;j++)
				b[j]=false;
			b[i]=true;
			int h=0,t=1;
			q[1]=i;
			while (h<t && bb)
			{
				h++;
				int x=q[h];
				for (int j=1;j<=map[x][0] && bb;j++)
				{
					int y=map[x][j];
					if (b[y]) bb=false;
					else 
					{
						b[y]=true;
						t++;
						q[t]=y;
					}
				}
			}
		}
		if (bb) cout<<"No"<<'\n'; else cout<<"Yes"<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
