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
    srand((int)time(NULL));
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        cout << "Case #" << i + 1 << ": ";
        ll k, c, s;
        cin >> k >> c >> s;
        if (k != s){
            cout << "IMPOSSIBLE\n";
            continue;
        } else {
            ll buf = 1;
            for (int i = 0; i < c - 1; i++){
                buf *= k;
            }
            for (int i = 0; i < k; i++){
                cout << buf * i + 1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
