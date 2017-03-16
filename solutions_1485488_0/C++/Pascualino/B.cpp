#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

#define c first
#define x second.first
#define y second.second
#define INF 20000000

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

int H, N, M;
bool v(int xx, int yy){
     return xx >= 0 && yy >= 0 && xx < N && yy < M;
}

int main(){
    int T;
    cin >> T;
    for(int t=1; t<=T; t++){
            cin >> H >> N >> M;
            vector<vector<int> > C(N, vector<int>(M));
            for(int i=0;i<N;i++)
                    for(int j=0;j<M;j++)
                            cin >> C[i][j];
                            
            vector<vector<int> > F(N, vector<int>(M));
            for(int i=0;i<N;i++)
                    for(int j=0;j<M;j++)
                            cin >> F[i][j];
            
            priority_queue<PIII> pq;
            pq.push(PIII(INF, PII(0, 0)));
            
            PIII a;
            vector<vector<int> > T(N, vector<int> (M,-INF-1));
            while(!pq.empty()){
                 a = pq.top();
                 pq.pop();
                 if(T[a.x][a.y] == -INF-1){
                     T[a.x][a.y] = a.c;
                     int dx[] = {1, 0, -1, 0}, dy[] = { 0, 1, 0, -1};
                     for(int i=0;i<4;i++){
                         if(v(a.x+dx[i], a.y+dy[i]) && C[a.x+dx[i]][a.y+dy[i]] - F[a.x+dx[i]][a.y+dy[i]] >= 50 &&
                            C[a.x][a.y] - 50 >= F[a.x+dx[i]][a.y+dy[i]] &&
                            C[a.x+dx[i]][a.y+dy[i]] - 50 >= F[a.x][a.y]){
                                 int nH = C[a.x+dx[i]][a.y+dy[i]] - 50;
                                 if(a.c == INF && nH >= H) nH = INF;
                                 if(nH != INF){
                                         nH = min(nH, a.c);
                                         if(nH - F[a.x][a.y] >= 20) nH -= 10;
                                         else nH -= 100;
                                 }
                                 pq.push(PIII(nH, PII(a.x+dx[i], a.y+dy[i])));
                            }
                     }
                 }
                 if(a.x == N-1 && a.y == M-1) break;
            }
            cout << "Case #" << t << ": ";
            cout << fixed << setprecision(1) << max(0.,(H-T[a.x][a.y])/10.) << endl;
    }
}
/*
4
200 2 1
250 233
180 100
*/
