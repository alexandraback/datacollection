/*
* @problem: Fashion Police
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <limits.h>
#include <vector>
#include <map>
#include <bitset>
#include <string>
#include <iterator>
#include <set>
#include <utility>
#include <queue>
#include <numeric>
#include <functional>
#include <ctype.h>
#include <stack>
#include <algorithm>
#include <cstdlib>
#define MAX 100100
#define mod 1000000007LL
#define bitcnt(x) __builtin_popcountll(x)
#define MS0(x) memset(x, 0, sizeof(x))
#define MS1(x) memset(x, -1, sizeof(x))
#define ll long long int
#define mp(x, y) make_pair(x, y)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define in(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define ins(x) scanf("%s", x)
#define pr(x) printf("%lld\n", x)
#define prd(x) printf("%d\n", x)
#define prs(x) printf("%s\n", x)
#define pi acos(-1.0)
#define ff first
#define ss second

using namespace std;

int main()
{
// #ifndef ONLINE_JUDGE
// 	freopen("../input.txt", "r", stdin);
// 	freopen("../output.txt", "w", stdout);
// #endif
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	int t, J, P, S, K, c;
	int x[1005][3];
	int vis[11][11][11];
	cin >> t;
	for (int a = 1; a <= t; a++)
	{
		cin >> J >> P >> S >> K;
		cout << "Case #" << a << ": ";
		c = 0;
		MS0(vis);
		int index = 0;
		// for (int l = 1; l <= K; l++)
		// {
			for (int i = 1; i <= J; i++)
			{
				for (int j = i + 1; j <= P; j++)
				{
					for (int k = j + 1; k <= S; k++)
					{
						if (vis[i][j][k] == 0 && vis[i][j][0] < K && vis[i][0][k] < K && vis[0][j][k] < K)
						{
							x[index][0] = i;
							x[index][1] = j;
							x[index][2] = k;
							index++;
							vis[i][j][0]++;
							vis[i][0][k]++;
							vis[0][j][k]++;
							vis[i][j][k] = 1;
							//cnt++;
						}
					}
					for (int k = j; k > 0; k--)
					{
						if (vis[i][j][0] < K && vis[i][0][k] < K && vis[0][j][k] < K)
						{
							x[index][0] = i;
							x[index][1] = j;
							x[index][2] = k;
							index++;
							vis[i][j][0]++;
							vis[i][0][k]++;
							vis[0][j][k]++;
							//vis[i][j][k] = 1;
							//cnt++;
						}
					}
				}
				for (int j = i; j > 0; j--)
				{
					for (int k = j + 1; k <= S; k++)
					{
						if (vis[i][j][k] == 0 && vis[i][j][0] < K && vis[i][0][k] < K && vis[0][j][k] < K)
						{
							x[index][0] = i;
							x[index][1] = j;
							x[index][2] = k;
							index++;
							vis[i][j][0]++;
							vis[i][0][k]++;
							vis[0][j][k]++;
							vis[i][j][k] = 1;
							//cnt++;
						}
					}
					for (int k = j; k > 0; k--)
					{
						if (vis[i][j][0] < K && vis[i][0][k] < K && vis[0][j][k] < K)
						{
							x[index][0] = i;
							x[index][1] = j;
							x[index][2] = k;
							index++;
							vis[i][j][0]++;
							vis[i][0][k]++;
							vis[0][j][k]++;
							//vis[i][j][k] = 1;
							//cnt++;
						}
					}
				}
			}
			
		//}
		cout << index << endl;
		for (int i = 0; i < index; i++)
		{
			cout << x[i][0] << " " << x[i][1] << " " << x[i][2] << endl;
		}
	}
	return 0;
}