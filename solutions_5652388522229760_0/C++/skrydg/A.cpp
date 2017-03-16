#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <list>
#include <iterator>
#include <functional>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <ctime>
#include <cassert>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef pair<short, short> pss;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pset set <int>*
#define vi vector <int>
#define vll vector <ll>
#define sz(a) ((int)(a.size()))
//#define clear(a) memset((a), 0, sizeof (a))


int get(int *buf, ll n){
    int ans = 0;
    while (n > 0){
        ll cur = n % 10;
        if (buf[cur] == 0){
            buf[cur] = 1;
            ans++;
        }
        n /= 10;
    }
    return ans;
}

ll solve(ll n){
    if (n == 0){ return -1; }
    int buf[10];
    memset(buf, 0, sizeof buf);
    int cnt = 0;
    for (int i = 1; i <= 1000 * 1000; i++){
        cnt += get(buf, i * n);
        if (cnt == 10){
            return i * n;
        }
    }
    return -1;
}

int main() {
#ifdef HOME
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        cout << "Case #" << i + 1 << ": ";
        int n;
        cin >> n;
        ll ans = solve(n);
        if (ans == -1){
            cout << "INSOMNIA\n";
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}
