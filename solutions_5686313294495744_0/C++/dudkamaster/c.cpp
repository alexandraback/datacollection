#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <memory.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define forn(i,n) for (int i=0; i<int(n); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;


const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

int n, ans;
vector <string> f, s;

void read(){
}

void solve(){
    cin >> n;
    f.resize(n);
    s.resize(n);
    ans = 0;
    forn(i,n) {
        cin >> f[i] >> s[i];
    }
    forn(i,n) {
        bool fake = false;
        forn(t1, n) {
            forn(t2, n) {
                if (t1 != i && t2 != i && t1!=t2 && f[i] == f[t1] && s[i] == s[t2]) {
                    fake = true;
                }
            }
        }
        if (fake) ans++;
    }
    cout << ans << endl;
}

int main(){
#ifdef dudkamaster
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int t;
    scanf("%d", &t);
    forn(i,t) {
        printf("Case #%d: ", i+1);
        solve();
    }
    return 0;
}
