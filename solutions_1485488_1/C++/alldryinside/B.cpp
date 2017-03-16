#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <list>
#include <set>
#include <ctime>
#include <list>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define vi vector<int>
#define vd vector<double>
#define pii pair<int,int>
#define pdd pair<double,double>
#define ll long long
using namespace std;

const int MAXN = 102, MAXT = 500;
const int INF = (1<<22);
int H, N, M;
pii A[MAXN][MAXN];

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool used[MAXN][MAXN];

double dist[MAXN][MAXN];

bool can_pass(pii fr, pii to, double level)
{
    if(to.y - to.x < 50) return false;
    if(fr.y - to.x < 50) return false;
    if(to.y - fr.x < 50) return false;
    if(to.y - level < 50) return false;
    return true;
}

double pass_time(pii fr, pii to, double level)
{
    if(to.y - to.x < 50) return -1.0;
    if(fr.y - to.x < 50) return -1.0;
    if(to.y - fr.x < 50) return -1.0;
    if(level <= 0) return 10.0;
    if(to.y - level < 50)
    {
        double wl = to.y - 50;
        double waittime = (level - wl) / 10.0;
        if(wl - fr.x < 20) return waittime + 10.0;
        else return waittime + 1.0;
    }
    if(level - fr.x >= 20) return 1.0;
    return 10.0;
}

void initial_go()
{
    int i, nx, ny;
    queue<pii> q;
    memset(used, false, sizeof used);
    used[0][0] = true;
    q.push(mp(0, 0));
    while(!q.empty())
    {
        pii cr = q.front(); q.pop();
        for(i = 0; i < 4; ++i)
        {
            nx = cr.x + dx[i]; ny = cr.y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(used[nx][ny]) continue;
            if(can_pass(A[cr.x][cr.y], A[nx][ny], H))
            {
                q.push(mp(nx, ny));
                used[nx][ny] = true;
            }
        }
    }
}

void solve_case(int case_id)
{
    printf("Case #%d: ", case_id);
    int i, j, k, l, t;
    cin >> H >> N >> M;
    for(i = 0; i < N; ++i)
        for(j = 0; j < M; ++j) cin >> A[i][j].y;
    for(i = 0; i < N; ++i)
        for(j = 0; j < M; ++j) cin >> A[i][j].x;
    initial_go();
    if(used[N - 1][M - 1])
    {
        printf("0.0\n");
        return;
    }

    queue<pii> q;
    for(i = 0; i < N; ++i)
        for(j = 0; j < M; ++j) dist[i][j] = INF;
    dist[0][0] = 0.0;
    for(i = 0; i < N; ++i)
        for(j = 0; j < M; ++j)
            if(used[i][j])
            {
                q.push(mp(i, j));
                dist[i][j] = 0.0;
            }

    pii cr;
    int nx, ny;
    double tm, lvl;
    while(!q.empty())
    {
        cr = q.front(); q.pop();
        lvl = H - 10 * dist[cr.x][cr.y];
        for(i = 0; i < 4; ++i)
        {
            nx = cr.x + dx[i]; ny = cr.y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            tm = pass_time(A[cr.x][cr.y], A[nx][ny], lvl);
            if(tm < 0) continue;
            if(dist[nx][ny] > dist[cr.x][cr.y] + tm)
            {
                dist[nx][ny] = dist[cr.x][cr.y] + tm;
                q.push(mp(nx, ny));
            }
        }
    }

    printf("%.8lf\n", dist[N - 1][M - 1]);
}

int main()
{
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; ++i) solve_case(i);
    return 0;
}
