#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){ 
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;++t){
        map<int, int> M;
        int n;
        scanf("%d", &n);
        for(int i=0;i<(2*n-1);++i){
            for(int j=0;j<n;++j){
                int h;
                scanf("%d", &h);
                if(M.find(h)==M.end()){
                    M[h] = 1;
                }else{
                    M[h] += 1;
                }
            }
        }
        vector<int> sol;
        
        for(map<int, int>::iterator it = M.begin(); it!=M.end(); ++it){
            int h = it->first;
            int cnt = it->second;
            if(cnt%2==1){
                sol.push_back(h);
            }
        }
        sort(sol.begin(), sol.end());
        printf("Case #%d:",t);
        for(int i=0;i<n;++i){
            printf(" %d", sol[i]);
        }
        printf("\n");
    }
    return 0;
}

