#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<set>
#include<vector>
#include<string.h>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

vector < vector < int > > to;
vector< char > tome;

char used[1024];

bool dfs(int numb)
{
	used[numb] = 1;
	for (int i=0; i<to[numb].size(); i++)
	{
		int next = to[numb][i];
		if (used[next] == 1)
			return true;
		else
		{
			bool res = dfs(next);
			if (res)
				return true;
		}
	}
	return false;
}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif


	int T;

	cin >> T;

	for (int cs = 1; cs <= T; cs ++)
	{

		printf("Case #%d: ",cs);

		int n; cin >> n;

		to.clear();
		to.resize(n);
		tome.clear();
		tome.resize(n);

		for (int i=0; i<n; i++)
		{
			int m;
			cin >> m;
			to[i].resize(m);
			for (int j=0; j<m; j++)
			{
				cin >> to[i][j];
				to[i][j]--;
				tome[to[i][j]] = 1;
			}
		}

		bool ok = false;

		for (int i=0; i<n; i++)
		{
			if (tome[i] == 0)
			{
				memset(used,0,sizeof(used));
				if ( dfs(i) )
				{
					ok = true;
					break;
				}
			}
		}

		if (ok)
			printf("Yes");
		else
			printf("No");
		printf("\n");
	}

	return 0;
}