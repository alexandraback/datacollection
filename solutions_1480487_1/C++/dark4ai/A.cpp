#include<iostream>
#include<iomanip>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cassert>
#include<cstdio>
#include<cstring>
#include<ctime>

#define DEBUGLEVEL
#ifdef DEBUGLEVEL
#define printf_debug(fmt, args...) fprintf(stderr, fmt, ##args)
#else
#define printf_debug(fmt, args...)
#endif

typedef long long llong;

using namespace std;

double EPS = 1e-12;

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        vector<double> points(n);
        vector<double> ans(n);
        double sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> points[i];
            sum += points[i];
        }
        for(int i = 0; i < n; i++) {
            double l = 0.0, r = 1.0;
            int iters = 200;
            while(iters--) {
                double m = (l + r) / 2.0;
                double sumy = 0.0;
                for(int j = 0; j < n; j++) {
                    if(i != j) {
                        double add = (points[i] - points[j] + sum * m) / sum;
                        if(add < 0) {
                            add = 0;
                        }
                        sumy += add;
//                        cnt += ((points[i] + sum * m) < (points[j] + sum * kf));
                    }
                }
                if(sumy > (1.0 - m)) {
                    r = m;
                } else {
                    l = m;
                }
            }
            ans[i] = l;
        }
        cout << "Case #" << t << ":";
        for(int i = 0; i < n; i++) {
            cout << " " << setprecision(8) << fixed << ans[i] * 100.0;
        }
        cout << endl;
    }
        
    return 0;
}
