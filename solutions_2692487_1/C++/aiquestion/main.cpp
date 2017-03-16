#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int dp[110][110];
int a,n;
int nn[110];
int cmp(int aa,int bb){
    return aa<bb;
}
int main()
{
    //freopen("D:/A-large (3).in","r",stdin);
    //freopen("D:/out.txt","w",stdout);
    int t,i,j;
    cin>>t;
    for(int iii=1;iii<=t;iii++){
        cin>>a>>n;
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++){
            cin>>nn[i];
        }
        sort(nn,nn+n,cmp);
        int c=a;
        for(i=0;i<n+1;i++){
            dp[0][i]=c;
            c+=c-1;
        }
        for(i=0;i<n;i++){
            int c=nn[i];
            int flag=1;
            for(j=0;j<n+1;j++){
                if(dp[i][j]<=c)
                    dp[i+1][j]=0;
                else{
                    if(flag){
                        dp[i+1][j]=dp[i][j]+c;
                        flag=0;
                    }
                    else{
                        dp[i+1][j]=2*dp[i+1][j-1]-1;
                    }

                }
            }
        }
        int ans=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n+1;j++){
                if(dp[i+1][j]>nn[i]){
                    int tmp=n-i-1+j;
                    if(tmp<ans)
                        ans=tmp;
                }
            }
        }
        cout<<"Case #"<<iii<<": "<<ans<<endl;
    }

}
