#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long            int64;
typedef pair<double, double> pdd;
typedef pair<int,  int>      pii;
typedef pair<int64, int64>   pii64;
typedef unsigned long long   uint64;
typedef vector<double>       vd;
typedef vector<int64>        vi64;
typedef vector<int>          vi;
typedef vector<vi>           vvi;
typedef pair<int, string>    pis;
const double eps = 1e-11;
const double pi  = acos(-1.0);
const int    p   = 1000000007;

void solve() {
    int X,Y;
    cin >> X >> Y;
    if (X > 0)
        for (int i = 0; i < X; ++i)
            cout << "WE";
    else
        for (int i = 0; i < -X; ++i)
            cout << "EW";
    if (Y > 0)
        for (int i = 0; i < Y; ++i)
            cout << "SN";
    else
        for (int i = 0; i < -Y; ++i)
            cout << "NS";
    cout << endl;
//    map<pii, pis> path;
//    path[pii(0,0)] = pis(0, string());
//    priority_queue<pair<int, pii>> q; // (dist, coords)
//    q.push(pair<int, pii>(0, pii(0,0)));
//    while (!q.empty()) {
//        pair<int, pii> cur = q.top();
//        q.pop();
//        int dist = -cur.first;
//        if (path.find(pii(X,Y)) != path.end() && path[pii(X,Y)].first <= dist)
//            break;
//        int x = cur.second.first, y = cur.second.second;
//        if (path[cur.second].first < dist) {
//            continue;
//        }
//        vector<vector<int> > st({
//            {'N', 0, 1}, {'S', 0, -1}, {'E', 1, 0}, {'W', -1, 0}}
//        );
//        for (vector<int> &u : st) {
//            char c = u[0];
//            int dx = u[1], dy = u[2];
//            int new_x = x + dx * (dist + 1);
//            int new_y = y + dy * (dist + 1);
//            if (abs(new_x) > 500 || abs(new_y) > 500)
//                continue;
//            pii coord = pii(new_x, new_y);
//            int new_dist = dist + 1;
//            if (path.find(coord) == path.end() || new_dist < path[coord].first) {
//                string new_path = path[pii(x,y)].second + c;
//                path[coord] = pis(new_dist, new_path);
//                q.push(pair<int, pii>(-new_dist, coord));
//            }
//        }
//
//    }
//    cout << path[pii(X,Y)].second << endl;
}

int main() {
    int nTests;
    cin >> nTests;

    for(unsigned int testNumber = 0; testNumber < nTests; ++testNumber) {
        printf("Case #%d: ", testNumber + 1);
        solve();
    }
    return 0;
}
