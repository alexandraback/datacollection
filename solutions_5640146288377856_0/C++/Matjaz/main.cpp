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

int R,C,W;
/*
int dp[(1<<20)+5];

int min_moves(int bitmask){
    
    int res=1;
    
    int tmp=C;
    
    for (int i=0;i<C;i++) if ((bitmask&(1<<i))==0) tmp=min(tmp,min_moves(bitmask|(1<<i)));
    res+=tmp;
    
    return res;
    
} */

int main(){
    
    scanf("%d",&T);
    
    for (int case_number=1;case_number<=T;case_number++){
        int R,C,W;
        
        scanf("%d %d %d",&R,&C,&W);
        
        int answer=(R-1)*(C/W);
        
        if (C%W==0) answer=answer+C/W+W-1; else answer=answer+C/W+W;
        
        printf("Case #%d: %d\n",case_number,answer);
        
    }
    
    return 0;
}
