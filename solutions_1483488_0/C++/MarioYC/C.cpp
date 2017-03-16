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

int cont[2000001];
int d[10];

int rot(int n){
    int sz = 0,ret = n;
    
    while(n != 0){
        d[sz++] = n % 10;
        n /= 10;
    }
    
    for(int i = 0;i < sz;++i){
        if(d[i] != 0){
            int aux = 0;
            
            for(int j = i;j >= 0;--j)
                aux = aux * 10 + d[j];
            
            for(int j = sz - 1;j > i;--j)
                aux = aux * 10 + d[j];
            
            ret = min(ret,aux);
        }
    }
    
    return ret;
}

int main(){
    int T,A,B;
    
    cin >> T;
    
    for(int tc = 1;tc <= T;++tc){
        cin >> A >> B;
        
        memset(cont,0,sizeof cont);
        
        long long ans = 0;
        
        for(int i = A;i <= B;++i){
            int aux = rot(i);
            ans += cont[aux];
            ++cont[aux];
        }
        
        cout << "Case #" << tc << ": " << ans << endl;
    }
    
    return 0;
}
