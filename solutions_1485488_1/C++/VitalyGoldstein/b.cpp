#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int n, m, h;
vector< vector<int> > up, down, dst;

typedef pair<int, int> Point;
typedef set< pair<int, Point> > Queue;
Queue q;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool in(const Point& p)
{
    return p.first >= 0 && p.first < n && p.second >= 0 && p.second < m;
}

void update(Point p, int res)
{
    int& cdst = dst[p.first][p.second];
    if (cdst < res) {
        q.erase(make_pair(-cdst, p));
        cdst = res;
        q.insert(make_pair(-cdst, p));
    }
}

void go(Point s, int level, Point f)
{
    if (!in(f)) return ;
    int curFloor = down[s.first][s.second];
    int curCeil = up[s.first][s.second];
    int targetFloor = down[f.first][f.second];
    int targetCeil = up[f.first][f.second];

    if (curFloor + 50 > targetCeil ||
        targetFloor + 50 > targetCeil ||
        targetFloor + 50 > curCeil) {
        return ; //never can move
    }

    int needLevel = min(targetCeil - 50, level);
    int waiting = max(level - needLevel, 0);

    if (waiting == 0 && level == h) {
        //just go before
        update(f, h);
        return ;
    }

    int spentTime = curFloor <= needLevel - 20 ? 1 : 10;
    update(f, needLevel - spentTime * 10);
}

void solve()
{
    q.clear();
    q.insert(make_pair(-dst[0][0], Point(0, 0)));
    while (!q.empty()) {
        Queue::iterator it = q.begin();
        Point pos = it->second;
        int dst = -it->first;
        q.erase(it);

        for(int i = 0; i < 4; ++i) {
            go(pos, dst, Point(pos.first + dx[i], pos.second + dy[i]));
        }
    }
    cout << (h - dst[n - 1][m - 1]) * 0.1 << endl;

}

int main()
{
    int tst;
    cin >> tst;
    for(int iter = 0; iter < tst; ++iter) {
        cin >> h >> n >> m;
        up.clear();
        down.clear();
        up.resize(n, vector<int>(m));
        down.resize(n, vector<int>(m));
        dst.clear();
        dst.assign(n, vector<int>(m, -1e+9));
        dst[0][0] = h;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> up[i][j];
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> down[i][j];
            }
        }
        printf("Case #%d: ", iter + 1);
        solve();
    }
    return 0;
}
