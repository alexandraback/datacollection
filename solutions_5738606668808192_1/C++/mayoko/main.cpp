#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<list>
#include<queue>
#include<deque>
#include<algorithm>
//#include<numeric>
#include<utility>
#include<complex>
//#include<memory>
#include<functional>
#include<cassert>
#include<set>
#include<stack>
#include<random>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

bool check(ll s, int d, int base) {
    ll rest = 0;
    while (s) {
        rest = (base*rest + (s%2)) % d;
        s /= 2;
    }
    return rest == 0;
}

bool ok(ll s) {
    vector<ll> divs;
    for (int base = 2; base <= 10; base++) {
        if (base%2 == 1) {
            divs.push_back(2);
            continue;
        }
        int d = 3;
        for (; d <= 100; d++) {
            if (check(s, d, base)) {
                divs.push_back(d);
                break;
            }
        }
        if (d > 100) return false;
    }
    string tmp;
    while (s) {
        tmp += (char)((s%2)+'0');
        s /= 2;
    }
    cout << tmp << " ";
    for (int i = 0; i < 9; i++) {
        cout << divs[i] ;
        if (i < 9-1) cout << " ";
    }
    cout << endl;
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T, N, J;
    cin >> T;
    cin >> N >> J;
    int cnt = 0;
    cout << "Case #1:" << endl;
    for (ll s = (1ll<<(N-1)); s < (1ll<<N); s++) {
        if (cnt==J) break;
        if (s%2==0) continue;
        if (__builtin_popcountll(s)%2 == 1) continue;
        if (ok(s)) cnt++;
    }
    return 0;
}
