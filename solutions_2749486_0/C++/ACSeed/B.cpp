#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<utility>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<iomanip>
#include<queue>
#include<iterator>
using namespace std;

#define MAXN 100000 + 10
typedef int Int;
struct Point
{
    Int x, y;
    Int cnt;
    string s;
    bool operator < (const Point& a) const
    {
        if(x != a.x) return x < a.x;
        return y < a.y;
    }
};
Int tx, ty;
string bfs()
{
    set<Point> vis;
    queue<Point> Q;
    Point s;
    s.x = 0;s.y = 0;s.cnt = 0;s.s = "";
    Q.push(s);
    vis.insert(s);
    while(!Q.empty())
    {
        Point u = Q.front();
        Q.pop();
        if(u.x == tx && u.y == ty) return u.s;
        Point v;
        v.x = u.x;
        v.y = u.y;
        v.cnt = u.cnt + 1;
        v.y += v.cnt;
        v.s = u.s + "N";
        if(vis.find(v) == vis.end())
        {
            vis.insert(v);
            Q.push(v);
        }
        v.y -= v.cnt;
        v.y -= v.cnt;
        v.s = u.s + "S";
        if(vis.find(v) == vis.end())
        {
            vis.insert(v);
            Q.push(v);
        }
        v.y += v.cnt;
        v.x += v.cnt;
        v.s = u.s + "E";
        if(vis.find(v) == vis.end())
        {
            vis.insert(v);
            Q.push(v);
        }
        v.x -= v.cnt;
        v.x -= v.cnt;
        v.s = u.s + "W";
        if(vis.find(v) == vis.end())
        {
            vis.insert(v);
            Q.push(v);
        }
    }
    return "";
}
int main(int argv, char **args)
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    Int T;
    cin >> T;
    for(Int id = 1; id <= T; ++id)
    {
        cin >> tx >> ty;
        cout << "Case #" << id << ": " << bfs() << endl;
    }
    return 0;
}
