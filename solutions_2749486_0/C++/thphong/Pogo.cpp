#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstring>

#define MAXN 100
#define INFTY 1000000000

using namespace std;
int x, y;
bool f[2*MAXN+1][2*MAXN+1][501];
char di[2*MAXN+1][2*MAXN+1][501];
int pre[2*MAXN+1][2*MAXN+1][501];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char dd[] = {'N', 'S', 'W', 'E'};
 
 void Init(){      
    f[MAXN][MAXN][0] = 1;
    for(int step = 1; step<= 500; step++){
            for(int i=-MAXN; i<=MAXN; i++){
                 for(int j=-MAXN; j<=MAXN; j++) if(f[i+MAXN][j+MAXN][step-1]){
                      for(int k=0; k<4; k++){
                           int nX = i+MAXN+dx[k]*step;
                           int nY = j+MAXN+dy[k]*step;
                           if(nX >= 0 && nX <= 2*MAXN && nY >= 0 && nY <= 2*MAXN)
                           {
                                 f[nX][nY][step] = 1;
                                 //if(step < 5) cout<<nX<<" "<<nY<<" "<<step<<endl;
                                 pre[nX][nY][step] = (i+MAXN)*(2*MAXN+1)+j+MAXN;
                                 di[nX][nY][step] = dd[k];
                           }
                      }
                 }
            }
    }
 }
 
void Trace(int X, int Y, int step){
     //cout<<X<<" "<<Y<<" "<<step<<endl;
     if(step > 0){
           int nX = pre[X][Y][step] / (2*MAXN+1);
           int nY = pre[X][Y][step] % (2*MAXN+1);
           Trace(nX, nY, step-1);
           cout<<di[X][Y][step];
     }
}

void Solve(){
    for(int step=0; step<=500; step++)
    if(f[x+MAXN][y+MAXN][step]){
          Trace(x+MAXN, y+MAXN, step);
          return;
    }
}

int main () {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    Init();
    for(int ca=1; ca<=t; ca++){
        cin >> x >> y;            
        cout<<"Case #"<<ca<<": ";
        Solve();
        cout<<endl;
    }
    return 0;
}
