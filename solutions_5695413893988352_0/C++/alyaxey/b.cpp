#include <cstdlib>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define sz(X) ((int)(X).size())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define all(X) (X).begin(),(X).end()
#define FOR(i, a, n) for(int i=(a), __ ## i=(n); i<__ ## i; i++)
#define REP(I,N) FOR(I,0,N)
#define PR(X) cout<<#X<<" = "<<(X)<<" "
#define PRL cout<<endl
#define PRV(X) {cout<<#X<<" = {";REP(__prv,sz(X)-1)cout<<(X)[__prv]<<",";if(sz(X))cout<<*(X).end();cout<<"}"<<endl;}

template<class T> ostream &operator<<(ostream &os, vector<T> &vec)
{
    os << '{';
    REP(i, sz(vec))
    {
        os << vec[i];
        if (i + 1 != sz(vec) )
            os << ',';
    }
    os << '}';
    return os;
}

template<class T1, class T2> ostream &operator<<(ostream &os, pair<T1, T2> &par)
{
    os << '(' << par.X << ',' << par.Y << ')';
    return os;
}

typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;

int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : abs(x);
}

template<class T> T sqr(T x)
{
    return x * x;
}

lint str2int(const string & s)
{
	lint a = 0;
	for (char c : s)
		a = a * 10 + c - '0';
	return a;
}

template <typename T> int sgn(T val)
{
    return (T(0) < val) - (val < T(0));
}

pair<pair<lint, lint>, pair<lint, lint>> add_info(const pair<lint, lint> & a)
{
	return mp(mp(a.X == -1, abs(a.X - a.Y)), a);
}

pair<lint, lint> best(const pair<lint, lint> & a, const pair<lint, lint> & b)
{
	return min(add_info(a), add_info(b)).Y;
}

void solve(int test)
{
	string a, b;
	cin >> a >> b;
	pair<lint, lint> impossible(-1, -1);
	vector<pair<lint, lint>> d = {impossible, mp(0, 0), impossible};
	REP(i, sz(a))
	{
		vector<pair<lint, lint>> d1(3, impossible);
		for (int da = a[i] == '?' ? 0 : a[i] - '0'; da <= (a[i] == '?' ? 9 : a[i] - '0'); ++da)
			for (int db = b[i] == '?' ? 0 : b[i] - '0'; db <= (b[i] == '?' ? 9 : b[i] - '0'); ++db)
				REP(j, 3)
					if (d[j].X != -1)
						{
							auto x = mp(d[j].X * 10 + da, d[j].Y * 10 + db);
							auto & y = d1[sgn(x.X - x.Y) + 1];
							y = best(y, x);
						}
		d.swap(d1);
	}
	auto ans = best(d[0], best(d[1], d[2]));
	cout << "Case #" << test << ":";
    cout << fixed;
    cout << setprecision(8);
	cout << " " << setw(sz(a)) << setfill('0') << ans.X << ' ' << setw(sz(a)) << setfill('0') << ans.Y;
	cout << endl;
}

void pre()
{
}

int main()
{
    if (!freopen("1.in", "r", stdin))
    {
        cerr << "No input file" << endl;
        return 1;
    }
    if (!freopen("1.out", "w", stdout))
    {
        cerr << "Error creating output file" << endl;
        return 1;
    }
    ios::sync_with_stdio(false);
    pre();
    int n;
    cin >> n;
    string tmp;
    getline(cin, tmp);
    for (int i = 1; i <= n; ++i)
    {
        solve(i);
    }
    return 0;
}
