#include "../libs/DebugOutput.h"
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <cassert>
#include <map>
#include <memory>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#if ( _WIN32 || __WIN32__ )
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define pb push_back
#define INF 1000000000
#define L(s) (int)(s.size())
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define rep(i, n) FOR(i, 1, (n))
#define rept(i, n) FOR(i, 0, int(n) - 1)
#define C(a) memset((a), 0, sizeof(a))
#define ll long long
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define VI vector<int>
#define ppb pop_back
#define mp make_pair
#define pii pair<int, int>
#define pdd pair<double, double>
#define sqr(a) (a)*(a)
#define pi 3.1415926535897932384626433
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define rnd() ((rand() << 16) ^ rand())

void solve() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "INSOMNIA";
        return;
    }
    int mask = 0;
    ll cur = 0;
    while (mask != (1 << 10) - 1) {
        cur += n;
        ll x = cur;
        while (x > 0) {
            mask |= (1 << (x % 10));
            x /= 10;
        }
    }
    cout << cur;
}

int main() {
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout); 
    int TC;
    scanf("%d", &TC);
    rep(tc, TC) {
		cout << "Case #" << tc << ": ";
    	solve();
    	cout << endl;
    }
    return 0;
}