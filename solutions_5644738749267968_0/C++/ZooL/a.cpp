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
const LL inf = 1e+9;

#define mp make_pair
#define pb push_back
#define X first
#define Y second

#define dbg(x) { cerr << #x << " = " << x << endl; }


typedef vector<int> vi;
typedef vector<vi> vvi;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define START clock_t _clock = clock();
#define END cerr << endl << "time: " << (clock() - _clock) / LD(CLOCKS_PER_SEC) << endl;

#define NAME "problem"


int get(vector <int> &a, vector <int> &b)
{
	 int n = a.size();
	 int cnt = 0;
	 int j = 0;
	 for (int i = 0; i < n; i++)
	 {
		 while (j < n && a[i] > b[j])
			 j++;

		 if (j < n)
		 {
			 j++;
			 cnt++;
		 }
	 }
	 return n - cnt;
}

int get0(vector <int> a, vector <int> b)
{
	 int n = a.size();
	 return n - get(b, a);
}
int s2i(string s)
{
	string t = s.substr(s.find('.') + 1);
	while (t.size() < 5)
		t.pb('0');
	stringstream O(t);

	int res;
	O >> res;
	return res;
}
int main()
{
    //freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
    freopen("input.txt", "r", stdin);  freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int q = 0; q < T; q++)
	{
		int n;
		cin >> n;
		vector <int> a(n), b(n);
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			a[i] = s2i(s);
		}

		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			b[i] = s2i(s);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		cout << "Case #" << q + 1 << ": " << get0(a, b) << " " << get(a, b) << endl;
	}

    return 0;
}
/*******************************************
*******************************************/
