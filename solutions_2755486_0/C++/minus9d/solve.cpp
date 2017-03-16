#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define FOREACH(i, n) for (__typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair

struct data {
    ll d;
    ll w;
    ll e;
    ll s;

    bool operator<( const data& right ) const {
        return d < right.d;
    }
};

int main(void)
{
    int TEST_NUM;
    cin >> TEST_NUM;

    for(int test = 0; test < TEST_NUM; ++test){
        int N;
        cin >> N;

        // day, array
        map<ll, vector<data> > days;
        
        REP(tribe, N){
            ll d, n, w, e, s, dd, dp, ds;
            cin >> d >> n >> w >> e >> s >> dd >> dp >> ds;

            REP(n_idx, n){
                data cur_data;
                cur_data.d = d + n_idx * dd;
                cur_data.w = w + n_idx * dp;
                cur_data.e = e + n_idx * dp;
                cur_data.s = s + n_idx * ds;
                days[cur_data.d].push_back(cur_data);
            }
        }

        const int RANGE = 1000;
        const int OS = 500;
        vector<ll> wall(RANGE);


        ll ret = 0;
        FOREACH(dt, days){
            ll day = dt->first;
            vector<data> arr = dt->second;

            FOREACH(a, arr){
                bool isSuccess = false;
                for(int loc = a->w; loc < a->e; ++loc){
                    if (wall[OS + loc] < a->s){
                        isSuccess = true;
                        ++ret;
                        break;
                    }
                }
            }

            // update
            FOREACH(a, arr){
                for(int loc = a->w; loc < a->e; ++loc){
                    wall[OS + loc] = max(wall[OS + loc], a->s);
                }
            }
        }

        cout << "Case #" << (test+1) << ": " << ret << endl;
    }

    return 0;
}
