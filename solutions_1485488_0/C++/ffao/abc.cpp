#include<iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;

int n,m,T;
int dist[100][100];
int marked[100][100];
int ceiling[100][100];
int floor[100][100];
int height;

double inf = 1e15;

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        memset(dist,-1,sizeof(dist));
        memset(marked,0,sizeof(marked));
        scanf("%d", &height);
        scanf("%d %d", &n, &m);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &ceiling[i][j]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &floor[i][j]);
            }
        }
        
        dist[0][0] = 0;
        int currx = 0;
        int curry = 0;
        while (currx != -1) {
            marked[currx][curry]=1;
            
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx*dy == 0 && dx+dy != 0) {
                        int tgx = currx+dx;
                        int tgy = curry+dy;
                        if (tgx < 0 || tgx >= n) continue;
                        if (tgy < 0 || tgy >= m) continue;
                        if (marked[tgx][tgy]) continue;
                        
                        if (ceiling[tgx][tgy] - floor[tgx][tgy] < 50) continue; 
                        if (ceiling[tgx][tgy] - floor[currx][curry] < 50) continue; 
                        if (ceiling[currx][curry] - floor[tgx][tgy] < 50) continue;  
                        if (ceiling[tgx][tgy] - height < 50) continue;
                        
                        //printf("dist[%d][%d] is now 0\n",tgx,tgy);
                        dist[tgx][tgy] = 0;
                    }
                } 
            }
            
            currx = -1;
            curry = -1;
            int best_dist = 1000000000;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!marked[i][j] && dist[i][j]!=-1) {
                        if (dist[i][j] < best_dist) {
                            currx=i; curry=j;
                            best_dist = dist[i][j];
                        }
                    }
                }
            }
        }
        
        memset(marked,0,sizeof(marked));
        currx = 0; curry = 0;
        
        while (currx != -1) {
            //printf("Going out from %d %d\n",currx,curry);
            marked[currx][curry]=1;
            
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx*dy == 0 && dx+dy != 0) {
                        int tgx = currx+dx;
                        int tgy = curry+dy;
                        
                        if (tgx < 0 || tgx >= n) continue;
                        if (tgy < 0 || tgy >= m) continue;
                        if (marked[tgx][tgy]) continue;
                        //printf("dist[%d][%d] is now ana %d %d %d\n",tgx,tgy,n,m,marked[tgx][tgy]);
                        
                        int ch = height-dist[currx][curry];
                        int delay = 0;
                        if (ceiling[tgx][tgy] - floor[tgx][tgy] < 50) continue; 
                        if (ceiling[tgx][tgy] - floor[currx][curry] < 50) continue; 
                        if (ceiling[currx][curry] - floor[tgx][tgy] < 50) continue;  
                        if (ceiling[tgx][tgy] - ch < 50) {
                            delay = ch-(ceiling[tgx][tgy]-50);
                        }
                        
                        int temph = ch-delay;
                        int nd;
                        
                        if (temph - floor[currx][curry] >= 20) nd = dist[currx][curry]+10+delay;
                        else nd = dist[currx][curry]+100+delay;
                    
                        if (dist[tgx][tgy] == -1 || nd < dist[tgx][tgy]) dist[tgx][tgy] = nd;
                    }
                } 
            }
            
            currx = -1;
            curry = -1;
            int best_dist = 1000000000;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    //printf("testing %d %d\n",i,j,marked[i][j],dist[i][j]);
                    if (!marked[i][j] && dist[i][j]!=-1) {
                        if (dist[i][j] < best_dist) {
                            currx=i; curry=j;
                            best_dist = dist[i][j];
                        }
                    }
                }
            }
        }
        
        printf("%lf\n", dist[n-1][m-1]/10.);
    }    
}
