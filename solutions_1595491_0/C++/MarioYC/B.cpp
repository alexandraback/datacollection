#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int p,t[100],memo[101][101];

int solve(int n, int s){
    if(s == -1) return -1000;
    if(n == -1) return 0;
    
    int &ret = memo[n][s];
    
    if(ret == -1){
        ret = -1000;
        
        for(int i = 0;i <= 10;++i)
            for(int j = 0;j <= i;++j)
                for(int k = 0;k <= j;++k)
                    if(i - k <= 2 && i + j + k == t[n])
                        ret = max(ret,(i >= p? 1 : 0) + solve(n - 1,i - k == 2? s - 1 : s));
    }
    
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    
    int T,N,S;
    
    cin >> T;
    
    for(int tc = 1;tc <= T;++tc){
        cin >> N >> S >> p;
        
        for(int i = 0;i < N;++i)
            cin >> t[i];
        
        memset(memo,-1,sizeof memo);
        
        cout << "Case #" << tc << ": " << solve(N - 1,S) << '\n';
    }
    
    return 0;
}
