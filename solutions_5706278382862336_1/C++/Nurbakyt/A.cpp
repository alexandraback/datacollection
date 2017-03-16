#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <ctime>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#define pb push_back
#define pp pop_back
#define f first
#define s second
#define mp make_pair
#define sz(a) int((a).size())
#define _USE_MATH_DEFINES
#define ll long long 
#define ull unsigned long long  
#define fname ""
const int N = (int)1e6 + 123;
const double eps = 1e-6;
const ll inf = (ll)1e18 + 123;

using namespace std;

int t, ans;
ll p, q;
double now, cur;
char a;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> t;
	for (int tests = 1;tests <= t;tests ++)
	{
		cin >> p >> a >> q;
		now = (double)((1.0 * p) / (1.0 * q));
		ans = -1;
		for (int i = 1;i <= 40;i ++)
		{
			cur = (double)((1ll << i) * now);								
			if (cur >= 1.0)
			{
				ans = i;
				break;
			}
		}
		for (int i = 1;i <= 40;i ++)
		{
			if (q % 2 == 0)
				q /= 2;
			else
				break;
		}
		if (p % q != 0)
			ans = -1;
		cout << "Case #" << tests << ": ";
		if (ans == -1)
			cout << "impossible\n";
		else
			cout << ans << endl;
	}
	return 0;
}
