#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h> 
using namespace std;

int K,N;
vector<int> keys; 

int type[20]; 
vector<int> in_chest[20]; 

int d[1<<20][201]; 
int q[(1<<20) + 10]; 
int from[1<<20]; 

void solve(int t) {
    for (int i = 0; i <= 200; i++)
        d[0][i] = 0; 
    for (int i = 0; i < keys.size(); i++)
        d[0][keys[i]] ++;       
    int head = 0; 
    int tail = 0; 
    q[0] = 0; 
    memset(from, -1, sizeof(from)); 
    
    while (head <= tail) {
        for (int i = 0; i < N; i++) {
            if (((q[head]|(1<<i)) != q[head]) && d[q[head]][type[i]] > 0) {
                int new_status = q[head]|(1<<i); 
                if (from[new_status] != -1) {
                    continue; 
                }
                
                for (int j = 0; j <= 200; j++)
                    d[new_status][j] = d[q[head]][j]; 
                d[new_status][type[i]]--;
                for (int j = 0; j < in_chest[i].size(); j++) {
                    d[new_status][in_chest[i][j]]++;  
                }
                
                from[new_status] = i; 
                tail++; 
                q[tail] = new_status; 
                if (new_status == (1<<N)-1) {
                    break; 
                }
            }
        }
        head++; 
    }    
    
    vector<int> rec; 
    int tmp = (1<<N)-1; 
    
    if (from[tmp] == -1) {
        cout << "Case #" << t << ": IMPOSSIBLE" << endl; 
        return; 
    }
    
    while (tmp > 0) {
        rec.push_back(from[tmp]);
        tmp -= (1<<from[tmp]); 
    }
    cout << "Case #" << t << ": "; 
    
    for (int i = rec.size()-1; i >= 0; i--) {
        cout << rec[i] + 1 << " "; 
    }
    cout << endl; 
}

int main() {
    int T; 
    cin >> T; 
    for (int i = 1; i <= T; i++) {
        cin >> K; 
        cin >> N; 
        keys.clear(); 
        
        for (int j = 0; j < K; j++) {
            int key; 
            cin >> key; 
            keys.push_back(key); 
        }
        
        memset(type, sizeof(type), 0);
        for (int j = 0; j < N; j++) {
            in_chest[j].clear(); 
        } 
        for (int j = 0; j < N; j++) {
            cin >> type[j]; 
            int cnt; 
            cin >> cnt;
            for (int k = 0; k < cnt; k++) {
                int tmp; 
                cin >> tmp; 
                in_chest[j].push_back(tmp); 
            } 
        }
        solve(i); 
    }
}







