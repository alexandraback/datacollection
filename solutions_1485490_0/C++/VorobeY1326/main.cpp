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
		int m; cin >> m;

		vector < long long > up ( n );
		vector < int > upType ( n );
		vector < long long > down ( m );
		vector < int > downType ( m );

		for (int i=0; i<n; i++)
		{
			cin >> up[i];
			cin >> upType[i];
		}
		for (int i=0; i<m; i++)
		{
			cin >> down[i];
			cin >> downType[i];
		}

		long long maximum = 0;

		for (int first = 0; first < m; first ++)
		{
			for (int second = first-1; second < m; second ++)
			{
				for (int third = second-1; third < m; third ++)
				{
					if (second < 0 || third < 0)
						continue;
					long long cnt = 0;
					if (n >= 1)
					{
						long long _left = up[0];
						for (int i=first; i<second; i++)
							if (downType[i] == upType[0])
							{
								long long sub = min(_left,down[i]);
								_left -= sub;
								cnt += sub;
							}
					}
					if (n >= 2)
					{
						long long _left = up[1];
						for (int i=second; i<third; i++)
							if (downType[i] == upType[1])
							{
								long long sub = min(_left,down[i]);
								_left -= sub;
								cnt += sub;
							}
					}
					if (n >= 3)
					{
						long long _left = up[2];
						for (int i=third; i<m; i++)
							if (downType[i] == upType[2])
							{
								long long sub = min(_left,down[i]);
								_left -= sub;
								cnt += sub;
							}
					}
					if (cnt > maximum)
						maximum = cnt;
				}
			}
		}

		printf("%lld\n",maximum);

	}

	return 0;
}