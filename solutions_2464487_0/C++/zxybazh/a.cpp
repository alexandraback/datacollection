#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
#define LD long double
#define VI vector<int>
#define PB push_back
#define MP make_pair
#define re(x) scanf("%d", &x)
#define re2(x,y) scanf("%d%d", &x, &y)
#define wt(x) printf("%d ", x)
#define wl(x) printf("%d\n", x)

int n, m, p;
LL rr, t, kk;
double r;

double calc(double k) {
    return (3*2*r*(k+1)+4*(k+1)*(k+1)*(k+1)-(k+1)-2*k*(k+1)*(2*k+1))/3;
}

bool cmp(double x, double y) {
    return (x < y) || (abs(x-y) < 1e-7);
}

LL work() {
    LL ans = 1, l = 1, r = 1000000000000000000, mid;
    while (l <= r) {
        mid = (l+r)/2;
        if (cmp(calc(mid-1),t)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid-1;
        }
    }
    return ans;
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("ou.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    int _ = 0;
    while (n--) {
        _++;
        cin >> rr>>t;
        r = rr;
        cout << "Case #" << _ << ": " << work() << endl;
    }
    return 0;
}

