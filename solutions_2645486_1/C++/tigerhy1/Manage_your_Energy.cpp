#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h> 
#include <sstream>
using namespace std; 

typedef long long llong; 

const int MAX_LEN = 10001; 

llong E, R, N; 
llong v[MAX_LEN]; 


int find_max(int a, int b) {
    int ret = -1;
    int pos = -1;  
    for (int i = a; i <= b; i++) {
        if (v[i] > ret) {
            ret = v[i]; 
            pos = i; 
        }
    }
    return pos; 
}

void init() {
    
}

llong cal(int a, int b, llong b_E, llong e_E) {
    if (a > b) {
        return 0; 
    }
    llong ret = 0; 
    int pos = find_max(a, b);
    
    llong min_E = e_E - (b-pos+1)*R;
    if (min_E < 0) {
        min_E = 0; 
        ret += cal(pos+1, b, R, e_E); 
    }       
    
    llong max_E = b_E + (pos-a)*R; 
    if (max_E > E) {
        max_E = E;  
        ret+= cal(a, pos-1, b_E, E); 
    }
    
    if (max_E - min_E > 0) {
       ret += (max_E - min_E)*v[pos];
    } 
    
    return ret; 
}

void solve(int cas) {
    llong res = cal(0, N-1, E, 0);
    cout << "Case #" << cas << ": " << res << endl; 
}

int main() {
    int T; 
    cin >> T; 
    for (int i = 0; i < T; i++) {
        cin >> E >> R >> N; 
        for (int j = 0; j < N; j++)
            cin >> v[j]; 
        solve(i + 1); 
    }
    //system("pause"); 
}
