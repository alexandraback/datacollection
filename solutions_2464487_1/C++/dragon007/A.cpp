#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <list>
using namespace std;

#define PB push_back
#define MP make_pair
#define A first
#define B second
#define eps 1e-8

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int t;
LL r, m;

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A1.out", "w", stdout);
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ca ++ ) {
        scanf("%I64d%I64d", &r, &m);
        LL left = 0, right = min((LL)sqrt(m) + 1, m / (2 * r - 1) + 1);
        while (left < right) {
            LL mid = (left + right + 1) / 2;
            //cout<<2LL * mid * mid + (2 * r - 1) * mid<<endl;
            if (2LL * mid * mid + (2 * r - 1) * mid > m)
                right = mid - 1;
            else left = mid;
        }
        printf("Case #%d: %I64d\n", ca, left);
    }
    return 0;
}
