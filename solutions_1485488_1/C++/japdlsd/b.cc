/* Look at my code
 * My code is amazing
 * Give it a lick
 * Mmm! It tastes just like raisins!
*/

//another_fine_solution by Askar

// input/output
#include <cstdio>
#include <iostream>
// structures
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <tr1/unordered_set>
#include <tr1/unordered_map>
// other stuff
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <utility>
// debug
#ifndef EBUG
    #define NDEBUG
#endif
#include <cassert>

using namespace std;
using namespace std::tr1;

#ifdef EBUG
    #include <cstdio>
    #define db(x) cout << #x << "\t: " << (x) << endl;
    #define dbg if(1)
#else
    #define db(x)
    #define dbg if(0)
#endif

#define For(i,n) for(int i = 0; i < n; i++)
#define iter(x) typeof((x).begin())
#define Foreach(it, str) for(typeof((str).begin()) it = (str).begin(); it != (str).end(); it++)
#define mp make_pair
#define PASS
#define ll long long
#define INF 2000000000

int H, M, N;

vector<vector<int> > F, C;

vector<vector<double> > bfs;

int dx[] =  {0,0,-1,1};
int dy[] =  {-1, 1, 0,0};

double dostanem_sa_o(double cas, pair<int, int> from, pair<int, int> to){
    //The water level, the floor height of your current square, and the floor height of the adjacent square must all be at least 50 centimeters lower than the ceiling height of the adjacent square. Note: this means that you will never be able to enter a square with less than 50 centimeters between the floor and the ceiling.
    double NEVER = -1;
    
    // najprv tu fruhu
    if(C[from.first][from.second] < F[to.first][to.second]  + 50) return NEVER;
    
    // teraz tu trapnu
    
    if(F[from.first][from.second] + 50 > C[to.first][to.second] || F[to.first][to.second] + 50 > C[to.first][to.second]) return NEVER;
    else{
        double w_cur = max(H - 10*cas, 0.0);
        double w_will = C[to.first][to.second] - 50;
        if(w_cur <= w_will && w_cur - F[from.first][from.second] >= 20){
            if(cas == 0) return 0;
            return cas + 1; 
        }
        if(w_cur <= w_will){
            if(cas == 0) return 0; 
            return cas + 10;
        }
        else{
            //musime cakat
            double dt = (w_cur - w_will)/10;
            if(w_will - F[from.first][from.second] >= 20) return cas + 1 + dt;
            else return cas + 10 + dt;
        }

    }
    return cas;
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        F.clear();
        C.clear();
        cin >> H >> N >> M;
        F.resize(N);
        C.resize(N);
        For(i, N){
            C[i].resize(M);
            For(j, M){
                cin >> C[i][j];
            }
        }
        For(i, N){
            F[i].resize(M);
            For(j, M){
                cin >> F[i][j];
            }
        }
    
        bfs.clear();
        bfs.resize(N);
        For(i, N) bfs[i].resize(M, -1);
    
        queue<pair<int, int> > qu;

        qu.push(mp(0,0));
        bfs[0][0] = 0;



        while(!qu.empty()){
            int x = qu.front().first;
            int y = qu.front().second;
            qu.pop();
            double cas = bfs[x][y];
            For(i, 4){
                int xx = x + dx[i];
                int yy = y + dy[i];
                if(xx < 0 || xx >= N || yy < 0 || yy >= M ) continue;
                double reach = dostanem_sa_o(cas, mp(x,y), mp(xx,yy));
                if(reach != -1 && (bfs[xx][yy] == -1 || bfs[xx][yy] > reach)){
                    bfs[xx][yy] = reach;
                    qu.push(mp(xx, yy));
                    dbg{
                        db(cas);
                        For(i, N){  For(j, M) cerr << bfs[i][j] << " "; cerr << endl;
                    }

                    }
                }
            }
        }
        cout.precision(12);
        cout << "Case #" << t << ": " << bfs[N-1][M-1] << endl;
    }
}
