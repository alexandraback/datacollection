#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
using namespace std;

const int maxn = 1000005;
const int inf  = 0x3f3f3f3f;
const double eps = 1e-8;
typedef long long ll;

int main() {
    int T;
    freopen("in.txt","r",stdin);
    freopen("codejam.txt", "w", stdout);
    cin >> T;
    int cas = 1;
    while(T --) {
        int n;
        cin >> n;
        int d[10], m[10];
        double v[10];
        int c = 0;
        for(int i=0;i<n;i++) {
            int D, H, M;
            cin >> D >> H >> M;
            for(int j=0;j<H;j++) {
                d[c] = D;
                m[c] = M + j;
                v[c] = 360.0 / m[c];
                c ++;
            }
        }
        int ans = 0;
        if(c < 2)ans = 0;
        else {
            if(d[0] < d[1]){
                swap(d[0], d[1]);
                swap(m[0], m[1]);
                swap(v[0], v[1]);
            }
            if(m[0] > m[1]){
                double t = (d[0]-d[1])/(v[1]-v[0]);
                double pos = d[0] + v[0]*t;
                if(pos > 360.0- eps) {
                    ans = 0;
                }
                else {
                    d[0] = d[1] = pos;
                    swap(v[0], v[1]);
                    t = (360.0-d[1])/v[1];
                    pos = d[0] + v[0] * t;
                    //printf("%.3f\n",pos);
                    if(pos >= 360.0-eps && pos <= 720.0-eps){
                        ans = 0;
                    }
                    else {
                        ans = 1;
                    }
                }
            }
            else if(m[0] == m[1]){
                ans = 0;
            }
            //case 2
            else {
                double t = (360.0-d[1])/v[1];
                double pos = d[0] + v[0] * t;
                if(pos >= 360.0-eps && pos <= 720.0 - eps){
                    ans = 0;
                }
                else {
                    ans = 1;
                }
            }
        }
        printf("Case #%d: %d\n",cas++, ans);
    }
}
