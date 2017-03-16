#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
#include<set>
#include<deque>
#include<queue>
#include<map>
#include<climits>
#include<string>
#include<stack>
#include<sstream>

using namespace std;
int dp[2000005];
int x[1000005];
int ind[1000005];


char s[1000005];
int n;

bool isvowel(char ch){
    if(ch=='a' ||ch=='e' ||ch=='i' ||ch=='o' ||ch=='u')return 1;
    return 0;    
}                
                 
int main(){      
    
    int k;
    int tc;
    cin>>tc;
    
    for(int caso=1;caso<=tc;caso++){
        long long gainor=0;
        
        scanf("%s",s);
        n=strlen(s);
        scanf("%d",&k);
        
        
        
        memset(x,0,sizeof(x));
        memset(ind,-1,sizeof(ind));
        
        for(int i=n-1;i>=0;i--){
            if(!isvowel(s[i]))
                x[i]=1+x[i+1];
        }
        
        for(int i=n-1;i>=0;i--){
            if(x[i]>=k){
                ind[i]=i;
            }else{
                ind[i]=ind[i+1];    
            }
        }
        
        for(int i=0;i<n;i++){
            if(ind[i]==-1)break;
            gainor+=n-k-ind[i]+1;
        }
        
        
        cout<<"Case #"<<caso<<": "<<gainor<<endl;    
    }
    
    
    return 0;
}
