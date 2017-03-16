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

int solve(long long A, int m, int b[]){
    if(A == 1) return m;
    
    int ret = 0;
    
    for(int i = 0;i < m;++i){
        while(A <= b[i]){
            A = 2 * A - 1;
            ++ret;
        }
        A += b[i];
    }
    
    return ret;
}

int main(){
    int T,A,N;
    int b[100];
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d %d",&A,&N);
        
        for(int i = 0;i < N;++i)
            scanf("%d",&b[i]);
        sort(b,b + N);
        
        int ans = N;
        
        for(int i = 0;i < N;++i)
            ans = min(ans,i + solve(A,N - i,b));
        
        printf("Case #%d: %d\n",tc,ans);
    }
    
    return 0;
}
