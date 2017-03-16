#include<iostream>
#include<cstdio>
#include<cstring>
long long dp[32][2][2][2][2][2];
int a,b,k;
long long f(int p1,int z1,int z2,int s,int b1,int b2);
using namespace std;
int main()
{
   // freopen("B-large.in","r",stdin);
   // freopen("B-large.txt","w",stdout);
    int cas;
    cin>>cas;
    for(int q=1;q<=cas;q++)
    {
        memset(dp,-1,sizeof(dp));
        cin>>a>>b>>k;
        a--;
        b--;
        k--;
        long long sol = f(31,0,0,0,0,0);
        cout<<"Case #"<<q<<": "<<sol<<endl;
    }
    return 0;
}
long long f(int p,int z1,int z2,int s,int b1,int b2)
{
     //cout<<p<<' '<<z1<<' '<<z2<<' '<<' '<<s<<' '<<b1<<' '<<b2<<' '<<endl;
    if(p==-1 )return 1;
    long long & ret1 = dp[p][z1][z2][s][b1][b2];

    if(ret1!=-1){return ret1;}
    long long ret = 0;
    int bit1 = (a >> p) & 1;
    int bit2 = (b >> p)& 1;
    int bit3 = (k >> p)& 1;
    if(z1)bit1 = 1;
    if(z2)bit2 = 1;
        for(int i=0;i<=bit1;i++)
            for(int j=0;j<=bit2;j++)
            {
                int res = (i&j);
                if(s)
                {
                    ret+=f(p-1,z1 || (bit1==1 && (i==0)),
                               z2 || (bit2==1 && (j==0)),
                               1,i,j);
                }
                else if( res < bit3)
                {
                    ret+=f(p-1,z1 || (bit1==1 && (i==0)),
                               z2 || (bit2==1 && (j==0)),
                               1,i,j);
                }
                else if(res == bit3)
                {
                    ret+=f(p-1,z1 || (bit1==1 && (i==0)),
                               z2 || (bit2==1 && (j==0)),
                               0,i,j);
                }
            }
//cout<<p<<' '<<z1<<' '<<z2<<' '<<' '<<s<<' '<<b1<<' '<<b2<<' '<<' '<<ret<<endl;
    return ret1 = ret;
}
