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

int mult_abs(int p, int q) {
	if (p == 1 || q == 1)
		return p + q - 1;
	if (p == q)
		return -1;
	p -= 2;
	q -= 2;
	return (3 - p - q + 2) * ((p + 1) % 3 == q ? 1 : -1);
}

int mult(int p, int q) {
	return (p < 0 ? -1 : 1) * (q < 0 ? -1 : 1) * mult_abs(abs(p), abs(q));
}

int pow(int p, lint n) {
	int res = 1;
	REP(i, n % 4)
		res = mult(res, p);
	return res;
}

int c2i(char c){
	return c == 'i' ? 2 : c == 'j' ? 3 : 4;
}

void solve(int test)
{
	lint l, x;
	cin >> l >> x;
	string s;
	cin >> s;
	int res = 1;
	for (auto c : s)
		res = mult(res, c2i(c));
	bool ans = false;
	if (pow(res, x) == -1){
		lint p1 = -1;
		int res = 1;
		REP(i, l * min(x, 4LL)) {
			res = mult(res, c2i(s[i % l]));
			if (res == 2) {
				p1 = i;
				break;
			}
		}
		lint p2 = -1;
		res = 1;
		for (lint i = l * x - 1; i >= l * (x - min(x, 4LL)); --i) {
			res = mult(c2i(s[i % l]), res);
			if (res == 4) {
				p2 = i;
				break;
			}
		}
		ans = p1 != -1 && p2 != -1 && p1 < p2;
	}

    cout << "Case #" << test << ":";
    cout << fixed;
    cout << setprecision(8);
    cout << " ";
    cout << (ans ? "YES" : "NO");
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
