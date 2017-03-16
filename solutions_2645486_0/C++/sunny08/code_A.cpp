#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<math.h>
using namespace std;
int main()
{
  fstream myf,f2;
  myf.open("input.txt",ios::in|ios::app);
  f2.open("output.txt",ios::out);
    int t;
    if(myf.is_open())
    {
        myf>>t;
        //cin>>t;
        //getline(cin,line);
        int test=0;
        while(t--)
        {
            test++;
            int e,r,n;
            myf>>e>>r>>n;
            int ar[n];
            for(int i=0;i<n;i++)
            myf>>ar[i];
            int gain=0;
            int dp[n+1][e+1];
            memset(dp,-1,sizeof(dp));
            dp[0][e]=0;
            for(int i=1;i<=n;i++)
            {
                for(int k=0;k<=e;k++)
                for(int j=0;j<=k;j++)
                {
                    if(dp[i-1][k]>-1)
                    if((k+r-j)>0)
                    dp[i][min((k+r-j),e)]=max(dp[i][min((k+r-j),e)],dp[i-1][k]+(j*ar[i-1]));
                }
            }
            for(int i=0;i<=e;i++)
            gain=max(gain,dp[n][i]);
            f2<<"Case #"<<test<<": ";
            f2<<gain<<"\n";
            cout<<gain<<"\n";
        }
    }
    myf.close();
    f2.close();
    return 0;
}

