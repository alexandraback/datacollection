#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <set>
#include <limits.h>

#define inp(x) scanf("%d",&x)
#define inp_l(x) scanf("%lld",&x)
#define inp_d(x) scanf("%lf",&x)
#define MOD 1000000007

using namespace std;

typedef long long int ll;
typedef vector <int> VI;
typedef vector <long long int> VLL;
typedef pair<int,int> PI;
typedef pair<ll,ll> PLL;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, i, j, B;
	ll M;
	int adj[51][51];
	bool flag, flag1;
	cin >> t;
	for(int z = 1; z <= t; z++)
	{
		cin >> B >> M;
		cout << "Case #" << z << ": " ;
		for(i = 1; i <= B; i++)
		{
			for(j = 1; j <= B; j++)
			{
				adj[i][j] = 0;
			}
		}
		adj[1][B] = 1;
		VLL arr(B + 1, 0ll);
		ll ans = 1ll;
		if(M == 1)
		{
			cout << "POSSIBLE" << endl;
			for(i = 1; i <= B; i++)
			{
				for(j = 1; j <= B; j++)
				{
					cout << adj[i][j] ;
				}
				cout << endl;
			}
			continue;
		}
		arr[1] = 1ll;
		flag = false;
		flag1 = true;
		for(i = 1; i < B && flag1; i++)
		{
			for(j = i + 1; j < B; j++)
			{
				if(ans + arr[i] > M)
				{
					flag = false;
					flag1 = false;
					break;
				}
				ans += arr[i];
				adj[i][j] = 1;
				arr[j]+= arr[i];
				adj[j][B] = 1;
				if(ans == M)
				{
					flag = true;
					flag1 = false;
					break;
				}
			}
		}
		if(flag)
		{
			cout << "POSSIBLE" << endl;
			for(i = 1; i <= B; i++)
			{
				for(j = 1; j <= B; j++)
				{
					cout << adj[i][j];
				}
				cout << endl;
			}
		}
		else
			cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}

