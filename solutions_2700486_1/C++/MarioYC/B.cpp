#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int G,want;
double memo[1500][1500];

double solve(int pos1, int pos2, int n){
    if(n == -1) return 0;
    
    double &ret = memo[pos1 + 1][pos2 + 1];
    
    if(!(ret == ret)){
        ret = 0;
        
        if(pos1 == 2 * G - 3){
            if(4*G - 4 - (pos2 + 1) == want) ret = 1;
            else ret += solve(pos1,pos2 + 1,n - 1);
        }else if(pos2 == 2 * G - 3){
            if(pos1 + 1 == want) ret = 1;
            else ret += solve(pos1 + 1,pos2,n - 1);
        }else{
            if(pos1 + 1 == want) ret += 0.5;
            else ret += 0.5 * solve(pos1 + 1,pos2,n - 1);
            
            if(4*G - 4 - (pos2 + 1) == want) ret += 0.5;
            else ret += 0.5 * solve(pos1,pos2 + 1,n - 1);
        }
    }
    
    return ret;
}

int main(){
    int T,N,X,Y;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d %d %d",&N,&X,&Y);
        
        G = 1;
        while(2 * (G - 1) * (G) + G + 1 <= N) ++G;
        N -= 2 * (G - 2) * (G - 1) + G;
        
        double ans;
        
        if((abs(X) + Y) / 2 < G - 1) ans = 1;
        else if((abs(X) + Y) / 2 > G - 1) ans = 0;
        else{
            memset(memo,-1,sizeof memo);
            want = X + 2 * (G - 1);
            ans = solve(-1,-1,N);
        }
        
        printf("Case #%d: %.10f\n",tc,ans);
    }
    
    return 0;
}
