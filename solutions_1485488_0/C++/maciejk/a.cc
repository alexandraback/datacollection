
#include<cassert>
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<cstring>
#include<stack>
#include<sstream>
#include<complex>
#define FORE(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define DEBU true
#define debug(x) { if (DEBU) cerr << #x << " = " << x << "\n"; }
#define debugv(x) { if (DEBU) { cerr << #x << " = "; FORE(it,(x)) cerr<< *it <<","; cerr<<"\n"; } }
#define fup(i,a,b) for(int i=(a);i<=(b);i++)
#define fdo(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x) memset((x),0,sizeof (x))
#define abso(a) ((a)<0?(-(a)):(a))
#define maxi(a,b) ((a)>(b)?(a):(b))
#define mini(a,b) ((a)<(b)?(a):(b))
#define MP make_pair
#define PB push_back
#define FI first
#define SE second
#define siz(a) ((int)a.size())
#define inf 1000000000
#define SQR(a) ((a)*(a))

using namespace std;
typedef long long lli;
typedef double ld;

#define maxn 105 

int flo[maxn][maxn];
int cei[maxn][maxn];
int cas, h, w;
int Hlev;

bool done[maxn][maxn];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isin(int x, int y) {
    return x >= 1 && y >= 1 && x <= h && y <= w;
}

void dfs(int x, int y) {
    done[x][y] = true;
    fup(i, 0, 3) {
        int xx, yy;
        xx = x + dx[i];
        yy = y + dy[i]; 
        if (!isin(xx, yy)) continue;
        if (done[xx][yy]) continue;

        if (Hlev <= cei[xx][yy] - 50 && flo[x][y] <= cei[xx][yy] - 50 && flo[xx][yy] <= cei[xx][yy] - 50 && flo[xx][yy] <= cei[x][y] - 50) dfs(xx, yy);
    }
}

struct stan{
    double czas;
    int x, y;
    stan(double a, int b, int c) {
        czas = a;
        x = b;
        y = c;
    }
};

bool operator<(const stan&l, const stan&r) {
    return l.czas > r.czas;
}


double best[maxn][maxn];

int main() {
    cin >> cas;
    fup(c, 1, cas) {
        cin >> Hlev >> h >> w;   
        fup(i, 1, h) fup(j, 1, w) cin >> cei[i][j];
        fup(i, 1, h) fup(j, 1, w) cin >> flo[i][j];
        CLR(done);
        dfs(1, 1);
        priority_queue<stan> Q;
        fup(i, 1, h) fup(j, 1, w) {
            if (done[i][j]) {
                best[i][j] = 0;
                Q.push(stan(0, i, j));
            } else best[i][j] = inf;
        }

        CLR(done);

        while (!Q.empty()) {
            double d = Q.top().czas;
            int x, y;
            x = Q.top().x;
            y = Q.top().y;
            Q.pop();
            if (done[x][y]) continue;
            if (d > best[x][y]) continue;
            done[x][y] = true;
            fup(i, 0, 3) {
                int xx, yy;
                xx = dx[i] + x;
                yy = dy[i] + y;
                if (!isin(xx, yy)) continue;
                if (done[xx][yy]) continue;
                if (!(flo[x][y] <= cei[xx][yy] - 50 && flo[xx][yy] <= cei[xx][yy] - 50 && flo[xx][yy] <= cei[x][y] - 50)) continue;
                double level = cei[xx][yy] - 50;
                double act_level = Hlev - d * 10;
                double czekam = 0;
                if (act_level > level) czekam = (act_level - level) / 10.0;

                double cost = 0;
                if (Hlev - (czekam + d)*10.0 >= 20 + flo[x][y]) {
                    cost = 1 + czekam;
                } else cost = 10 + czekam;

                if (d + cost < best[xx][yy]) {
                    best[xx][yy] = d + cost;
                    Q.push(stan(d + cost, xx, yy));
                }
            }
        }

        printf("Case #%d: %.8lf\n", c, best[h][w]);

    }

    return 0;
}

