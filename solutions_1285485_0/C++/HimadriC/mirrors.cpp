#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <queue>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>

using namespace std;

#define SZ(X) ((int)X.size())
#define REP(i,n) for(int i=0; i<(int)n; i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define IT(it) __typeof((it)->begin())
#define FORIT(v) for(IT(v) it=(v)->begin(); it!=(v)->end(); it++)
#define all(x) (x).begin(),x.end()
#define pb(x) push_back(x)
#define VI vector<int> 
#define VVI vector<vector<int> >
#define VS vector<string>
#define PI pair<int,int>
#define PPI pair<PI, pair<double,Slope > > 
#define SQR(x) (x)*(x)
#define PB push_back

int gcd(int a, int b) {
    if (a<0) a=-a;
    if (b<0) b=-b;
    if (b==0) return a;
    return gcd(b, a%b);
}

int H,W,D;

int main()
{
    int T;
    cin >> T; getchar();
    REP(zz,T) {
    cin >> H >> W >> D; getchar();
    D*=1;
    W*=1;
    H*=1;
    PI start;
//    VVI memo(W,VI(memo,H));
    REP(i,H) {
        string buf;
        getline(cin,buf);
        REP(j,W) {
            if (buf[j]=='X') {
                start.first  = double(j);
                start.second = double(i);
            } else if (buf[j]=='X') {
 //               memo[j][i] = 1;
            } else {
  //              memo[j][i] = 0;
            }
        }
    }
    vector<PI> points;
    int N = 50;
    for (int n=-N; n<=N; n++) {
        for (int m=-N; m<=N; m++) {
            int px = (2*W-2-1)+(2*W-4)*n;
            int py = (2*H-2-1)+(2*H-4)*m;
            int x,y;
            if (n&0x1) {
                x = px+2*start.first-1;
            } else {
                x = px+(2*W-2-1-2*start.first);
            }
            if (m&0x1) {
                y = py+2*start.second-1;
            } else {
                y = py+(2*H-2-1-2*start.second);
            }
            points.PB(make_pair(x/2,y/2));
        }
    }
    set<pair<int, int> > memo;
    int ret=0;
    REP(i,SZ(points)) {
        PI pt0 = points[i];
        PI pt1 = start;
        if (pt1 == pt0) continue;
        int dx = pt1.first-pt0.first;
        int dy = pt1.second-pt0.second;
        if (D>=sqrt(SQR(dx)+SQR(dy))) {
            int g=gcd(dx,dy);
            dx /= g; 
            dy /= g;
            if (memo.count(make_pair(dx,dy))==1) continue;
            memo.insert(make_pair(dx,dy));
            ret++;
        }
    }

    printf("Case #%d: %d\n", zz+1,ret);
    }

    return 0;
}
