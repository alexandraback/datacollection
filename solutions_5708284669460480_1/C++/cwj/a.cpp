#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int T,K,L,S;

char kb[110],tg[110];

int tran[110][110];
double dp[110][110][110];
int h[110][110];

void st()
{
    memset(tran,0,sizeof(tran));
    for(int i=1;i<=K;i++)
    {
        if(kb[i]==tg[1]) tran[0][i]=1;
    }
    for(int i=1;i<=L;i++)
    {
        int k=i-1;
        while(k>0)
        {
            k=tran[k][0];
            if(tg[i]==tg[k+1])
            {
                tran[i][0]=k+1;
                break;
            }
        }
        for(int j=1;j<=K;j++)
        {
            if(kb[j]==tg[i+1]) tran[i][j]=i+1;
            else
            {
                int k=i;
                while(k>0)
                {
                    k=tran[k][0];
                    if(kb[j]==tg[k+1])
                    {
                        tran[i][j]=k+1;
                        break;
                    }
                }
            }
        }
    }
    memset(dp,0,sizeof(dp));
}

double eps=0.000000000001;

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    cin>>T;
    for(int ca=1;ca<=T;ca++)
    {
        cin>>K>>L>>S;
        cin>>kb>>tg;
        for(int i=K;i>=1;i--) kb[i]=kb[i-1];
        for(int i=L;i>=1;i--) tg[i]=tg[i-1];
        tg[L+1]='1';
        st();
        int cwj=0;
        dp[0][0][0]=1.0;
        for(int i=0;i<S;i++)
        {
            for(int j=0;j<=L;j++)
            {
                for(int k=0;k<=i;k++)
                {
                    for(int w=1;w<=K;w++)
                    {
                        double prob=1.0/(double(K));
                        int ss=tran[j][w];
                        if(ss<L)
                        {
                            dp[i+1][ss][k]+=(dp[i][j][k]*prob);
                        }
                        else
                        {
                            dp[i+1][ss][k+1]+=(dp[i][j][k]*prob);
                        }
                    }
                }
            }
        }
        double ep=0;
        for(int i=0;i<=L;i++)
        {
            for(int j=1;j<=S;j++)
            {
                ep+=(dp[S][i][j]*(double(j)));
            }
        }
        memset(h,-1,sizeof(h));
        h[0][0]=0;
        for(int i=0;i<S;i++)
        {
            for(int j=0;j<=L;j++)
            {
                if(h[i][j]==-1) continue;
                for(int k=1;k<=K;k++)
                {
                    int ss=tran[j][k];
                    if(ss<L)
                    {
                        h[i+1][ss]=max(h[i+1][ss],h[i][j]);
                    }
                    else
                    {
                        h[i+1][ss]=max(h[i+1][ss],h[i][j]+1);
                    }
                }
            }
        }
        for(int i=0;i<=L;i++)
        {
            cwj=max(cwj,h[S][i]);
        }
        double ans=((double)(cwj))-ep;
        printf("Case #%d: %.10f\n",ca,ans);
        //cout<<"Case #"<<ca<<": "<<ans<<endl;
    }
    return 0;
}
