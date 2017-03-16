#if 1
#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <list>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;

const LD eps = 1e-9;
const LD pi = acos(-1.0);
const int inf = 1000 * 1000 * 1000;

#define mp make_pair
#define pb push_back
#define X first
#define Y second

#define dbg(x) { cerr << #x << " = " << x << endl; }

// extended template
#pragma comment(linker, "/STACK:36777216")
typedef vector<int> vi;
typedef vector<vi> vvi;


#define START clock_t _clock = clock();
#define END cerr << endl << "time: " << (clock() - _clock) / LD(CLOCKS_PER_SEC) << endl;

#define NAME "problem"


int main()
{
	freopen("input3.txt","r",stdin);freopen("output2.txt","w",stdout);
	int t;
	cin >> t;
	
	for (int test = 1; test <= t; test++)
	{	
		int ans = inf;
		int x, n;
		cin >> x >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		if (x == 1)
			ans = n;
		else
		{
			for (int i = 0; i <= n; i++)
			{	 
				LL s = x;
				int cnt = 0;
				for (int j = 0; j < i; j++)
				{
					if (s > a[j])
					{
						s += a[j];
						continue;
					}
					else
					{
						cnt++;
						s += (s - 1);
						j--;
					}
				}
				ans = min(ans, cnt + n - i);
			}
		}
		printf("Case #%d: %d\n",test,  ans);
	}
    return 0;
}
/*******************************************
*******************************************/
#endif