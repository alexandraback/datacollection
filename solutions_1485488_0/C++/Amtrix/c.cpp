#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <stack>
#include <assert.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define f first
#define s second
#define mk make_pair
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define pb push_back
#define blabla pair<double,pii >

int d[][2] = {-1,0, 1,0, 0,1, 0,-1};

const int maxn = 205;
const double eps = 1e-13;

int h,w,lvl;
int lo[maxn][maxn];
int hi[maxn][maxn];
bool visited[maxn][maxn];

bool canMove(int r1, int c1, int r2, int c2, double time) {
    double waterLevel = min((double)lvl, lvl - time * 10);
    bool b1 = waterLevel < hi[r2][c2]-50+1e-9;
    b1 = b1 && lo[r1][c1] < hi[r2][c2]-50+1e-9;
    b1 = b1 && lo[r2][c2] < hi[r2][c2]-50+1e-9;
    bool b2 = lo[r2][c2] < hi[r1][c1]-50+1e-9;
    return b1 && b2;
}

double dst[maxn][maxn];

bool reachable(double waiting) {
    for (int i = 0; i < h; ++i){
        for (int j = 0; j < w; ++j) {
            dst[i][j] = 1e9;
            visited[i][j] = false;
        }
    }

    dst[0][0] = waiting;
    priority_queue<blabla >pq;
    pq.push(mk(-waiting, mk(0,0)));

    while(!pq.empty()) {
        blabla u = pq.top(); pq.pop();
        int r = u.s.f;
        int c = u.s.s;
        double passedTime = -u.f;
        double waterLevel = min((double)lvl, lvl - passedTime * (double)10);
        double cost = 10;
       // printf("%.10lf\n",waterLevel-lo[r][c]);e exit - but after three moves (taking three seconds) the water is at 20cm, which is only 10cm above the floor,
        if(waterLevel-(double)lo[r][c] > 20-1e-9)
            cost = 1;
     //   printf("%.13lf\n",waterLevel-lo[r][c]);
       // cout<<r<<" "<<c<<" , "<<-u.f<<" | "<<dst[h-1][w-1]<<" | "<<waterLevel - lo[r][c]<<" "<<cost<<endl;
        visited[r][c] = true;

        for (int i = 0; i < 4; ++i) {
            int nr = r + d[i][0];
            int nc = c + d[i][1];
            if(nr<0||nc<0||nr>=h||nc>=w)continue;

            double t = dst[r][c] + cost;
            bool b = canMove(r, c, nr, nc, passedTime);
            if(b && dst[nr][nc] > t-1e-9 && !visited[nr][nc]) {
                dst[nr][nc] = t;
                pq.push(mk(-t, mk(nr,nc)));
            }
        }
    }
  //  cout<<dst[h-1][w-1]<<endl;
    return visited[h-1][w-1];
}

int main() {
    freopen("Ulaz","r",stdin);
   freopen("Izlaz2","w",stdout);
    int tests; scanf("%d",&tests);
  //  cout<<tests<<endl;
    for (int t = 1; t <= tests; ++t) {
        scanf("%d%d%d",&lvl,&h,&w);
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                scanf("%d",&hi[i][j]);

        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                scanf("%d",&lo[i][j]);


        double lo = -100000, hi = 100000;
        double sol = 1e9;
        while(hi-lo>eps) { // starting time
            double mid = (hi+lo)/2;
            bool b = reachable(mid);
            if(b) {
                hi = mid - eps;
                sol = dst[h-1][w-1];
            }else lo = mid + eps;
        }
      //  cout<<reachable(5)<<endl;
      //  cout<<dst[h-1][w-1]<<endl;
      //  cout<<lo<<" , "<<sol<<endl;
        printf("Case #%d: %.10lf\n",t,max(sol,0.0));
    }
    return 0;
}
