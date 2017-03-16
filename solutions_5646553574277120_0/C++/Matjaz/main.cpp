#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <stdio.h>
using namespace std;


int T;

int main() {
    
    scanf("%d",&T);
    
    for (int case_number=1;case_number<=T;case_number++){
        
        int C,D,V;
        
        scanf("%d %d %d",&C,&D,&V);
        
        int possible[10000];
        
        memset(possible, 0, sizeof(possible));
        
        vector<int> denomination;
        
        for (int i=0;i<D;i++){
            int x;
            scanf("%d",&x);
            denomination.push_back(x);
        }
        
        possible[0]=1;
        
        int new_possible[10000];
        
        for (int i=0;i<denomination.size();i++){
            memset(new_possible, 0, sizeof(new_possible));
            for (int j=0;j<=V;j++) if (possible[j]==1) new_possible[j+denomination[i]]=1;
            for (int j=0;j<=V;j++) if (new_possible[j]==1) possible[j]=1;
        }
        int res=0;
        for (int i=0;i<=V;i++){
            if (possible[i]) continue;
            res++;
            memset(new_possible, 0, sizeof(new_possible));
            for (int j=0;j<=V;j++) if (possible[j]==1) new_possible[j+i]=1;
            for (int j=0;j<=V;j++) if (new_possible[j]==1) possible[j]=1;
            
            
        }
    
        
        
        printf("Case #%d: %d\n",case_number,res);
        
    }
    
    return 0;
}
