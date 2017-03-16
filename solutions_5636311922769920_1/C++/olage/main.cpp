#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <deque>
#include <ctime>
#include <cstring>

//#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sd second
#define pb push_back
#define mp make_pair

#define endl '\n'

#define forr(i, n) for(ll (i) = 0LL; (i) < (n); (i)++)
#define mp3(a, b, c) mp(a, mp(b, c))

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector < vector < double > > vvd;
typedef vector < double > vd;
typedef vector < pair < double, double> > vdd;
typedef vector < vector < long long > > vvl;
typedef vector < long long > vl;
typedef vector < pll > vll;

int INT_MAX_VAL = (int)  0x3F3F3F3F;
int INT_MIN_VAL = (int) -0x3F3F3F3F;
ll LONG_MAX_VAL = (ll)   0x3F3F3F3F3F3F3F3F;
ll LONG_MIN_VAL = (ll)  -0x3F3F3F3F3F3F3F3F;

#define MAXN 500006
#define MOD 1000000007

string fractal(string init, int k)
{
    string result = init;
    for (int i = 2; i <= k; ++i) {
        string current_l = result;
        string current_g = string(result.size(), 'G');
        string current_result;

        for (int j = 0; j < init.size(); ++j) {
            if (init[j] == 'G') {
                current_result += current_g;
            } else {
                current_result += current_l;
            }
        }
        result = current_result;
    }
    return result;
}


void solve(int test)
{
    cout << "Case #" << test << ": ";
    int k, c, s; cin >> k >> c >> s;

/*
    cout << endl;
    string f;
    for (int i = 0; i < k; ++i) {
        string init(k, '_');
        init[i] = 'G';

        f = fractal(init, c);
        cout << f << endl;
    }

    for (int i = 1; i  <= f.size(); ++i) {
        cout << i % 10;
    }
    cout << endl;
*/


    ll current_pos = 0;
    ll pw = 1;

    vector<ll> result;

    for (int i = 0; i < k; ++i) {
        current_pos += i * pw;
        pw *= k;
        if ((i + 1 == k) || ((i % c) == (c - 1))) {
            result.push_back(current_pos + 1);
            current_pos = 0;
            pw = 1;
        }
    }

    sort(result.begin(), result.end());

    if (result.size() > s) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (auto v : result) {
            cout << v << " ";
        }
        cout << endl;
    }
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) solve(t);

	return 0;
}
