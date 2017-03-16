#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

#define  clr(arr, x)  memset(arr, (x), sizeof(arr))
#define  rep(i, n)  for(int i = 0; i < (n); i++)
#define  repu(i, l, r)  for(int i = (l); i <= (r); i++)
#define  repd(i, r, l)  for(int i = (r); i >= (l); i--)
#define  MP  make_pair
#define  PB  push_back
#define  reget(str)  freopen(str, "r", stdin)
#define  vi  vector<int>

typedef long long llg;

const double PI = acos(-1.0);
const double eps = 1e-6;
int cmp(double x) {
    if(x > eps)  return  1;
    else  if(x < -eps)  return  -1;
    else  return  0;
}
void run() {
    int T;
    llg r, t, ans;
    scanf("%d", &T);
    repu(Case, 1, T) {
        scanf("%lld%lld", &r, &t);
        ans = 1;
        llg ll = 1, rr = (llg)(t+eps), mid;
        double el, er;
        while(ll <= rr) {
            mid = (ll+rr)>>1;
            el = (t-mid)*0.5;
            er = mid*1.0*(r*1.0+mid-1);
            if(cmp(el-er) >= 0) {
                ans = mid;
                ll = mid+1;
            }
            else  rr = mid-1;
        }
        printf("Case #%d: %lld\n", Case, ans);
    }
}

int main() {
	reget("data.in");
	freopen("data.out", "w", stdout);
	run();
	return  0;
}
















