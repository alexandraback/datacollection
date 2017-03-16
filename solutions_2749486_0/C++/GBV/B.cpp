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
#define INF (1<<30)
using namespace std;

const int MAXN = 1024, OFF = 500;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int used[MAXN][MAXN];
struct state
{
    int px, py;
    string path;
};
state ms(int _px, int _py, string _path)
{
    state s;
    s.px = _px; s.py = _py; s.path = _path;
    return s;
}
queue<state> q;

void reset()
{
    while(!q.empty()) q.pop();
    q.push(ms(0, 0, ""));
    for(int i = 0; i <  MAXN; ++i)
        for(int j = 0; j < MAXN; ++j)
    {
        used[i][j] = 0;
    }
}

string gdir(int dir)
{
    if(dir == 0) return "W";
    if(dir == 1) return "S";
    if(dir == 2) return "N";
    return "E";
}

void solve_case(int case_id)
{
    printf("Case #%d: ", case_id);
    int i, xx, yy, tx, ty, d;
    state v;
    cin >> xx >> yy;
    reset();
    while(!q.empty())
    {
        v = q.front(); q.pop();
        d = v.path.length();
        if(v.path.length() > 500) continue;
        for(i = 0; i < 4; ++i)
        {
            tx = v.px + dx[i] * (d + 1);
            ty = v.py + dy[i] * (d + 1);
            if(tx >= -OFF && tx + OFF < MAXN && ty >= -OFF && ty + OFF < MAXN && used[tx + OFF][ty + OFF] < 10)
            {
               ++used[tx + OFF][ty + OFF];
               q.push(ms(tx, ty, v.path + gdir(i)));
               if(tx == xx && ty == yy)
               {
                   //cout << tx << ' ' << ty << '\n';
                   cout << v.path + gdir(i) << '\n';
                   return;
               }
            }
        }
    }
}

int main()
{
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; ++i) solve_case(i);
    return 0;
}
