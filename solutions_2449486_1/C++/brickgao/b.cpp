//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

typedef struct record {
    int x, y, v;
} pos;

bool flag;
int t, m, n, caseno = 1;
int a[102][102], map[102][102], maxrow[102], maxcol[102];
vector <pos> pt;

bool cmp(pos a, pos b) {
    return a.v < b.v;
}

int main() {
    cin >> t;
    while(t --) {
        flag = true;
        pt.clear();
        cin >> n >> m;
        for(int i = 0; i < n; i ++) {
            int maxn = 0;
            for(int j = 0; j < m; j ++) {
                pos tmp;
                map[i][j] = 100;
                cin >> a[i][j];
                tmp.x = i, tmp.y = j;
                tmp.v = a[i][j];
                pt.push_back(tmp);
                maxn = max(maxn, a[i][j]);
            }
            maxrow[i] = maxn;
        }
        for(int j = 0; j < m; j ++) {
            int maxn = 0;
            for(int i = 0; i < n; i ++) {
                maxn = max(maxn, a[i][j]);
            }
            maxcol[j] = maxn;
        }
        sort(pt.begin(), pt.end(), cmp);
        for(int i = 0; i < SZ(pt); i ++) {
            int x = pt[i].x, y = pt[i].y, v = pt[i].v;
            if(v == map[x][y])  continue;
            if(v != maxrow[x] && v != maxcol[y]) {
                flag = false;
                break;
            }
            if(v == maxrow[x]) {
                for(int j = 0; j < m; j ++) {
                    map[x][j] = min(map[x][j], v);
                }
            }
            if(v == maxcol[y]) {
                for(int j = 0; j < n; j ++) {
                    map[j][y] = min(map[j][y], v);
                }
            }
        }
        if(!flag) {
            printf("Case #%d: NO\n", caseno ++);
            continue;
        }
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                if(a[i][j] != map[i][j]) {
                    flag = false;
                    break;
                }
            }
            if(!flag) {
                break;
            }
        }
        if(flag) {
            printf("Case #%d: YES\n", caseno ++);
        }
        else {
            printf("Case #%d: NO\n", caseno ++);
        }
    }
    return 0;
}

