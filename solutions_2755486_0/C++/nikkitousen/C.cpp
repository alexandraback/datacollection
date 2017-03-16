#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <fstream>
#include <set>

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define MP make_pair
#define PB push_back
#define VI vector<int>
#define VS vector<string>
#define PII pair<int, int>
#define X first
#define Y second

int aabs(int a) { return (a<0)?-a:a; }
int mmax(int a, int b) { return (a>b)?a:b; }
int mmin(int a, int b) { return (a<b)?a:b; }

#define ZERO 500
int wall[1000];
int modif[1000][5]; // last_modif_day, prev_height

#define di 0
#define ni 1
#define wi 2
#define ei 3
#define si 4
#define ddi 5
#define dpi 6
#define dsi 7

int N;
int tribes[100][10]; // di, ni, wi, ei, si, delta_di, delta_pi, delta_si
vector<pair<int, int> > v;

int main()
{
    int T;
    cin >> T;
    
    REP(caso, T) {
        cin >> N;
        
        v.clear();
        REP(i, N) {
            REP(j, 8) cin >> tribes[i][j];
            v.PB(MP(tribes[i][0], i));
        }
        
        memset(wall, 0, sizeof(wall));
        REP(i, 1000) modif[i][0] = -1, modif[i][1] = 0;
        int ret = 0;
        
        while(SZ(v) > 0) {
            SORT(v);
            int k = v[0].Y;
            int d = v[0].X;
            if(d > tribes[k][di] + (tribes[k][ni]-1)*tribes[k][ddi]) {
                v.erase(v.begin());
                continue;
            }
            
            int n = (d - tribes[k][di]) / tribes[k][ddi];
            int s = tribes[k][si] + n*tribes[k][dsi];
            int w = tribes[k][wi] + n*tribes[k][dpi];
            int e = tribes[k][ei] + n*tribes[k][dpi];
            
            
            
            
            bool succ = false;
            FOR(i, ZERO+w, ZERO+e) {
                if(wall[i] < s) {
                    succ = true;
                    modif[i][0] = d;
                    modif[i][1] = wall[i];
                    wall[i] = s;
                } else if (d == modif[i][0] and modif[i][1] < s) {
                    succ = true;
                }
            }
            
            if(succ) ret++;
            
            //cout << d << " " << k << " " << n << " " << s << " " << w << " " << e << " " << succ << endl;
            
            v[0].X = d + tribes[k][ddi];
        }
        
        cout << "Case #" << caso+1 << ": " << ret << endl;
        
    }
    
}
