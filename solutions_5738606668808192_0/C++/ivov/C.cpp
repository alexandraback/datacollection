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

const int MAX_D = 100;

void solve() {
    int n, J;
    cin >> n >> J;
    vector<pair<ll, VI> > result;
    for (ll mask = 1 + (1 << (n - 1)); mask < 1LL << n; mask += 2) {
        cerr << result.size() << endl;
        bool bad = false;
        VI divisors;
        for (int b = 2; b <= 10; b++) {
            int divisor = -1;
            for (int d = 2; d <= MAX_D; d++) {
                ll mod = 0, pw = 1;
                for (int i = 0; i < n; i++) {
                    if (mask & (1LL << i)) {
                        mod = (mod + pw) % d;
                    }
                    pw *= b;
                    pw %= d;
                }
                if (mod == 0) {
                    divisor = d;
                    break;
                }
            }
            if (divisor == -1) {
                bad = true;
                break;
            } else {
                divisors.push_back(divisor);
            }
        }
        if (!bad) {
            result.push_back(mp(mask, divisors));
            if (result.size() == J) {
                break;
            }
        }
    }
    for (int i = 0; i < L(result); i++) {
        ll mask = result[i].first;
        const VI & divisors = result[i].second;
        for (int j = n - 1; j >= 0; j--) 
            if (mask & (1 << j)) {
                cout << "1";
            } else {
                cout << "0";
            }
        for (int divisor : divisors) {
            cout << " " << divisor;
        }
        cout << endl;
    }
}

int main() {
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout); 
    int TC;
    scanf("%d", &TC);
    rep(tc, TC) {
		cout << "Case #" << tc << ":\n";
    	solve();
    	cout << endl;
    }
    return 0;
}