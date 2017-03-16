#include <iostream>
#include <cstdio>
using namespace std;
double d[2];
int m[2], h[2];

int main() {
    freopen("C-small-1-attempt3.in","r",stdin);
    freopen("C-small.out","w",stdout);

    int T; cin >> T;
    for (int o = 1; o <= T; o++) {
        int n;
        cin >> n;
        int p = 0;
        for (int i = 0; i < n; i++) {
            cin >> d[i] >> h[i] >> m[i];
            p += h[i];
        }
        if (n == 1 || p == 1) {
            printf("Case #%d: 0\n", o);
            continue;
        }
        if (m[0] == m[1]) {
            printf("Case #%d: 0\n", o);
            continue;
        }
        if (m[1] < m[0]) {
            swap(d[0],d[1]);
            swap(m[0],m[1]);
        }

     //   d[1] -= 360;
   //     double v1 = 360./m[1];
    //   double v0 = 360./m[0];
      //  double t = (d[0]-d[1])/(v1-v0);
      //  double dis = t * v1;
        d[0] -= 360;
        double dd = (d[1] * m[1] - d[0] * m[0]) / (m[1]-m[0]);
        if (dd <= 360) {
             printf("Case #%d: 1\n", o);
        } else {
            printf("Case #%d: 0\n", o);
        }
    }
}
