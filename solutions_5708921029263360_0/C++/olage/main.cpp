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

void SolveRec(int i, vector<int>& opts, vector<int>& used, vector<int>& result, vector<int>& current)
{
//    cout << current.size() << endl;
    if (i == opts.size()) {
        //cout << result.size() << endl;
        if (result.size() < current.size()) {
            result = current;
        }
        return;
    }

    SolveRec(i + 1, opts, used, result, current);

    int cand = opts[i];
    int p1 = (cand / 10) * 10;
    int p3 = cand % 100;
    int p2 = (cand % 10) + (cand / 100) * 100;
//    cout << cand << " " << p1 << " " << p2 << " " << p3 << endl;
//    cout << used[p1] << " " << used[p2] << " " << used[p3] << endl;

    if (used[p1] == 0) return;
    if (used[p2] == 0) return;
    if (used[p3] == 0) return;

    current.push_back(cand);
    --used[p1];
    --used[p2];
    --used[p3];

    SolveRec(i + 1, opts, used, result, current);

    ++used[p3];
    ++used[p2];
    ++used[p1];
    current.pop_back();
}

int solve()
{
    int a, b, c, K; cin >> a >> b >> c >> K;

    vector<int> opts;
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            for (int k = 1; k <= c; ++k) {
                opts.push_back(i * 100 + j * 10 + k);
            }
        }
    }

    vector<int> used(1000, K);
 //   cout << K << endl;
//    cout << used[10] << used[100] << endl;
    vector<int> result;
    vector<int> current;
    SolveRec(0, opts, used, result, current);


    cout << result.size() << endl;
    for (auto &t : result) {
        cout << t / 100 << " " << (t / 10) % 10 << " " << t % 10 << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t; cin >> t;
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
