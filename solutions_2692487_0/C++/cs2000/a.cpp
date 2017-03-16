#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
using namespace std;  
struct swing{
	int p,x;
    bool operator<(const swing ext) const{
    return (p<ext.p);
    }
};
int main(){
    long long si[101],dp[101][101],xd[101];
    long long a,x,ma,ans;
    ma=1000001;
    int z,i,j,k,l,n,t;
    cin>>t;
    for (z=1; z<=t; ++z){
        cin>>a>>n;
        for (i=0; i<n; ++i)
            cin>>si[i];
        if (a==1){
                  cout<<"Case #"<<z<<": "<<n<<endl;
        }
        else
        {
        sort(si,si+n);
        memset(dp,-1,sizeof dp);
        memset(xd,-1,sizeof xd);
        xd[0]=0;
        dp[0][0]=a;
        for (i=0; i<n; ++i){
            for (j=0; j<=n; ++j){
                if (dp[i][j]!=-1){
                   for (k=0; k+j<=n; ++k){
                       x=dp[i][j];
                       for (l=0; l<k; ++l){
                           x+=x-1;
                           if (x>=ma)
                              x=ma;
                       }
                       if (x>si[i]){
                          x+=si[i];
                          if (x>=ma)
                          x=ma;
                          if (dp[i+1][k+j]==-1 || dp[i+1][k+j]<x)
                             dp[i+1][k+j]=x;
                          if (xd[i+1]==-1 || xd[i+1]>k+j)
                             xd[i+1]=k+j;
                       }
                   } 
                }//end of if
            }
        }
        ans=n;
        for (i=0; i<=n; ++i){
            if (xd[i]+n-i<ans && xd[i]!=-1)
               ans=xd[i]+n-i;
        } 
        cout<<"Case #"<<z<<": "<<ans<<endl;
        }//end of if a==1
    }
    return 0;
}
