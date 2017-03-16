#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long LL;

int ss, mid, n;
LL a[50000], b[50000], c[50000], d[50000], ll, rr, tl, e, r, now, can_take, s;
LL ans;



int main() {
    int test, tt;
    freopen("B-small-attempt1.in", "r", stdin);
   freopen("output.txt", "w", stdout);
    cin >> test;
    for (int tt = 1; tt <= test; tt++) {

        scanf("%I64d%I64d%d", &e, &r, &n);
       // if (tt == 100) cout << e << ' '<< r << ' ' << n << endl;
        //y = e / r;
        ans = 0;
        s = 0;
        for (int i = 1; i <= n; i++) {
            //a[i].x = i;
            scanf("%d", &a[i]);
            if (a[i] > s) s = a[i];
        }
//        sort(a + 1, a + 1 + n, cmp);
        ll = 1; rr = 0; //b[1] = a[1]; c[1] = 0;
       // now += r;
        for (int i = 1; i <= n; i++) {


            if (i != 1) {
                //cout << "!!" << i << ' ' << b[ll] << ' ' << ans << endl;
                if (c[ll] >= r) {
                    ans += (long long)(b[ll]) * r;
                    c[ll] -= r;
                  // cout << "@@@" << endl;
                } else {
                    int l = r - c[ll];
                    ans +=  c[ll] * b[ll];
                    ll++;
                    ans += l * (long long)(b[ll]); c[ll] = e -l;
                }
                //cout << "!!" << i << ' ' << ans << endl;
            }
            while (rr >= ll && a[i] > b[rr]) rr--;
            rr++;
            b[rr] = a[i]; //c[rr] = 0;
            if (a[i] == s) {
                mid = i;
                break;
            }

        }

       // cin >> tl;
        ans += (long long)(e) * s;
      //  cout << "!!!" << mid << " " << ans << endl;
        tl = 1; d[1] = s;
        for (int i = mid + 1; i <= n; i++) {
            while (a[i] > d[tl]) tl--;
            tl++; d[tl] = a[i];
        }
        ll = 1; rr = 0; d[tl + 1] = 0;
        ss = 2;
        //b[ll] = a[mid + 1]; c[ll] = r;
        now = 0; can_take = 0;
        for (int i = mid + 1; i <= n; i++) {
            now += r;
            if (now > e) {
                LL l = now - e;
                if (c[ll] >= l) {
                    ans += (long long)(b[ll]) * l;
                    c[ll] -= l;
                } else {
                    ans += (long long)(b[ll]) * c[ll];
                    l -= c[ll];
                    ll++;
                    ans += (long long)(b[ll]) * l;
                }
                now = e;
            }

            can_take += r; if (can_take > e) can_take = e;
            while (rr >= ll && a[i] > b[rr]) rr--;
            rr++; b[rr] = a[i]; c[rr] = can_take;

            if (a[i] == d[ss]) {
                ans += (long long)(now) * a[i];
                now = 0;
                ll = 0; rr = 0;
                can_take = 0;
                ss++;
            }
        }
        printf("Case #%d: %I64d\n",tt, ans);
    }
    return 0;
}
