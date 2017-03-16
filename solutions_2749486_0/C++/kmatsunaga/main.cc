#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <cstring>
#include <cctype>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <complex>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for(int i = a; i < (int)b; i++)
#define FOREQ(i,a,b) for(int i = a; i <= (int)b; i++)
#define FOREACH(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define ALL(c) (c).begin(), (c).end()
#define SZ(c) (c).size()
template <class T> void pp(T v) { FOREACH(it, v) cout << *it << ' '; cout << endl ; }
template <class T> void pp(T v, int n) { REP(i,n) cout<<v[i]<< ' '; cout << endl; }
template <class T> inline void chmax(T &a, const T b) { a = max(a, b); }
template <class T> inline void chmin(T &a, const T b) { a = min(a, b); }
typedef vector<int> vint;
typedef pair<int, int> pint;
typedef complex<double> P;
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef unsigned uint;
const int INF = 1<<28;
const double EPS = 1.0e-9;
static const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
#undef MOD_CALC
#ifdef MOD_CALC
const ll MOD = 1000 * 1000 * 1000 + 7 ; // 1000000007
inline void chadd(ll &a, const ll b) { a = (a + b) % MOD;}
inline ll add(const ll a, const ll b){ return (a + b) %  MOD;}
inline void chsub(ll &a, const ll b) { a = (a - b + MOD) % MOD;}
inline ll sub(const ll a, const ll b){ return (a - b + MOD) % MOD; }
inline void chmul(ll &a, const ll b) { a = (a * b) %  MOD;}
inline ll mul(const ll a, const ll b){ return (a * b) %  MOD;}
#endif

const int SIZE = 100;
int dist[SIZE*2+1][SIZE*2+1];
string ans[SIZE*2+1][SIZE*2+1];

struct State {
    int x, y, step;
    string rec;
};
void init(void)
{
    REP(x,SIZE*2+1)
            REP(y,SIZE*2+1)
                dist[x][y] = INF;
    deque<State> q;
    q.push_back((State) {0, 0, 0, ""});
    while(q.empty() == false) {
        State cs = q.front(); q.pop_front();
        const int dx[] = {0, 1, 0, -1};
        const int dy[] = {1, 0, -1, 0};
        string dir = "NESW";
        int nstep = cs.step+1;
        REP(d, 4) {
            int nx = cs.x + nstep * dx[d];
            int ny = cs.y + nstep * dy[d];
            if(abs(nx) <= SIZE && abs(ny) <= SIZE) {
                if(cs.step + 1 < dist[nx+SIZE][ny+SIZE]) {
                    string nrec = cs.rec + dir[d];
                    q.push_back((State){nx, ny, cs.step+1, nrec});
                    dist[nx+SIZE][ny+SIZE] = cs.step + 1;
                    ans[nx+SIZE][ny+SIZE] = nrec;
                }

            }
        }
    }
}

int main(void)
{
    init();
    int T; cin>>T;
    for(int case_no = 1; case_no <= T; case_no++) {
        int x, y; cin>>x>>y;
        cout << "Case #" << case_no << ": ";
        cout << ans[x+SIZE][y+SIZE] << endl;
    }
    return 0;
}
