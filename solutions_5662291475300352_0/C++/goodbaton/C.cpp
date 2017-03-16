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
#include <list>

typedef long long ll;
using namespace std;
#define INF (int)2e9
#define LLINF (ll)4e18
#define mod 1000000007
#define SIZE 100000


int calc(){
    int ans=0,N,D[SIZE],H[SIZE],M[SIZE];
    
    scanf("%d",&N);
    
    for(int i=0;i<N;i++){
        scanf("%d%d%d",&D[i],&H[i],&M[i]);
        
    }
    
    if(N==1){
        if(H[0]==2){
            D[1]=D[0];
            M[1]=M[0]+1;
        }else{
            return 0;
        }
    }
    
    ll m=0,minN;
    
    if(M[1]==M[0]) return 0;
    
    if(M[1]>M[0]) minN=0;
    else minN=1;
    
    while(1){
        
        m+=M[minN];
        
        if(m>M[!minN]){
            D[!minN]++;
            m-=M[!minN];
            
            if(min(D[0],D[1])>=360){
                if(max(D[0],D[1])>=720) return 1;
                else return 0;
            }
        }
        
        if(m==M[!minN]){
            D[!minN]++;
            m-=M[!minN];
        }
        
        D[minN]++;
        
        if(min(D[0],D[1])>=360){
            if(max(D[0],D[1])>=720) return 1;
            else return 0;
        }
        
    }
    
    return 0;
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    for(int i=1;i<=T;i++){
        printf("case #%d: %d\n",i,calc());
        cerr << i << endl;
    }
    
    return 0;
}
