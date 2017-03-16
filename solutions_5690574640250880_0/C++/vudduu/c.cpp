//Problem C. Minesweeper Master
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define S           size()
#define MP          make_pair
typedef long long   LL;

int R, C, M;
const int xx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int yy[] = {1, -1, 0, 0, 1, -1, 1, -1};

bool good(int x, int y) {
    if(x < 0 || y < 0) return 0;
    if(x >= R || y >= C) return 0;
    return 1;
}
int count(vector<string> vs, int x, int y) {
    if(!good(x, y)) return 0;
    return vs[x][y] == '*';
}

bool isValid(vector<string> vs) {
    int c = 0;
    F(i, R) {
        F(j, C) {
            if(vs[i][j] == '*')
                c++;
        }
    }
    if(c != M) return false;
    int x = 0, y = 0;
    queue<pair<int,int> > q;
    q.push(MP(x, y));
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if(vs[x][y] == 'x') continue;
        vs[x][y] = 'x';
        int aux = 0;
        F(i, 8) aux += count(vs, x+xx[i], y+yy[i]);
        if(aux == 0) {
            F(i, 8)
                if(good(x+xx[i], y+yy[i]))
                    q.push(MP(x+xx[i], y+yy[i]));
        }
    }
    c = 0;
    F(i, R) {
        F(j, C) {
            if(vs[i][j] == 'x')
                c++;
        }
    }
    if(c != (R*C)-M) return false;
    return true;
}

void solve() {
    int r, c, m, fa;
    cin >> r >> c >> m;
    R = r;
    C = c;
    M = m;

    // cout << R << " " << C << " " << M << endl;
    fa = (r*c) - m;
    vector<string> vs(r, string(c, '.'));

    vs[0][0] = 'c';
    if(fa == 1) {
        vector<string> vs(r, string(c, '*'));        
        vs[0][0] = 'c';
        F(i, r) cout << vs[i] << endl;
        return;
    }

    if(r == 1 || c == 1) {
        vs[0][0] = 'c';
        if(r == 1) {
            for(int i=c-1; m ;i--) {
                vs[0][i] = '*';
                m--;
            }
        }
        if(c == 1) {
            for(int i=r-1; m ;i--) {
                vs[i][0] = '*';
                m--;
            }
        }
    }
    else{
        if(fa < 4){
            cout << "Impossible" << endl;
            return;
        }
        else if(m > 0) {
            vs = vector<string>(r, string(c, '*'));
            vs[0][0] = 'c';
            vs[1][0] = '.';
            fa -= 2;
            for(int i=1; i<c && fa >= 2 ;i++) {
                vs[0][i] = vs[1][i] = '.';
                fa -= 2;
                if(i+1 >= fa && r > 2 && fa >= 2) {
                    for(int j=0; j<fa ;j++)
                        vs[2][j] = '.';
                    fa = 0;
                }
            }
            if(fa == 1) {
                cout << "Impossible" << endl;
                return;
            }
            for(int i=2; i<r && fa >= 2 ;i++) {
                vs[i][0] = vs[i][1] = '.';
                fa -= 2;
            }
            if(fa == 1 && c == 2) {
                cout << "Impossible" << endl;
                return;
            }
            int x = 2, y = 2, newY = 2, newX = 2;
            while(fa > 0) {
                // if(x >= r || y >= c) {
                //     cout << x << " " << y << endl;
                // }
                vs[x][y] = '.';
                x++;
                y--;
                fa--;
                if(y < 2 || x >= r) {
                    if(newY < c-1) {
                        newY++;
                    }
                    else{
                        newX++;
                    }
                    x = newX;
                    y = newY;
                }
            }
        }
    }
    
    if(!isValid(vs)) {
        cout << "Impossible" << endl;
    }
    else {
        F(i, r) {
            cout << vs[i] << endl;
        }
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    freopen("C-small-attempt4.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T ;cas++) {
        printf("Case #%d:\n", cas);
        solve();
    }
}
