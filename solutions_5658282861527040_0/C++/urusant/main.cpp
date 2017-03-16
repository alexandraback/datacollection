#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <iterator>
#include <cstdio>
#include <list>

using namespace std;

#define rs resize
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back
#define ms(a) memset(a, 0, sizeof(a))
#define ass assign
#define inf (int)1e9
#define pi 3.1415926535

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
typedef vector <ll> vl;
typedef vector <vl> vvl;
typedef vector <vvl> vvvl;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <vii> vvii;
typedef set <int> si;
typedef queue <int> qi;
typedef vector <string> vs;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	for (int T = 0; T < t; ++T)
	{
		cout << "Case #" << T + 1 << ": ";
		int a, b, k;
		cin >> a >> b >> k;
		int ans = 0;
		for (int i = 0; i < a; ++i)
			for (int j = 0; j < b; ++j)
				if ((i & j) < k)
					ans++;
		cout << ans << endl;
	}
}