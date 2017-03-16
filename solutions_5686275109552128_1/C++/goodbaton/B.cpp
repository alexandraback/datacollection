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
    int T,D,P[1000],ans,Pmax,ANS;
    
    scanf("%d",&T);
    
    
    for(int i=1;i<=T;i++){
        ANS=1000;
        Pmax=0;
        scanf("%d",&D);
        
        for(int j=0;j<D;j++){
            scanf("%d",&P[j]);
            
            Pmax=max(P[j],Pmax);
        }
        
        for(int j=1;j<=Pmax;j++){
            ans=0;
            for(int l=0;l<D;l++){
                
                ans+=(P[l]-1)/j;
                
            }
            
            if(Pmax>=j){
                ans+=j;
            }else{
                ans+=Pmax;
            }
            
            //cerr << j << ":" << ans << endl;
            ANS=min(ANS,ans);
        }
        
        printf("Case #%d: %d\n",i,ANS);
        
    }
    
    return 0;
}
