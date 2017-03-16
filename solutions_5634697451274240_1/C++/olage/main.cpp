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

string flip(string s, int right)
{
    reverse(s.begin(), s.begin() + right + 1);
    for (int i = 0; i <= right; ++i) {
        if (s[i] == '+') {
            s[i] = '-';
        } else {
            s[i] = '+';
        }
    }
    return s;
}

void solve(int test)
{
    string s; cin >> s;

    int result = 0;

    int right = s.size() - 1;
    while (right >= 0) {
        // cout << s << endl;
        while (right >= 0 && s[right] == '+') --right;

        if (right < 0) {
            break;
        }

        if (s[0] == '-') {
            s = flip(s, right);
        } else {
            int left = 0;
            while (s[left] == '+') {
                ++left;
            }
            s = flip(s, left - 1);
        }

        ++result;
    }

    cout << "Case #" << test << ": " << result << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) solve(t);

    return 0;
}
