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
	freopen("C-small-attempt3.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int t;
	cin >> t;
	for (int p = 0; p < t; ++p)
	{
		int r, c, m;
		cin >> r >> c >> m;
		int k = r * c - m;
		cout << "Case #" << p + 1 << ":" << endl;
		if (k == 1)
		{
			cout << "c";
			for (int i = 1; i < c; ++i)
				cout << "*";
			cout << endl;
			for (int i = 1; i < r; ++i)
			{
				for (int j = 0; j < c; ++j)
					cout << "*";
				cout << endl;
			}
			continue;
		}
		if (k == r * c)
		{
			cout << "c";
			for (int i = 1; i < c; ++i)
				cout << ".";
			cout << endl;
			for (int i = 1; i < r; ++i)
			{
				for (int j = 0; j < c; ++j)
					cout << ".";
				cout << endl;
			}
			continue;
		}
		if (r == 1)
		{
			cout << "c";
			for (int i = 0; i < k - 1; ++i)
				cout << ".";
			for (int i = k - 1; i < c - 1; ++i)
				cout << "*";
			cout << endl;
			continue;
		}
		if (c == 1)
		{
			cout << "c" << endl;
			for (int i = 0; i < k - 1; ++i)
				cout << "." << endl;
			for (int i = k - 1; i < r - 1; ++i)
				cout << "*" << endl;
			continue;
		}
		if (k == 2 || k == 3 || k == 5 || k == 7)
		{
			cout << "Impossible" << endl;
			continue;
		}
		if (c == 2)
		{
			if (k % 2 == 1)
			{
				cout << "Impossible" << endl;
				continue;
			}
			k /= 2;
			--k;
			cout << "c." << endl;
			for (int i = 0; i < k; ++i)
				cout << ".." << endl;
			for (int i = k; i < r - 1; ++i)
				cout << "**" << endl;
			continue;
		}
		if (r == 2)
		{
			if (k % 2 == 1)
			{
				cout << "Impossible" << endl;
				continue;
			}
			k /= 2;
			--k;
			cout << "c";
			for (int i = 0; i < k; ++i)
				cout << ".";
			for (int i = k; i < c - 1; ++i)
				cout << "*";
			cout << endl;
			for (int i = 0; i < k + 1; ++i)
				cout << ".";
			for (int i = k + 1; i < c; ++i)
				cout << "*";
			cout << endl;
			continue;
		}
		if (k / 2 <= c)
		{
			bool f = 0;
			if (k % 2 == 1)
			{
				f = 1;
				k -= 3;
			}
			k /= 2;
			k--;
			cout << "c";
			for (int i = 0; i < k; ++i)
				cout << ".";
			for (int i = k; i < c - 1; ++i)
				cout << "*";
			cout << endl;
			for (int i = 0; i < k + 1; ++i)
				cout << ".";
			for (int i = k + 1; i < c; ++i)
				cout << "*";
			cout << endl;
			if (f)
			{
				cout << "...";
				for (int i = 3; i < c; ++i)
					cout << "*";
				cout << endl;
			}
			else
			{
				for (int i = 0; i < c; ++i)
					cout << "*";
				cout << endl;
			}
			for (int i = 3; i < r; ++i)
			{
				for (int j = 0; j < c; ++j)
					cout << "*";
				cout << endl;
			}
			continue;
		}
		int s = k - c * (k / c);
		cout << "c";
		for (int i = 0; i < c - 1; ++i)
			cout << ".";
		cout << endl;
		for (int i = 0; i < k / c - 2; ++i)
		{
			for (int j = 0; j < c; ++j)
				cout << ".";
			cout << endl;
		}
		if (s == 1)
		{
			for (int i = 0; i < c - 1; ++i)
				cout << ".";
			cout << "*";
			cout << endl;
			cout << "..";
			for (int i = 2; i < c; ++i)
				cout << "*";
			cout << endl;
			for (int i = k / c + 1; i < r; ++i)
			{
				for (int j = 0; j < c; ++j)
					cout << "*";
				cout << endl;
			}
			continue;
		}
		for (int i = 0; i < c; ++i)
			cout << ".";
		cout << endl;
		for (int i = 0; i < s; ++i)
			cout << ".";
		for (int i = s; i < c; ++i)
			cout << "*";
		cout << endl;
		for (int i = k / c + 1; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
				cout << "*";
			cout << endl;
		}
	}				
	return 0;
}