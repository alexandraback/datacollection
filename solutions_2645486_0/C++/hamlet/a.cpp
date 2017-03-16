#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
int n;
int E,R;
int c[100];
int memo[101][101];

int dp(int pos,int energia){
    if(pos==n)return 0;
    if(memo[pos][energia]!=-1)return memo[pos][energia];
    
    int dev=0;
    
    for(int i=0;i<=energia;i++){
        dev=max(dev,c[pos]*i+dp(pos+1,min(E,energia-i+R)));    
    }
    
    memo[pos][energia]=dev;
    return dev;
}

int main(){
    
    int tc;
    cin>>tc;
       
    for(int caso=1;caso<=tc;caso++){
        cin>>E>>R>>n;
        
        for(int i=0;i<n;i++){
            cin>>c[i];     
        }
        
        memset(memo,-1,sizeof(memo));
        cout<<"Case #"<<caso<<": "<<dp(0,E)<<endl;    
    }   
    
    return 0;
} 
