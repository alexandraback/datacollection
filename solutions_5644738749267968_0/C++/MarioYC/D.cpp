#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

int N;
double a[1000],b[1000];
bool used[1000];

int main(){
    ios::sync_with_stdio(0);
    
    int TC;
    
    cin >> TC;
    
    for(int tc = 1;tc <= TC;++tc){
        cin >> N;
        
        for(int i = 0;i < N;++i)
            cin >> a[i];
        for(int i = 0;i < N;++i)
            cin >> b[i];
        sort(a,a + N);
        sort(b,b + N);
        
        int sc1 = 0;
        
        for(int i = 0;i < N;++i){
            int aux = 0;
            
            for(int j = 0;j < N - i;++j)
                if(a[N - 1 - j] > b[N - 1 - i - j])
                    ++aux;
            
            sc1 = max(sc1,aux);
        }
        
        int sc2 = 0;
        memset(used,false,sizeof used);
        
        for(int i = 0;i < N;++i){
            int ind = -1;
            
            for(int j = 0;j < N;++j)
                if(!used[j] && b[j] > a[i]){
                    ind = j;
                    break;
                }
            
            if(ind == -1){
                ++sc2;
                
                for(int j = 0;j < N;++j)
                    if(!used[j]){
                        used[j] = true;
                        break;
                    }
            }else used[ind] = true;
        }
        
        cout << "Case #" << tc << ": " << sc1 << " " << sc2 << endl;
    }
    
    return 0;
}
