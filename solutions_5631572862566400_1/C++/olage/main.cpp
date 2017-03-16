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

vector<int> bs;
vector<char> used;
vector<vector<int> > graph;

int dfs(int v)
{
//    cout << "dfs " << v << endl;
    used[v] = true;
    int result = 0;
    for (auto w : graph[v]) {
        if (used[w]) continue;
        result = max(result, dfs(w));
    }
    return result + 1;
}

int dfs2(int v, int level)
{
    int result = 0;

    if (used[v] == 1) {
        result = 0;
    } else if (!used[v]) {
        used[v] = level;
        result = dfs2(bs[v], level + 1);
    } else {
        result = level - used[v];
    }
    used[v] = 1;
//    cout << v << " " << level << " " << result << endl;
    return result;
}

int solve()
{
    int n; cin >> n;
    bs = vector<int>(n);
    used = vector<char>(n);
    graph = vector<vector<int>>(n);

    forr(i, n) {
        int b; cin >> b; --b;
        bs[i] = b;
        graph[b].push_back(i);
    }

    int paired = 0;

    for(int i = 0; i < n; ++i) {
        if (used[i]) continue;
        for(int j = i; j < n; ++j) {
            if (used[j]) continue;

            if (bs[i] == j && bs[j] == i) {
                used[i] = true;
                used[j] = true;

                paired += dfs(i) + dfs(j);
            }
        }
    }

    //cout << paired << endl;

    int result = paired;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            result = max(result, dfs2(i, 2));
        }
    }

    return result;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

    int t; cin >> t;
    for(int i = 1; i <= t; ++i) cout << "Case #" << i << ": " << solve() << endl;

	return 0;
}
