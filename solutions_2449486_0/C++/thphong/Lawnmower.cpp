#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstring>

#define MAXN 100
#define INFTY 1000000000
using namespace std;

int a[MAXN][MAXN];
int b[MAXN][MAXN];
int N, M;

bool check(){
     for(int i=0; i<N; i++)
     for(int j=0; j<M; j++) b[i][j] = MAXN;
     
     for(int k=MAXN; k>=1; k--){           
             
           //row
           for(int i=0; i<N; i++){
               bool ch = 1;
               for(int j=0; j<M; j++){
                     if(k < a[i][j]) ch = 0; 
               }
               if(ch){
                   for(int j=0; j<M; j++){
                        b[i][j] = k;
                   }
               }
           }
           
           //col
           for(int j=0; j<M; j++){
               bool ch = 1;
               for(int i=0; i<N; i++){
                     if(k < a[i][j]) ch = 0; 
               }
               if(ch){
                   for(int i=0; i<N; i++){
                        b[i][j] = k;
                   }
               }
           }
     }
     
     for(int i=0; i<N; i++){
          for(int j=0; j<M; j++){
               if( a[i][j] != b[i][j]) return 0;
          }
     }
           
     return 1;
}

int main () {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);int t;
    cin >> t;
    for(int ca=1; ca<=t; ca++){
        cin >> N >> M;
        for(int i=0; i<N; i++)
             for(int j=0; j<M; j++) cin >> a[i][j];
            
        cout<<"Case #"<<ca<<": ";
        if(check()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
