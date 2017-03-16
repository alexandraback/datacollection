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

void solve(int test)
{
	int n;
	cin >> n;
	vector<pair<int, int>> a;
	unordered_map<string, int> inds;
	int last_ind = 0;
	REP(i, n)
	{
		string x, y;
		cin >> x >> y;
		if (!inds[x])
			inds[x] = ++last_ind;
		if (!inds[y])
			inds[y] = ++last_ind;
		a.pb(mp(inds[x] - 1, inds[y] - 1));
	}
	int ans = 0;
	REP(mask, 1 << n)
	{
		int lett[2] = {};
		REP(j, n)
		{
			if ((mask >> j) & 1)
			{
				lett[0] |= 1 << a[j].X;
				lett[1] |= 1 << a[j].Y;
			}
		}
		int sz = 0;
		REP(j, n)
		{
			if (!((mask >> j) & 1) && (lett[0] & (1 << a[j].X)) && (lett[1] & (1 << a[j].Y)))
			{
				++sz;
			}
		}
		ans = max(ans, sz);
	}

	cout << "Case #" << test << ":";
    cout << fixed;
    cout << setprecision(8);
	cout << " " << ans;

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
