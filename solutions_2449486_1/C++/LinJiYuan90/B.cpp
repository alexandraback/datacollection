#include "sstream"
#include "iostream"
#include "cstdio"
#include "cstring"
#include "cmath"
#include "algorithm"
#include "vector"
#include "map"
#include "set"
#include "queue"
#include "deque"
#include "list"
#include "string"
#include "cassert"

using namespace std;

typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;

int main()
{
    freopen("b.in", "r", stdin);
    int T, t = 1;
    for (cin>>T; T--; ) {
        cout<<"Case #"<<t++<<": ";
        int n, m;
        cin>>n>>m;
        int lawn[100][100];
        VI vt;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>lawn[i][j];
                vt.push_back(lawn[i][j]);
            }
        }
        sort(vt.begin(), vt.end());
        vt.resize(unique(vt.begin(), vt.end()) - vt.begin());
        int ok = 1;
        int x[100], y[100];
        fill(x, x+n, -1);
        fill(y, y+m, -1);
        for (int k = 0; k < vt.size() && ok; k++) {
            //horizontal
            for (int i = 0; i < n && ok; i++) {
                int cnt_lt = 0, cnt_eq = 0;
                for (int j = 0; j < m; j++) {
                    if (lawn[i][j] < vt[k]) {
                        cnt_lt ++;
                    }
                    if (lawn[i][j] == vt[k]) {
                        cnt_eq ++;
                    }
                }
                if (cnt_lt + cnt_eq == m) {
                    if (cnt_eq > 0 && x[i] != -1 && x[i] != vt[k]) {
                        ok = 0;
                        break;
                    }
                    x[i] = vt[k];
                } else {
                    for (int j = 0; j < m; j++) {
                        if (lawn[i][j] == vt[k]) {
                            if (y[j] != -1 && y[j] != vt[k]) {
                                ok = 0;
                                break;
                            }
                            y[j] = vt[k];
                        }
                    }
                }
            }
            //vertical
            for (int j = 0; j < m && ok; j++) {
                int cnt_lt = 0, cnt_eq = 0;
                for (int i = 0; i < n; i++) {
                    if (lawn[i][j] < vt[k]) {
                        cnt_lt ++;
                    }
                    if (lawn[i][j] == vt[k]) {
                        cnt_eq ++;
                    }
                }
                if (cnt_lt + cnt_eq == n) {
                    if (cnt_eq > 0 && y[j] != -1 && y[j] != vt[k]) {
                        ok = 0;
                        break;
                    }
                    y[j] = vt[k];
                } else {
                    for (int i = 0; i < n; i++) {
                        if (lawn[i][j] == vt[k]) {
                            if (x[i] != -1 && x[i] != vt[k]) {
                                ok = 0;
                                break;
                            }
                            x[i] = vt[k];
                        }
                    }
                }
            }
        }
        cout<<(ok ? "YES" : "NO")<<endl;
    }
    return 0;
}

