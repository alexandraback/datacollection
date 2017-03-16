#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Attack {
    long long d;
    long long w;
    long long e;
    long long s;
    Attack(long long dd, long long ww, long long ee, long long ss) {
        d = dd;
        w = ww;
        e = ee;
        s = ss;
    }
    bool operator<(const Attack &c) const {
        return (d < c.d);
    }
};

    const int NUM = 10000;
    long long wall[NUM];
    long long wall_tmp[NUM];

int
main(void)
{
    long long T, N, ret;
    long long i, j, k;
    long long d[1010];
    long long n[1010];
    long long w[1010];
    long long e[1010];
    long long s[1010];
    long long delta_di[1010];
    long long delta_pi[1010];
    long long delta_si[1010];

    long long ww, ee, ss, dd;

    vector<Attack> vec;

    cin >> T;

    for(i=1;i<=T;i++) {
        cin >> N;

        for(j=0;j<N;j++) {
            cin >> d[j] >> n[j] >> w[j] >> e[j] >> s[j];
            cin >> delta_di[j] >> delta_pi[j] >> delta_si[j];
        }

        vec.clear();

        for(j=0;j<N;j++) {
            dd = d[j];
            ww = w[j];
            ee = e[j];
            ss = s[j];
            for(k=0;k<n[j];k++) {
                vec.push_back(Attack(dd,ww,ee,ss));
                dd += delta_di[j];
                ww += delta_pi[j];
                ee += delta_pi[j];
                ss += delta_si[j];
            }
        }

        for(j=0;j<vec.size();j++) {
            // cout << vec[j].d << "," << vec[j].w << "," << vec[j].e << "," << vec[j].s << endl;
        }

        sort(vec.begin(), vec.end());


        for(j=0;j<NUM;j++) {
            wall[j] = 0;
            wall_tmp[j] = 0;
        }

        ret = 0;
        for(j=0;j<vec.size();j++) {
            if ((j > 0) && (vec[j].d != vec[j-1].d)) {
                for(k=0;k<NUM;k++) {
                    wall[k] = max(wall[k],wall_tmp[k]);
                }
            }
            // cout << vec[j].d << "," << vec[j].w << "," << vec[j].e << "," << vec[j].s << endl;
            bool flg = false;
            for(k=vec[j].w;k<vec[j].e;k++) {
                if (vec[j].s > wall[k+NUM/2]) {
                    flg = true;
                    wall_tmp[k+NUM/2] = vec[j].s;
                }
            }
            if (flg) {
                ret++;
                // cout << "yes" << endl;
            }
        }
        
        cout << "Case #" << i << ": " << ret << endl;
    }
    
    return 0;
}
