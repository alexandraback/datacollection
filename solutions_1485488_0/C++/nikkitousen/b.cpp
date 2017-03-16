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
#include <set>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define X first
#define Y second

#define INF 1000000000

int aabs(int a) { return (a<0)?-a:a; }
int H, N, M;
int f[110][110], c[110][110];
int reach[110][110];
int mark[110][110];
int dis[110][110];

int ax[4] = {-1, 0, 0, 1};
int ay[4] = {0, -1, 1, 0};

bool cango(int i, int j, int ii, int jj, int h) {
    if(ii < 0 || ii >= N || jj < 0 || jj >= M) return false;
    if(!(h <= c[ii][jj]-50 && f[i][j] <= c[ii][jj]-50 && f[ii][jj] <= c[ii][jj]-50)) return false;
    if(!(f[ii][jj] <= c[i][j]-50)) return false;
    
    return true;
}

int inside(int ii, int jj) {
    if(ii < 0 || ii >= N || jj < 0 || jj >= M) return false;
    return true;
}

int main()
{
    int T;
    cin >> T;
    
    REP(caso, T) {
        cin >> H >> N >> M;
        REP(i, N) REP(j, M) cin >> c[i][j];
        REP(i, N) REP(j, M) cin >> f[i][j];
        
        memset(reach, 0, sizeof(reach));
        memset(mark, 0, sizeof(mark));
        queue< PII > q;
        q.push(MP(0,0));
        
        while(!q.empty()) {
            PII p = q.front();
            q.pop();
            mark[p.X][p.Y] = 1;
            reach[p.X][p.Y] = 1;
            REP(i, 4) {
                if(!mark[p.X+ax[i]][p.Y+ay[i]] && cango(p.X, p.Y, p.X+ax[i], p.Y+ay[i], H)) q.push(MP(p.X+ax[i], p.Y+ay[i]));
            }
        }
        
        /*
        REP(i, N) {
            REP(j, M) cout << reach[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        */
        
        
        int res = INF;
        
        REP(i, N) {
            REP(j, M) {
                if(!reach[i][j]) continue;
                
                set< pair< int , PII > > S;
                REP(ii, N) REP(jj, M) {
                    if(ii==i && jj==j) S.insert(MP(0, MP(ii, jj))), dis[ii][jj] = 0;
                    else S.insert(MP(INF, MP(ii, jj))), dis[ii][jj] = INF;
                }
                memset(mark, 0, sizeof(mark));
                
                while(1) {
                    pair< int, PII > v;
                    v = *(S.begin());
                    S.erase(S.begin());
                    
                    int d = v.X;
                    PII p = v.Y;
                    
                    if(mark[p.X][p.Y]) continue;
                    
                    mark[p.X][p.Y] = 1;
                    int hh = H-d;
                    int x = p.X, y = p.Y;
                    
                    if(x == N-1 && y == M-1) break;
                    
                    REP(t, 4) {
                        int xx = p.X+ax[t], yy = p.Y+ay[t];
                        if(!inside(xx, yy)) continue;
                        
                        //cout << "--  " << x << " " << y << "  --   " << xx << " " <<yy << endl;
                        
                        if(!(f[xx][yy] <= c[x][y]-50)) continue; // constr. 2 does not hold
                        if(!(f[x][y] <= c[xx][yy]-50 && f[xx][yy] <= c[xx][yy]-50)) continue; // part of contr. 1 does not hold
                        
                        //cout << "ahaaa " << xx << " " << yy << endl;
                        
                        int aux = c[xx][yy]-hh;
                        int wait = 0;
                        if(aux < 50) wait = 50 - aux;
                        
                        int move = 10;
                        if((hh-wait)-f[x][y] < 20) move = 100;
                        
                        if(dis[xx][yy] > d + wait + move) {
                            dis[xx][yy] = d + wait + move;
                            S.insert(MP(dis[xx][yy], MP(xx, yy)));
                        } 
                    }   
                }
                
                if(res > dis[N-1][M-1]) res = dis[N-1][M-1];
            }
        }
        cout << "Case #" << caso+1 << ": " << res/10 << "." << res%10 << endl;
    }
}
