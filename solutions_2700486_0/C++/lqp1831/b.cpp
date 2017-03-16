#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rev(i, n) for(int i = (n) - 1; i >= 0; --i)
using namespace std;

void bug() { cout << " " << endl; }
template<class T> void bug(T a) { cout << a << "  "; }
template<class T> void bug(T* a, int n) {rep(i, n) bug(a[i]);}

int n;
int X, Y;
double f[1111][1111];

double run() {
    cin >> n >> X >> Y;
    int floor = (abs(X) + abs(Y)) / 2 + 1;

    int go = 0, top = 0;
    rep(i, 1000000) if(i){
        if(n < 4 * i - 3) {
            go = i;
            top = 2 * i - 2;
            break;
        }
        else n -= 4 * i - 3;
    }

    if(go > floor)  return 1.0;
    if(X == 0) return 0.0;
    if(go < floor) return 0.0;

    
    memset(f, 0, sizeof(f));
    f[0][0] = 1.0;
    rep(i, n) rep(j, i + 1) if(f[i][j] >= 1e-8){
        int l = j;
        int r = i - j;
        if(l + 1 > top) f[i + 1][j] += f[i][j];
        else if(r + 1 > top) f[i + 1][j + 1] += f[i][j];
        else {
            f[i + 1][j] += f[i][j] / 2;
            f[i + 1][j + 1] += f[i][j] / 2;
        }
    }

    double ans = 0;
    rep(i, n + 1) if(i >= Y + 1) ans += f[n][i];

    return ans;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) 
        printf("Case #%d: %.8lf\n", i + 1, run());
    return 0;
}
