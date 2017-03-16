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

int t, a, b, c, ans;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> t;
	for (int test = 1;test <= t;test ++)
	{
		cin >> a >> b >> c;
		ans = 0;
		for (int i = 0;i < a;i ++)
			for (int j = 0;j < b;j ++)
				if ((i & j) < c)
					ans ++;
		cout << "Case #" << test << ": " << ans << endl;
	}
	return 0;
}
