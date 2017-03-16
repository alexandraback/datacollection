#include <fstream>
#include <vector>
#include <set>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

int t, w, h, c, d, dd, xs, ys, nextfree;
vector< pair<int, int> > pts;
set< pair<int, int> > g;

int d2(int x, int y) {
    return (x-xs)*(x-xs) + (y-ys)*(y-ys);
}

bool coll(int x1, int y1, int x2, int y2) {
    x1 -= xs;
    y1 -= ys;
    x2 -= xs;
    y2 -= ys;
    return (d2(x1+xs, y1+ys) > d2(x2+xs, y2+ys)) && ((x1*x2 + y1*y2) > 0) && (x1*x2 + y1*y2)*(x1*x2 + y1*y2) == (x1*x1 + y1*y1)*(x2*x2 + y2*y2);
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int ans = 0;
        pts.clear();
        g.clear();
        cin >> h >> w >> d;
        dd = d*d;
        char c;
        for (int y = 0; y < h; ++y)
            for (int x = 0; x < w; ++x) {
                cin >> c;
                if (c == 'X') {
                    xs = x;
                    ys = y;
                }
            }
        h -= 2;
        w -= 2;
        //cout << w << ' ' << h << endl;
        for (int p = -d/(2*w)-2; p < d/(2*w) + 3; ++p)
            for (int q = -d/(2*h)-2; q < d/(2*h) + 3; ++q) {
                g.insert(make_pair(2*p*w - xs+1, 2*q*h - ys+1));
                g.insert(make_pair(2*p*w - xs+1, 2*q*h + ys));
                g.insert(make_pair(2*p*w + xs, 2*q*h - ys+1));
                g.insert(make_pair(2*p*w + xs, 2*q*h + ys));
            }
        g.erase(make_pair(xs, ys));
        for (set< pair<int, int> >::iterator i = g.begin(); i != g.end(); ++i)
            pts.push_back(*i);
        for (int _i = 0; _i < pts.size(); ++_i) {
            bool good = d2(pts[_i].first, pts[_i].second) <= dd;
            for (int j = 0; j < pts.size() && good; ++j)
                if (coll(pts[_i].first, pts[_i].second, pts[j].first, pts[j].second)) good = false;
            //if (good) cout << pts[_i].first << ' ' << pts[_i].second << endl;
            ans += good;
        }

        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}
