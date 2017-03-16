#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <assert.h>
using namespace std;

void smain();
int main(){
    ios_base::sync_with_stdio(0);
#ifdef TASK
    //freopen(TASK".in","rt",stdin);
    freopen("/Users/ramis/Downloads/C-small-1-attempt1.in.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    const clock_t start = clock();
#endif
    smain();
#ifdef TASK
    cerr << "\nTotal Execution Time: " << float( clock () - start ) /  CLOCKS_PER_SEC << endl;
#endif
    return 0;
}

#define forn(i,n) for (int i=0;i<n;i++)
#define rforn(i,n) for (int i=n-1;i>=0;i--)
#define fori(i,a) for(auto i=a.begin(); i!=a.end(); ++i)
#define rfori(i,a) for(auto i=a.rbegin(); i!=a.rend(); ++i)
#define int long long
#define LL long long
#define mp(a,b) make_pair(a,b)
#define INF 2000000000//2305843009213693951LL
#define MOD 1000000007
#define EPS 1E-10
#define N 555
/* --------- END TEMPLATE CODE --------- */

int n;

void smain() {
    int T;
    cin >> T;
    for(int cas = 1; cin >> n; ++cas){
        vector<pair<int, int> > a;
        forn(i, n){
            int d, h, m;
            cin >> d >> h >> m;
            forn(j, h) a.emplace_back(d, m + j);
        }
        sort(a.begin(), a.end());
        int res = 1;
        vector<double> v(2, 360.0);
        if(a.size() == 1 || a[0].second == a[1].second) {
            res = 0;
        }else{
            v[0] /= a[0].second, v[1] /= a[1].second;
            if(v[0] > v[1]) {
                swap(v[0], v[1]), swap(a[0], a[1]);
            }
            double t, s;
            if(a[0].first < a[1].first) {
                t = (a[0].first + 360 - a[1].first) / (v[1] - v[0]);
            }else{
                t = (a[0].first - a[1].first) / (v[1] - v[0]);
            }
            if(a[0].first <= a[1].first) {
                s = t * v[0] + a[0].first;
                if(s > 360 - EPS) res = 0;
            } else {
                s = t * v[0] + a[0].first;
                if(s > 360 - EPS) res = 0;
                else {
                    double t1 = 360 / (v[1] - v[0]);
                    s += v[0] * t1;
                    if(s > 360 - EPS) res = 0;
                }
            }
        }
        cout << "Case #" << cas << ": " << res << '\n';
    }
}

