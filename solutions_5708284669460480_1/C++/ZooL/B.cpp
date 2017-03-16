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
typedef unsigned long long ULL;
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
 
// extended template
#pragma comment(linker, "/STACK:36777216")
typedef vector<int> vi;
typedef vector<vi> vvi;
 
#define forn(i, n) for (int i = 0; i < n; ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
 
template<typename T> istream & operator >> (istream &, vector<T> &);
template<typename T> ostream & operator << (ostream &, const vector<T> &);
 
#define START clock_t _clock = clock();
#define END cerr << endl << "time: " << (clock() - _clock) / LD(CLOCKS_PER_SEC) << endl;
 
#define NAME "basket"

vector <int> p_function(const string &s)
{
	int n = s.size();
	vector <int> p(n);
	for (int i = 1; i < n; i++)
	{
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j])
			j = p[j - 1];
		if (s[i] == s[j])
			j++;
		p[i] = j;
	}
	return p;
}

void solve()
{
	cout.setf(ios::fixed);
	cout.precision(9);

	int t;
	cin >> t;
	for (int q = 0; q < t; q++)
	{
		int K, L, S;
		cin >> K >> L >> S;
		string dict;
		cin >> dict;
		string target;
		cin >> target;

		vector <int> cnt(26);
		for (int i = 0; i < K; i++)
			cnt[dict[i] - 'A']++;

		bool fl = true;
		for (int i = 0; i < L; i++)
		{
			if (cnt[target[i] - 'A'] == 0)
			{
				fl = false;
				break;
			}
		}

		LD cntMax = 0;
		LD ans = 0;
		if (fl)
		{
			vector <int> pp = p_function(target);
			int l = pp.back();
			cntMax = 1;
			int j = L - 1;
			while (j + L - l < S)
			{
				j += L - l;
				cntMax++;
			}

			vector <LD> p(26);
			for (int i = 0; i < 26; i++)
				p[i] = LD(cnt[i]) / K;

			vector <vector <LD> > dp(S + 1, vector <LD> (L + 1, 0));
			dp[0][0] = 1;
			
			for (int i = 1; i <= S; i++)
			{
				LD S = 0;
				for (int len = 1; len <= L; len++)
				{
					dp[i][len] += dp[i - 1][len - 1] * p[target[len - 1] - 'A'];
					S += dp[i][len];
					ans += dp[i][L];
				}
				dp[i][0] = 1.0;
			}
		}

		cout << "Case #" << q + 1 << ": " << LD(cntMax) - ans << endl;
	}
}
int main()
{

    //START
    //freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    solve();
    //END
    return 0;
}
/*******************************************
*******************************************/
 
template<typename T> istream & operator >> (istream &is, vector<T> &v)
{
    forn(i, v.size())
        is >> v[i];
    return is;
}
template<typename T> ostream & operator << (ostream &os, const vector<T> &v)
{
    forn(i, v.size())
        os << v[i] << " ";
    return os;
}
#endif