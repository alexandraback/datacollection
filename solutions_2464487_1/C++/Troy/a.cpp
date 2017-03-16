#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define ll long long
#define ull unsigned long long
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

ull r, t;
bool check(ull k) {
    ull sum = r * 2LL * k;
    if (sum > t) return false;
    ull b = 1 + (k - 1) * 4LL;
    ull tmp = (1 + b) * k / 2;
    sum += tmp;
    return sum <= t;
}
int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T, ca = 0;
    cin >>T;
    while (T--) {
        cin >>r >>t;
        ull lo = 1, hi = (ull)(sqrt(1.0*t/2)+5), mid;
        //cout <<hi <<endl;
        ull ans = 1;
        while (lo <= hi) {
            mid = (lo + hi) >>1;
            if (check(mid)) ans = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        cout <<"Case #" <<++ca <<": " <<ans <<endl;
    
    }
    return 0;
}

