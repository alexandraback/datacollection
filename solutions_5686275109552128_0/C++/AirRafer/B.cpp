

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>


using namespace std;

#define geti(x) scanf("%d", &x)
#define getc(x) scanf("%c", &x)

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))


#define MAXN 1000005

int A[MAXN];
bool T[1000][MAXN];


int dfs(int ed, int level) {
    
    int i1 = 0;
    for(int i=0;i<=ed;i++) {
        if(A[i] > A[i1])
            i1 = i;
    }
    
    int max1 = A[i1];
    if(max1 <= 0)
        return 0;
    if(max1 == 1)
        return 1;
    
    for(int i=0;i<=ed;i++) {
        
        T[level][i] = false;
        if(A[i] > 0) {
            A[i]--;
            T[level][i] = true;
        }
    }
    int min2 = dfs(ed, level+1);
    for(int i=0;i<=ed;i++) {
        
        if(T[level][i])
            A[i]++;
    }
    
    //share
    


    int share = max1/2;
    
    
    int t = A[ed+1];
    A[i1] = max1 - share;
    A[ed+1] = share;
    
    int min1 = dfs(ed+1, level+1);
    
    //recover
    A[i1] = max1;
    A[ed+1] = t;
    
    
    int ans = MIN(min1, min2);
    //M[sig] = ans;
    if(max1 == 9) {
        
        int t = A[ed+1];
        
        A[i1] = 6;
        A[ed+1] = 3;
        
        int min3 = dfs(ed+1, level+1);
        
        A[i1] = 9;
        A[ed+1] = t;
        
        
        ans = MIN(ans, min3);
        
    }
    
    
    return ans+1;
}


int main() {

	freopen("/Users/cheng/Google/ACM/env/b.in", "r", stdin);
    freopen("/Users/cheng/Google/ACM/env/b.out", "w+", stdout);
    
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        
        int ans = 0;
        //memset(A, 0, sizeof(A));
        
        int D;
        cin >> D;
        
        
    
        for(int i=0;i<D;i++) {
            cin >> A[i];
        }

        ans = dfs(D-1, 0);
        
        cout<<"Case #"<<t<<": "<<ans<<endl;
        
        //<<ans<<endl;
       // cout<<D<<endl;
    }
    return 0;
}


