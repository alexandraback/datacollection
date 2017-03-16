#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
using namespace std;
int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
string ss = "ENWS";
int ax, ay, xx, yy;
struct aa{
    int x,y,c,d;
    string s;
    bool operator < (const aa &a) const{
        return c > a.c;
    }
};
struct bb{
    int x,y;
    bool operator < (const bb &a) const{
        if (a.x != x)
            return x < a.x;
        return y < a.y;
    }
};
int get(int nowx, int nowy, int d) {
    int now = 2*(abs(ax-nowx)+abs(ay-nowy));
    int l = 1, r = 10000, m;
    while (l+1 < r) {
        m = (l+r)>>1;
        if (m*m+(2*d-1)*m<=now)
            l = m;
        else 
            r = m;
    }
    return d+l;
}
int main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        cout << "Case #" << tt << ": ";
        cin >> ax >> ay; 
        priority_queue<aa> a;
        set<bb> mm;
        aa now;
        now.x = 0;
        now.y = 0;
        now.c = get(0, 0, 1);
        now.d = 1;
        now.s = "";
        a.push(now);
        int mark = 0;
        while (!mark) {
            now = a.top();
            a.pop();
            for (int i = 0; i < 4; ++i) {
                xx = now.x+d[i][0]*now.d;
                yy = now.y+d[i][1]*now.d;
                if (xx == ax && yy == ay) {
                    cout << (now.s+ss[i]) << endl;
                    mark = 1;
                    break;
                }
                bb b;
                b.x = xx;
                b.y = yy;
                if (mm.count(b))
                    continue;
                //cout << xx << " " << yy << endl;
                mm.insert(b);
                aa tmp;
                tmp.x = xx;
                tmp.y = yy;
                tmp.c = get(xx, yy, now.d+1);
                tmp.d = now.d+1;
                tmp.s = now.s+ss[i];
                a.push(tmp);
            }
        }
    }
    return 0;
}
