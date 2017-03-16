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

int is_div(const string & s, int b, int p)
{
	int x = 0;
	for (char c : s)
		x = (x * b + c - '0') % p;
	return !x;
}

VI primes{3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int get_div(const string & s, int b)
{
	for (int p : primes)
		if (is_div(s, b, p))
			return p;
	return 0;
}

bool get_divs(const string & s, VI & p)
{
	FOR(i, 2, 11)
	{
		int x = get_div(s, i);
		if (!x)
			return false;
		p[i - 2] = x;
	}
	return true;
}

void solve(int n, int k)
{
    unordered_map<string, VI> ans;
    while (sz(ans) < k)
    {
    	string x(n, '0');
    	REP(i, n)
    		x[i] = '0' + (rand() % 2);
    	x[0] = '1';
    	x[n - 1] = '1';
    	VI p(9);
    	if (get_divs(x, p))
    		ans[x] = p;
    }
    cout << "Case #1:\n";
    cout << fixed;
    cout << setprecision(8);
    for (const auto & kv : ans)
    {
    	cout << kv.X;
    	for (int p : kv.Y)
    		cout << ' ' << p;
		cout << "\n";
    }
}

void pre()
{
}

int main()
{
    if (!freopen("1.out", "w", stdout))
    {
        cerr << "Error creating output file" << endl;
        return 1;
    }
    ios::sync_with_stdio(false);
    pre();
//    solve(6, 3);
//    solve(16, 50);
    solve(32, 500);
    return 0;
}
