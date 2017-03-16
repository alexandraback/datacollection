//Catch me if you can!
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<string>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
using namespace std;

#define big long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int SIZE = 5;
int R, C, M;
bool vis[SIZE][SIZE];
int touched[SIZE][SIZE];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int dir2[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, -1}, {1, 1}, {-1, -1}, {-1, 1}};

bool valid(int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

int arr[SIZE*SIZE];
int cnt;
void go(int r, int c) {
    if(vis[r][c])
        return;
    
    cnt ++;
    vis[r][c] = true;
    if(touched[r][c])
        return;
    
    for(int d = 0 ; d < 8 ; d++){
        int nr = r+dir2[d][0], nc = c+dir2[d][1];
        if(valid(nr, nc))
            go(nr, nc);
    }
}

int main() {
    
    //freopen("/Users/hibrahim/workspace/contest/app/1.in", "rt", stdin);
    freopen("/Users/hibrahim/Downloads/C-small-attempt1.in", "rt", stdin);
    //freopen("/Users/hibrahim/Downloads/B-large.in", "rt", stdin);
    freopen("/Users/hibrahim/workspace/contest/app/app/1.out", "wt", stdout);
    
    int tt; cin >> tt;
    for(int t = 1 ; t <= tt ; t++){
        cerr << t << endl;
        cin >> R >> C >> M;
        cout << "Case #" << t << ":" << endl;
        
        if(M == R*C-1 || !M){
            cout << 'c';
            for(int i = 1 ; i < R*C ; i++){
                if(i%C == 0)cout << endl;
                cout << (!M ? '.' : '*');
            }
            cout << endl;
            continue;
        }
        
        memset(arr, 0, sizeof arr);
        for(int i = R*C-M ; i < R*C ; i++)
            arr[i] = true;
        
        int rr = -1, cc = -1, counter = 0;
        bool sol = false;
        do{
            //cout << counter++ << endl;
            //build touched
            memset(touched, 0, sizeof touched);
            for(int i = 0 ; i < R*C ; i++){
                if(arr[i]) {
                    int r = i/C, c = i%C;
                    for(int d = 0 ; d < 8 ; d++){
                        int nr = r+dir2[d][0], nc = c+dir2[d][1];
                        if(valid(nr, nc))
                            touched[nr][nc] ++;
                    }
                }
            }

            rr = -1;
            for(int i = 0 ; i < R*C ; i++){
                if(!arr[i]) {
                    int r = i/C, c = i%C;
                    if(!touched[r][c]) {
                        rr = r;
                        cc = c;
                        break;
                    }
                }
            }
            if (rr == -1)continue;
            
            memset(vis, 0, sizeof vis);
            cnt = 0;
            
//            if(arr[6] && arr[13] && arr[23]){
//                int bb = 0;
//                bb++;
//            }
            
            go(rr, cc);
            if(cnt == R*C-M){
                sol = true;
                break;
            }
        }while(next_permutation(arr, arr+R*C));
        
        if(!sol) {
            cout << "Impossible" << endl;
        } else {
            for(int i = 0 ; i < R*C ; i++){
                if(i && i%C == 0)cout << endl;
                if(arr[i])cout << "*";
                else if(rr*C+cc == i)cout << "c";
                else cout << ".";
            }
            cout << endl;
        }
    }
    
    return 0;
}

