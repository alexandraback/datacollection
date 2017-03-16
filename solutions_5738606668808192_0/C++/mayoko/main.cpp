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

ll calc(ll x) {
    for (ll i = 2; i*i <= x; i++) {
        if (x%i==0) {
            return i;
        }
        if (i > 100) return -1;
    }
    return -1;
}

bool ok(int s) {
    vector<ll> divs;
    for (int base = 2; base <= 10; base++) {
        ll num = 0;
        {
            int tmp = s;
            while (tmp) {
                num = num*base + (tmp%2);
                tmp /= 2;
            }
        }
        ll d = calc(num);
        if (d != -1) divs.push_back(d);
        else return false;
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
    for (int s = (1<<(N-1)); s < (1<<N); s++) {
        if (cnt==J) break;
        if (s%2==0) continue;
        if (__builtin_popcount(s)%2 == 1) continue;
        if (ok(s)) cnt++;
    }
    return 0;
}
