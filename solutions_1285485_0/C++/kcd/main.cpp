#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <utility>
#include <cstring>


using namespace std;
typedef long long LL;
#define x1 gjigu
#define y1 djigd
template<typename T>
inline T Abs(const T& value) { return value < 0 ? -value : value; }
template<typename T>
inline T Sqr(const T& value) { return value * value; }

int vm(int x1, int y1, int x2, int y2) {
    return x1*y2 - x2*y1;
}

const int maxn = 31;

char c[maxn][maxn];

struct TElem {
    int y, x;
    TElem(int y_, int x_)
        : y(y_)
        , x(x_)
    { }
};

bool operator<(const TElem& a, const TElem& b) {
    if (a.y >= 0 && b.y < 0)
        return true;
    if (a.y < 0 && b.y >= 0)
        return false;
    if (a.y == 0 && b.y == 0) {
        return a.x > 0 && b.x < 0;
    } else
        return vm(a.x, a.y, b.x, b.y) > 0;
}

set<TElem> e;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tt = 0; tt < t; ++tt) {
        e.clear();
        int n, m, d;
        cin >> n >> m >> d;
        int y0, x0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                cin >> c[i][j];
                if (c[i][j] == 'X') {
                    y0 = i;
                    x0 = j;
                }
            }
        y0 = y0*2 - 1;
        x0 = x0*2 - 1;
        n = 2*(n-2);
        m = 2*(m-2);
        d *= 2;
        for (int i = -d; i <= +d; ++i)
            for (int j = -d; j <= +d; ++j) {
                if (i != 0 || j != 0) {
                    int y = i * n;
                    int x = j * m;
                    if (Abs(i) % 2 == 0)
                        y += y0;
                    else
                        y += n - y0;
                    if (Abs(j) % 2 == 0)
                        x += x0;
                    else
                        x += m - x0;
                    if (Sqr(x-x0) + Sqr(y-y0) <= Sqr(d))
                        e.insert(TElem(y-y0, x-x0));
                }
            }
/*        for (set<TElem>::iterator it = e.begin(); it != e.end(); ++it) {
            cout << it->y << " " << it->x << endl;
        }
*/        cout << "Case #" << tt+1 << ": " << e.size() << endl;
    }
    

    return 0;
}
