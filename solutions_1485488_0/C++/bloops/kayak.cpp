#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <initializer_list>
using namespace std;
typedef pair<int,int> ii;
const int N = 11;
const int H = 1010;
bool D[N][N][H];

int F[N][N], C[N][N];

int h, n, m;

struct state { 
    int i, j;
    int h;
    double t;
};

bool operator <(const state &a, const state &b){
    if(fabs(a.t-b.t) < 1e-10)
        return make_pair(ii(a.i, a.j), a.h) < make_pair(ii(b.i,b.j), b.h);
    return a.t < b.t;
}

int di [] = {0,1,0,-1};
int dj [] = {1,0,-1,0};

bool ok(int i1, int j1, int i2, int j2, int wh){
    if(max(wh, max(F[i1][j1], F[i2][j2])) > C[i2][j2] - 50)
        return false;
    if(F[i2][j2] > C[i1][j1] - 50)
        return false;
    return true;
}

int time(int i1, int j1, int i2, int j2, int wh){
    if(wh >= F[i1][j1] + 20)
        return 1;
    return 10;
}


double search(){
    set<state> Q;
    queue<state> P;
    // at state (0,0,h)
    state s = {0,0,h,0};
    memset(D, 0, sizeof(D));

    P.push(s); 
    while(!P.empty()){
        state cur = P.front();

        
        Q.insert(cur);
        //printf("Inserting into Q (%d,%d,%d,%f) = %d\n", cur.i, cur.j, cur.h, cur.t, Q.size());        
        P.pop();
        if(D[cur.i][cur.j][cur.h])
            continue;
        D[cur.i][cur.j][cur.h] = 1;

        for (int l = 0; l < 4; l++){
            int i2 = cur.i + di[l], j2 = cur.j + dj[l];
            if(!(0 <= i2 and i2 < n and 0 <= j2 and j2 < m))
                continue;
            if(!ok(cur.i,cur.j,i2,j2,h))
                continue;
            state ncur = {i2,j2,h,0};
            P.push(ncur);
            // printf("Pushing into P (%d,%d,%d,%f)\n", ncur.i, ncur.j, ncur.h, ncur.t);
        }
    }
    //cout << "Size " << Q.size() << endl;
    memset(D, 0, sizeof(D));
    double ans = -1;
    while(!Q.empty()){
        state cur = *Q.begin();
        //printf("At state (%d,%d,%d,%f)\n", cur.i, cur.j, cur.h, cur.t);
        Q.erase(Q.begin());

        if(D[cur.i][cur.j][cur.h])
            continue;
        D[cur.i][cur.j][cur.h] = 1;

        if(cur.i == n-1 and cur.j == m-1){
            ans = cur.t;
            break;
        }
            
        // wait out 0.1 second
        if(cur.h > 0){
            state acur = cur;
            acur.h -= 1;
            acur.t += 0.1;
            Q.insert(acur);
        }
        
        for (int l = 0; l < 4; l++){
            int i2 = cur.i + di[l], j2 = cur.j + dj[l];
            if(!(0 <= i2 and i2 < n and 0 <= j2 and j2 < m))
                continue;
            if(!ok(cur.i,cur.j,i2,j2, cur.h))
                continue;
            int timereq = time(cur.i,cur.j,i2,i2, cur.h);
            state ncur = {i2,j2,max(cur.h - (10*timereq), 0), cur.t + timereq};
            //printf("Pushing (%d,%d,%d,%f)\n", ncur.i, ncur.j, ncur.h, ncur.t);            
            Q.insert(ncur);
        }

    }

    return ans;
}


int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    for (int q = 1; q <= T; q++){
        cin >> h >> n >> m;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> C[i][j];
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> F[i][j];
            }
        }

        cout << "Case #" << q << ": ";
        cout << search();
        cout << '\n';
    }
    return 0;
}

