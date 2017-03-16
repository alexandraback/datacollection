/*
 *		Problem		:
 *		Author		: Yicheng Huang from Dept.Computer Science & Technology, PKU
 *		Date		: 2013-04-27
 *		Algorithm	:
 *
 */

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <ctime>
#include <queue>

#define PB push_back
#define MP make_pair
#define two(X) (1<<X)
#define ME(a) memset(a, 0, sizeof(a))
#define MCP(a, b) memcpy(a, b, sizeof(b))
#define eps 1e-8
#define sqr(x) ((x) * (x))

typedef unsigned long long LL;

using namespace std;

LL N, R;

bool ok(LL p){
    double tmp = log(p + 0.0);
    double a = R; double b = p;
    a = a * 2 + b * 2 - 1;
    tmp += log(a);
    if (log(N) < tmp - 1) return false;
    LL k = 2*R*p + p *(2*p - 1);
    if (N >= k) return 1;
    else return 0;
}


int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int testcase;
    cin >> testcase;
    for (int  t = 1; t <= testcase; t++){
        printf("Case #%d: ", t);
        cin >> R >> N;
        LL l = 1, r = N / 2 /R;
        while (l + 1 < r){
            LL mid = (l + r) / 2;
            if (ok(mid)) l = mid;
            else r = mid - 1;
        }
        while (ok(l+1)) l++;
        cout << l << endl;
    }
}
