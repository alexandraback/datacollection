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

int xabs(int x)
{
	return x < 0 ? -x : x;
}
set <char> v;
int main()
{	
	v.insert('a');
	v.insert('e');
	v.insert('i');
	v.insert('o');
	v.insert('u');
	freopen("input3.txt","r",stdin);freopen("output2.txt","w",stdout);
	int T;
	cin >> T;
	for (int test = 1; test <= T; test++)
	{
		LL ans = 0;
		string s;
		int n;
		cin >> s >> n;
		int m = s.size();
		vector <int> a(m, 0);
		
		if (!v.count(s[0]))
			a[0] = 1;
		for (int i = 1; i < m; i++)
		{
			if (!v.count(s[i]))
			{
				a[i] = a[i - 1] + 1;
			}
			else
				a[i] = 0;
		}
		vector <int> pos;
		for (int i = 0; i < m; i++)
		{
			if (a[i] >= n)
				pos.pb(i);
		}
		for (int i = 0; i < m; i++)
		{
			int v = i + n - 1;
			int p = lower_bound(pos.begin(), pos.end(), v) - pos.begin();
			if (p != pos.size())
				ans += m - pos[p];
		}
		cout << "Case #" << test << ": " << ans << endl;
	}
    return 0;
}
/*******************************************
*******************************************/
#endif