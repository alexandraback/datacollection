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

vl solve_brute(vvl vs, int n)
{
    int m = 2 * n - 1;
    for (int skip_row = 0; skip_row < n; ++skip_row) {
        for (int i = 0; i < (1 << m); ++i) {
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                if (i & (1 << j)) ++cnt;
            }
            if (cnt != n) {
                continue;
            }

            vvl arr;
            int cur_row = 0;
            for (int j = 0; j <= m; ++j) {
                if (cur_row == skip_row) {
                    arr.push_back(vl(n, 0));
                    ++cur_row;
                }
                if (j < m && (i & (1 << j)) == 0) {
                    arr.push_back(vs[j]);
                    ++cur_row;
                }
            }

/*
            cout << arr.size() << endl;
            forr(i, n) {
                forr(j, n) {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
*/
            bool is_good = true;
            int cur_col = 0;
            for (int j = 0; j < m; ++j) {
                if (i & (1 << j)) {
                    for (int k = 0; k < n; ++k) {
                        if(arr[k][cur_col] == 0) {
                            arr[k][cur_col] = vs[j][k];
                        } else if(arr[k][cur_col] != vs[j][k]) {
                            is_good = false;
                        }
                    }
                    ++cur_col;
                }
            }

//            cout << is_good << endl;

            if (is_good) {
                return arr[skip_row];
            }
        }
    }
}

void gen(int n)
{
    srand(time(0));
    cout << "1" << endl << n << endl;
    vvl arr(n, vl(n));

    arr[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        arr[i][0] = arr[i - 1][0] + 1 + (rand() % 5);
        arr[0][i] = arr[0][i - 1] + 1 + (rand() % 5);
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]) + 1 + (rand() % 5);
        }
    }

    vvl vs;
    for (int i = 0; i < n; ++i) {
        vs.push_back(arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        vl v(n);
        for (int j = 0; j < n; ++j) {
            v[j] = arr[j][i];
        }
        vs.push_back(v);
    }

    int skip = rand() % (2 * n);

    for (int i = 0; i < 2 * n; ++i) {
        if (i == skip) continue;

        for (int j = 0; j < n; ++j) {
            cout << vs[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;
    for (int j = 0; j < n; ++j) {
        cout << vs[skip][j] << " ";
    }
    cout << endl;
}

void solve(int test)
{
    int n; cin >> n;
    vvl vs(2 * n - 1);
    forr(i, 2 * n - 1) {
        vs[i].resize(n);
        forr(j, n) cin >> vs[i][j];
    }
    sort(vs.begin(), vs.end());
    /*
       vvl rows;
       vvl cols;

       vl first_row = vs[0];

       rows.push_back(first_row);

       int missing = -1;
       int p = 0;
       for (int i = 1; i < vs.size(); ++i) {
       if (p < n && vs[i][0] > first_row[p]) {
       missing = p;
       ++p;
       } else if (p < n && vs[i][0] == first_row[p]) {
       rows.push_back(vs[i]);
       ++p;
       } else {
       cols.push_back(vs[i]);
       }

       }
       */

    vl result = solve_brute(vs, n);

    cout << "Case #" << test << ":";
    for (auto r : result) {
        cout << " " << r;
    }
    cout << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

//    gen(10);   return 0;
    int t; cin >> t;
    for(int i = 1; i <= t; ++i) solve(i);

    return 0;
}
