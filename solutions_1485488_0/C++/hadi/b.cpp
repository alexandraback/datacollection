#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
using namespace std;
const int N = 100;

struct State {
    int x, y;
    double w;
    State(int _x = 0, int _y = 0, double _w = 0) {
        x = _x; y = _y; w = _w;
    }
    bool operator<(const State& s) const {
        return w > s.w;
    }
};

const double eps = 1e-8;

typedef priority_queue<State> PQ;
typedef queue<State> Q;

int t, h, n, m;
int F[N][N], C[N][N];
bool visited[N][N];
PQ pq;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool check(double fl, double cl) {
    return fl + 50 < cl + eps;
}

bool can_go(int x, int y, int d, double t) {
    int nx = x + dx[d], ny = y + dy[d];
    if(nx < 0 || ny < 0 || nx >= n || ny >= m) return false;
    double water = h - t * 10;
    bool result = check(F[x][y], C[nx][ny]) && 
                  check(F[nx][ny], C[nx][ny]) && 
                  check(water, C[nx][ny]) && 
                  check(F[nx][ny], C[x][y]);
    return result;
}

void queue_init() {
    memset(visited, 0, sizeof visited);
    pq = PQ();
    Q q;
    q.push(State(0, 0));
    while(!q.empty()) {
        State s = q.front(); q.pop();
        if(visited[s.x][s.y]) continue;
        visited[s.x][s.y] = true;
        pq.push(s);
        //cerr << "Push " << s.x << "," << s.y << endl;
        for(int i = 0; i < 4; i ++) {
            if(can_go(s.x, s.y, i, 0)) {
                q.push(State(s.x + dx[i], s.y + dy[i]));
            }
        }
    }
}

bool get_time(int x, int y, int d, double& out) {
    double left = 0, right = 1000000;
    bool ok = false;
    for(int i = 0; i < 100; i ++) {
        double mid = (left + right) * 0.5;
        if(can_go(x, y, d, mid)) {
            right = mid;
            ok = true;
        } else {
            left = mid;
        }
    }
    out = left;
    return ok;
}

double solve() {
    memset(visited, 0, sizeof visited);
    while(!pq.empty()) {
        State s = pq.top(); pq.pop();
        if(visited[s.x][s.y]) continue;
        visited[s.x][s.y] = true;
        if(s.x == n - 1 && s.y == m - 1) return s.w;
        for(int i = 0; i < 4; i ++) {
            double t;
            if(get_time(s.x, s.y, i, t)) {
                double rt = max(s.w, t);
                //cout << "From " << s.x << "," << s.y << " to " << i << ": " << rt << endl;
                double water = h - 10 * rt;
                //cout << "Water is " << water << endl;
                if(water - 20 < F[s.x][s.y] + eps) {
                    rt += 10;
                } else  {
                    rt += 1;
                }
                pq.push(State(s.x + dx[i], s.y + dy[i], rt));
            }
        }
    }
    return 0;
}

int main() {
    cin >> t;
    for(int I = 1; I <= t; I ++) {
        cin >> h >> n >> m;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                cin >> C[i][j];
            }
        }
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                cin >> F[i][j];
            }
        }
        cout.precision(7);
        cout.setf(ios::fixed | ios::showpoint);
        queue_init();
        cout << "Case #" << I << ": " << solve() << endl;
    }
    return 0;
}
