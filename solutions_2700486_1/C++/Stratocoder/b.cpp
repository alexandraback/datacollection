#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>

using namespace std;

int main() {
    int t;
    cin>>t;
    for (int tt = 1; tt <= t; ++tt) {
        int n, x, y;
        cin>>n>>x>>y;
        int ln = (abs(x) + y) / 2;
        int ct = 0;
        for (int i = 0; i <= ln; ++ i) {
            ct += (i << 2) + 1;
        }
        double ans = 0.0;
        if (ct <= n) {
            ans = 1.0;
        } else {
            int ctl = (ln << 2) + 1;
            ct -= ctl;
            if ((n > ct) && (y < (ln << 1))) {
                int free = n - ct;
                int half = (ctl - 1) >> 1;
                vector< vector< pair< double, double > > > v(half);
                for (int i = 0; i < half; ++i) {
                    v[i].resize(free);
                }
                v[0][0] = make_pair(0.5, 0.5);
                for (int i = 1; i < free; ++i) {
                    for (int j = 0; j < min(i + 1, half); ++j) {
                        if ((j + half) == i) {
                            v[j][i] = make_pair(1.0 - v[j][i - 1].second, 1.0);
                        } else {
                            if ((j + half) > i) {
                                double base = 1.0;
                                if (j) {
                                    base = v[j - 1][i - 1].second;
                                }
                                base = (base - v[j][i - 1].second) * 0.5;
                                v[j][i] = make_pair(base, v[j][i - 1].second + base);
                            } else {
                                v[j][i] = make_pair(0.0, 1.0);
                            }
                        }
                        //cout<<i<<", "<<j<<": "<<v[j][i].first<<" "<<v[j][i].second<<endl;
                    }
                }
                ans = v[y].back().second;
            } else {
            }
        }
        cout<<"Case #"<<tt<<": "<<fixed<<setprecision(8)<<ans<<endl;
    }
    return 0;
}

