#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

typedef long long ll;
using namespace std;


int main(){
    int T,Smax,S[1000],ans,cp;
    
    scanf("%d",&T);
    
    
    for(int i=1;i<=T;i++){
        ans=0;
        cp=0;
        scanf("%d",&Smax);
        
        bool f = false;
        
        for(int i=0;i<=Smax;i++){
            scanf("%1d",&S[i]);
            
            if(S[i]>0){
                ans+=max(0,i-cp);
                cp=max(cp,i);
            }
            
            cp+=S[i];
        }
        
        printf("Case #%d: %d\n",i,ans);
        
    }
    
    return 0;
}
