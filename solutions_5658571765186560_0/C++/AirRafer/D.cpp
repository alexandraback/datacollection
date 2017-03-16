

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>


using namespace std;

#define geti(x) scanf("%d", &x)
#define getc(x) scanf("%c", &x)

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

//int P[];
//int find_ds(int x) {
//   return ((P[x] == x) ? x : (P[x] = find_ds(P[x])));
//}

int dx4[] = {-1, 0, 1, 0};
int dy4[] = {0, -1, 0, 1};

unordered_map<int, bool> map;

#define MAXN 7

int P[MAXN][MAXN];
int M[MAXN][MAXN];
int I[MAXN][2];
int G[MAXN][2];

bool test(int X, int R, int C) {
    
    int color = 2;
    
    for(int y=0;y<R;y++) {
        for(int x=0;x<C;x++) {
            
            if(M[y][x] == 0) {
                
                queue<pair<int,int> > Q;
                Q.push(make_pair(y,x));
                M[y][x] = color;
                int N = 0;
                
                while(!Q.empty()) {
                    
                    N++;
                    int ty = Q.front().first;
                    int tx = Q.front().second;
                    
                    Q.pop();
                    
                    for(int i=0;i<4;i++) {
                        
                        int yy = ty+dy4[i];
                        int xx = tx+dx4[i];
                        if(yy < 0 || xx < 0 || yy >= R || xx >= C)
                            continue;
                        if(M[yy][xx] != 0)
                            continue;
                        Q.push(make_pair(yy,xx));
                        M[yy][xx] = color;
                    }
                }
                if(N % X != 0)
                    return false;
                
                
                color++;
            }
            
            
        }
    }
    
    return true;
}

void clear(int R, int C) {
    
    for(int y=0;y<R;y++) {
        for(int x=0;x<C;x++) {
                M[y][x] = 0;
            
        }
    }
    
}



bool drawP2M(int X, int R, int C) {
    
//    int sig = 0;
//    for(int y=0;y<h;y++) {
//        for(int x=0;x<w;x++) {
//            if(P[py+y][px+x]) {
//                int idx = C*y + x;
//                sig |= (1 << idx);
//            }
//        }
//    }
//    if(map[sig]) {
//        return true;
//    }
//    map[sig] = true;
    
    
    int left = INT_MAX, right = 0;
    int top = INT_MAX, bottom = 0;
    
    for(int i=0;i<X;i++) {
        
        int y = I[i][0];
        int x = I[i][1];
        
        if( y < top)
            top = y;
        if( y > bottom)
            bottom = y;
        if( x < left)
            left = x;
        if( x > right)
            right = x;
    }
    int w = right - left + 1;
    int h = bottom - top + 1;
    int py = top, px = left;
    
    for(int sy=0;sy<R;sy++) {
        
        for(int sx=0;sx<C;sx++) {
            
            if(sy + h > R || sx + w > C)
                continue;
            
            //can draw
            clear( R, C);
            for(int i=0;i<X;i++) {
                
                M[I[i][0]-py+sy][I[i][1]-px+sx] = 1;
                
            }
            bool pass = test(X, R, C);
            
            if(pass) {
                return true;
            }
            
        }
        
    }
    return false;
}

void copyI(int X) {
    for(int i=0;i<X;i++) {
        I[i][0] = G[i][0];
        I[i][1] = G[i][1];
    }
}

void rotateI(int N, int X) {
    
    for(int i=0;i<X;i++) {
        
        int y = I[i][0];
        int x = I[i][1];
        
        I[i][0] = x;
        I[i][1] = N-1 - y;
        
    }
    
    
}

static int cnt = 0;

bool dfs(int X, int R, int C, int ay, int ax, int k) {
    
    P[ay][ax] = 1;
    G[k][0] = ay;
    G[k][1] = ax;
    
    if(k == X-1) {
        
        cnt++;
        
        copyI(X);
        bool ok = false;
        for(int i=0;i<4;i++) {
            
            
            if(drawP2M(X, R, C))
                return true;
            
            rotateI(MAXN, X);
        }
        
        P[ay][ax] = 0;
        
        return ok;
    }
    
    for(int i=0;i<=k;i++) {
        
        int y = G[i][0];
        int x = G[i][1];
        for(int d=0;d<4;d++) {
            
            int yy = y + dy4[d];
            int xx = x + dx4[d];
            if(yy < 0 || yy >= MAXN || xx < 0 || xx >= MAXN)
                continue;
            if(P[yy][xx])
                continue;
            if(!dfs(X, R, C, yy, xx, k+1))
                return false;
            
        }
    }
    P[ay][ax] = 0;
    return true;
}


bool genP(int X, int R, int C) {
    
    //for(int sy=0;sy<MAXN;sy++) {
        
        for(int sx=0;sx<MAXN;sx++) {
            
            for(int y=0;y<R;y++)
                for(int x=0;x<C;x++)
                    P[y][x] = 0;
            
            if(!dfs(X, R, C, 0, sx, 0))
                return false;
            
        }
        
   // }
    return true;
}



bool solve(int X, int R, int C) { //no solution return false
    
 
    clear(R, C);
    map.clear();
    
    return genP(X, R, C);
    
}


int main() {

	freopen("/Users/cheng/Google/ACM/env/d.in", "r", stdin);
    freopen("/Users/cheng/Google/ACM/env/d.out", "w+", stdout);
    
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        
        int X, R, C;
        cin >> X >> R >> C;
        
        bool ans = solve(X, R, C);
        
        cout<<"Case #"<<t<<": "<< (ans ? "GABRIEL" : "RICHARD")<<endl;
    }
    
    return 0;
}

