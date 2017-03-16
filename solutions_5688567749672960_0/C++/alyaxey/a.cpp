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

int len(lint n) {
	int ans = 0;
	while (n) {
		n /= 10;
		++ans;
	}
	return ans;
}

lint po(lint a, int n) {
	lint ans = 1;
	REP(i, n)
		ans *= a;
	return ans;
}

lint rev(lint n, int l){
	lint ans = 0;
	REP(i, l) {
		ans = ans * 10 + n % 10;
		n /= 10;
	}
	return ans;
}

lint f(lint n){
	if (n % 10 == 0)
		return f(n - 1) + 1;
	if (n < 10)
		return n;
	lint base = po(10, (len(n) + 1) / 2);
	lint up = n / base;
	lint down = n % base;
	return f(po(10, len(n) - 1) - 1) + down + rev(up, len(n) / 2) + (up == po(10, len(n) / 2 - 1) ? 0 : 1);
}

void solve(int test)
{
	lint n;
	cin >> n;
	lint ans = f(n);
    cout << "Case #" << test << ":";
    cout << fixed;
    cout << setprecision(8);
    cout << " ";
    cout << ans;
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
