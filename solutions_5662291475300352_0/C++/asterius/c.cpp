#include <bits/stdc++.h>
using namespace std;
vector<pair<double, double> > q;
int main() {
    int t; cin >> t;
    for(int T = 1; T <= t; T++) {
        int n; cin >> n;
        q.clear();
        for(int i = 0; i < n; i++) {
            int d, h, m;
            cin >> d >> h >> m;
            for(int i = 0; i < h; i++) {
                int t = m + i;
                q.emplace_back(double(d)*t/360, t);
            }
        }
        sort(q.begin(), q.end());
        int rekord = 1000000000;
        for(auto p: q) {
//             printf("%f, %f\n", p.first, p.second);
            int ilu = 0;
            double a = p.first;
            for(auto r: q) {
                double c, d;
                tie(c, d) = r;
                if(c > a) {
                    ilu++;
                }
                while(c + d < a) {
                    if(ilu > rekord)
                        break;
                    c -= d;
                    ilu++;
                }
            }
//             printf("%d\n", ilu);
            rekord = min(rekord, ilu);
        }
        printf("Case #%d: %d\n", T, rekord);
    }
    return 0;
}