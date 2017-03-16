#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h> 
using namespace std;

const int LEN = 101; 
int N,M; 
int a[LEN][LEN]; 
vector<int> pos[LEN]; 
int lawn[LEN][LEN]; 
bool done_x[LEN]; 
bool done_y[LEN]; 


void solve(int t) {
    for (int i = 0; i <= 100; i++) {
        pos[i].clear(); 
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            pos[a[i][j]].push_back(i * M + j); 
        }
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) {
            lawn[i][j] = 100; 
        }    
    memset(done_x, 0, sizeof(done_x));
    memset(done_y, 0, sizeof(done_y)); 
    
    bool flag = true; 
    for (int h = 100; h >= 1; h--) {
        for (int i = 0; i < pos[h].size(); i++) {
            int x = pos[h][i] / M; 
            int y = pos[h][i] % M; 
            
            if (lawn[x][y] == a[x][y]) {
                continue; 
            }
            
            if (!done_x[x]) {
                for (int j = 0; j < M; j++) {
                    lawn[x][j] = h;  
                }
            }
            else if (!done_y[y]) {
                for (int k = 0; k < N; k++) {
                    lawn[k][y] = h; 
                }
            }
            else {
                flag = false; 
                break; 
            }
            
            
            /*cout << "H = " << h << endl; 
            cout << pos[h][i] << " " << x << " " << y << endl; 
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < M; k++) {
                    cout << lawn[j][k] << "     "; 
                }
                cout << endl; 
            }
            cout << endl; */
         } 
         for (int i = 0; i < pos[h].size(); i++) {
             int x = pos[h][i] / M; 
             int y = pos[h][i] % M;
             done_x[x] = true; 
             done_y[y] = true; 
         }
         if (!flag) break; 
    }
    
/*    bool flag = true; 
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) {
            if (lawn[i][j] != a[i][j]) {
                flag = false; 
                break; 
            }
        }
 */      
 
    if (flag) {
        cout << "Case #" << t << ": " << "YES" << endl; 
    }
    else {
        cout << "Case #" << t << ": " << "NO" << endl; 
    }
}
int main() {
    int T; 
    cin >> T; 
    for (int i = 0; i < T; i++) {
        cin >> N; 
        cin >> M; 
        for (int j = 0; j < N; j++) 
            for (int k = 0; k < M; k++) 
                cin >> a[j][k]; 
        solve(i+1);
    }
}
