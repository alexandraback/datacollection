#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cassert>
#include <cstring>
#include <climits>

using namespace std;

#define FOR(k,a,b) for(int k=(a); k < (b); k++)
#define FORE(k,a,b) for(int k=(a); k <= (b); k++)
#define REP(k,a) for(int k=0; k < (a); k++)

#define ALL(c) (c).begin(), (c).end()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define RANGE(lb, x, ub) ((lb) <= (x) && (x) < (ub))

#define dump(x) cerr << #x << ": " << (x) << endl;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

const int INF = 1000 * 1000 * 1000;
const double EPS = 1e-10;


int main()
{
    int T; cin >> T;
    REP(tcase, T) {
        int C, D, V; cin >> C >> D >> V;
        VI ds(D); REP(i, D) cin >> ds[i];
        sort(ALL(ds));

        int res = 0;
        for(int v = 1; v <= V; v++) {
            int t = v;
            for(int i = ds.size()-1; i >= 0; i--) {
                REP(j, C) {
                    if(t >= ds[i]) t -= ds[i];
                }
            }

            if(t != 0) {
                ds.push_back(v);
                sort(ALL(ds));
                res++;
            }
        }

        printf("Case #%d: %d\n", tcase+1, res);
    }

    return 0;
}
