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

ll convertToBase(int mask, ll base)
{
    ll pw = 1;
    ll result = 0;

    while (mask) {
        if (mask & 1) {
            result += pw;
        }
        pw *= base;
        mask = mask >> 1;
    }
    return result;
}

bool checkNumber(int mask)
{
    for (int i = 2; i <= 10; ++i) {
        ll in_base = convertToBase(mask, i);
        if (in_base % (i + 1)) {
            return false;
        }
    }
    return true;
}

void print_binary(int n, int len)
{
    string bin(len, '0');
    for (int i = 0; i < len; ++i) {
        if (n & (1 << i)) {
            bin[len - i - 1] = '1';
        }
    }
    cout << bin;
}

void solve(int test)
{
    cout << "Case #" << test << ":" << endl;

    int n, J; cin >> n >> J;

    vector<int> left, right;

    int n2 = n / 2;

    for (int mask = 0; mask < (1 << n2); ++mask) {
        bool lowest_bit = (mask & 1) != 0;
        bool highet_bit = (mask & (1 << (n2 - 1))) != 0;

        if (!lowest_bit && !highet_bit) {
            continue;
        }

        if (checkNumber(mask)) {
            if (lowest_bit) {
                right.push_back(mask);
            }

            if (highet_bit) {
                left.push_back(mask);
            }
        }
    }

    int result_cnt = 0;

    for (int i = 0; i < left.size(); ++i) {
        for (int j = 0; j < right.size(); ++j) {
            if (result_cnt == J) break;

            print_binary(left[i], n2);
            print_binary(right[j],n2);
            for (int b = 2; b <= 10; ++b) {
                cout << " " << b + 1;
            }
            cout << endl;
            ++result_cnt;
        }
    }
//    cout << result_cnt << endl;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

    int T; cin >> T;
    for (int t = 1; t <= T; ++t) solve(t);

	return 0;
}
