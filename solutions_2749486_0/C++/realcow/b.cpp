#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <functional>
using namespace std;

int d[201][201], trace[201][201];
struct SS {
    int x, y;
    int dist;
    SS(int x, int y, int dist) : x(x), y(y), dist(dist) {}
    bool operator<(const SS& r) {
        return dist < r.dist;
    }
};
void set(int x, int y, int v, int arr) {
    d[x + 100][y + 100] = v;
    trace[x + 100][y + 100] = arr;
    
}
int get(int x, int y, int& arr) {
    arr = trace[x + 100][y + 100];
    return d[x + 100][y + 100];
}
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char dirChar[5] = "WESN";

void init()
{
    int i, j, k, n, pn = 1;
    //priority_queue<S, vector<S>, greater<S>> q;
    //priority_queue<SS, vector<SS>, less<SS>> q;
    queue<SS> q;

    for (i = -100; i <= 100; i++)
        for (j = -100; j <= 100; j++)
            set(i, j, 1e9, 0);
    q.push(SS(0, 0, 0));
    set(0, 0, 0, 0);

    while (!q.empty()) {
        SS t = q.front(); q.pop();
        int v = t.dist;
        for (i = 0; i < 4; i++) {
            int tx = t.x + dx[i] * (v + 1);
            int ty = t.y + dy[i] * (v + 1);
            if (tx >= -100 && tx <= 100 && ty >= -100 && ty <= 100) {
                int arr;
                if (get(tx, ty, arr) > v + 1) {
                    q.push(SS(tx, ty, v + 1));
                    set(tx, ty, v + 1, i);
                }
            }
        }
    }
}

string getsol(int x, int y) {
    string s;
    while (x != 0 || y != 0) {
        int arr;
        int v = get(x, y, arr);
        x -= dx[arr] * v;
        y -= dy[arr] * v;
        s.push_back(dirChar[arr]);
    }
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    int i, j, k, n, pn = 1;
    int x, y;
    init();
    scanf("%*d");
    while (scanf("%d%d", &x, &y) == 2) {

        printf("Case #%d: %s\n", pn++, getsol(x, y).c_str());
    }
}