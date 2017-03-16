#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
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
#define eps 1e-9
#define FOR(x, s, e) for(int x = (s); x < (e); ++x)
#define FORc(x, s, e, c) for(int x = (s); x < (e) && (c); ++x)
#define STEP(x, s, e, d) for(int x = (s); x < (e); x+=(d))
#define ROF(x, s, e) for(int x = (s); x >= (e); --x)
#define ROFc(x, s, e, c) for(int x = (s); x >= (e) && (c); --x)
#define vb vector<bool>
#define vi vector<int>
#define vii vector<pair<int, int> >
#define vs vector<string>
#define pb push_back
#define mp make_pair
#define ALL(X) X.begin(), X.end()
#define LL long long
#define pii pair<int, int>
#define x first
#define y second
#define gcd(x, y) __gcd((x), (y))
#define countbit(x) __builtin_popcount(x)

using namespace std;

double fmin(double x, double y){ return x-y>eps?y:x;}
bool fgt(double x, double y){ return x-y>eps;}

struct node{
    int x, y;
    bool tide;
    double t;
    node(){}
    node(int x, int y, double t, bool tide):x(x),y(y),t(t),tide(tide){}
    bool operator<(const node &S)const{
        return fgt(S.t, t);
    }
    bool operator>(const node &S)const{
        return fgt(t, S.t);
    }
};

int main(int argc, char **argv){
    int T;
    cin >> T;
    FOR(ca, 1, T+1){
        int H, N, M;
        cin >> H >> N >> M;
        int C[N][M], F[N][M];
        FOR(i, 0, N) FOR(j, 0, M) cin >> C[i][j];
        FOR(i, 0, N) FOR(j, 0, M) cin >> F[i][j];
        double d[N][M];
        FOR(i, 0, N) FOR(j, 0, M) d[i][j] = 1e30;
        d[0][0] = 0;
        priority_queue<node, vector<node>, greater<node> > Q;
        Q.push(node(0, 0, 0, 0));
        while (!Q.empty()){
            node U = Q.top();
            Q.pop();
            if (fgt(U.t, d[U.x][U.y])) continue;
            double ch = H - 10 * U.t, cc = C[U.x][U.y], cf = F[U.x][U.y];
            int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
            FOR(i, 0, 4){
                int nx = U.x + dx[i], ny = U.y + dy[i];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                double tc = C[nx][ny], tf = F[nx][ny];
                if (fgt(cf, tc-50)) continue;
                if (fgt(tf, tc-50)) continue;
                if (fgt(50, cc-tf)) continue; 
                double et = 0;
                double tide = U.tide;
                if (fgt(ch, tc-50)){ //Wait and see
                    et = (ch - tc + 50.) / 10.;
                    tide = 1;
                }
                double nh = ch - 10 * et, nt = U.t + et;
                if (fgt(20, nh-cf)){
                    nt += tide * 10;
                }else{
                    nt += tide * 1;
                }
                if (fgt(d[nx][ny], nt)){
                    d[nx][ny] = nt;
                    Q.push(node(nx, ny, nt, tide));
                }
            }
        }
        //FOR(i, 0, N){ FOR(j, 0, M) printf("%.3f ", d[i][j]); puts("");}
        printf("Case #%d: %.10f\n", ca, d[N-1][M-1]);
    }
	return 0;
}
