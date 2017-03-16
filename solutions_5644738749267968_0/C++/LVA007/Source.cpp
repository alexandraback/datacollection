#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <set>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <complex>
#include <hash_map>
#include <hash_set>

using namespace std;

#define pb push_back
#define pob pop_back
#define rs resize
#define as assign
#define lwb lower_bound
#define upb upper_bound
#define mp make_pair
#define x first
#define y second

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <ll> vl;
typedef vector <vl> vvl;
typedef vector <bool> vb;
typedef vector <vb> vvb;
typedef vector <string> vs;
typedef vector <char> vc;
typedef vector <vc> vvc;
typedef vector <vvi> vvvi;
typedef vector <vvl> vvvl;
typedef vector <vvb> vvvb;
typedef double db;
typedef long double ldb;
typedef vector <db> vdb;
typedef vector <ldb> vldb;
typedef pair <int, int> ii;
typedef pair <ll, ll> lll;
typedef pair <int, ll> il;
typedef pair <ll, int> li;
typedef vector <ii> vii;
typedef vector <vii> vvii;
typedef vector <lll> vll;
typedef vector <vll> vvll;
typedef set <int> si;
typedef set <ii> sii;
typedef vector <si> vsi;
typedef map <string, int> msi;
typedef map <char, int> mci;
typedef queue <int> qi;
typedef deque <int> di;
typedef stack <int> sti;

int main()
{
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	int t;
	cin >> t;
	for (int k = 0; k < t; ++k)
	{
		int n;
		cin >> n;
		vdb a(n), b(n);
		set <double> q1, q2, q3;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			q3.insert(a[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> b[i];
			q1.insert(b[i]);
			q2.insert(b[i]);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int ans1 = n;
		int s = 0;
		for (; ;)
		{
			bool f = 0;
			for (int j = s; j < n; ++j)
				if (a[j] < b[j - s])
				{
					f = 1;
					break;
				}
			if (f)
			{
				ans1--;
				s++;
			}
			else
				break;
		} 
		int ans2 = 0;
		for (int j = n - 1; j >= 0; --j)
		{
			if (q1.upb(a[j]) == q1.end())
			{
				q1.erase(*q1.begin());
				ans2++;
				continue;
			}
			q1.erase(*q1.upb(a[j]));
		}
		cout << "Case #" << k + 1 << ": " << ans1 << " " << ans2 << endl;
	}
	return 0;
}