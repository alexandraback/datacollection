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

int main(){
    ios::sync_with_stdio(0);
    int TC;
    
    cin >> TC;
    
    int N,a[1000],b[1000],done[1000];
    
    for(int tc = 1;tc <= TC;++tc){
        cin >> N;
        
        for(int i = 0;i < N;++i)
            cin >> a[i] >> b[i];
        
        memset(done,0,sizeof done);
        
        int ans = 0,cont = 0;
        
        while(cont != 2 * N){
            ++ans;
            
            bool found = false;
            
            for(int i = 0;i < N && !found;++i){
                if(done[i] == 0 && b[i] <= cont){
                    found = true;
                    done[i] = 2;
                    cont += 2;
                }
                
                if(done[i] == 1 && b[i] <= cont){
                    found = true;
                    done[i] = 2;
                    ++cont;
                }
            }
            
            if(found) continue;
            
            int ind = -1;
            
            for(int i = 0;i < N;++i)
                if(done[i] == 0 && a[i] <= cont && (ind == -1 || b[i] > b[ind]))
                    ind = i;
            
            if(ind == -1) break;
            
            done[ind] = 1;
            ++cont;
        }
        
        if(cont != 2 * N) cout << "Case #" << tc << ": Too Bad\n";
        else cout << "Case #" << tc << ": " << ans << '\n';
    }
    
    return 0;
}
