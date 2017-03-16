#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <valarray>
#include <vector>

using namespace std;

int T;
double dp[10000][10000];
int tx,ty,n;
int main()
{
   //freopen("C://input.txt","r",stdin);
    freopen("C://output.txt","w",stdout);
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        scanf("%d%d%d",&n,&tx,&ty);
        printf("Case #%d: ",++cas);
        int num=abs(tx);
        if(ty%2)
        {
            if(num%2==0)
            {
                puts("0.0");
                continue;
            }
        }
        else
        {
            if(num%2)
            {
                puts("0.0");
                continue;
            }
        }
       // cout<<"num="<<num<<endl;
        int cnt;
        if(ty%2==0)
        {
            cnt=(num-1)/2;
            if((num-1)%2)
                cnt++;
        }
        else
        {
            cnt=num/2;
            if(num%2)
            cnt++;
        }
       // cout<<"cnt="<<cnt<<endl;
        int len;
        //len=ty所在行的长度
        if(ty%2==0)
            len=cnt*2+1;
        else
            len=cnt*2;
       // cout<<"len="<<len<<endl;;
        int maxl=len+ty;
        maxl-=2;//小一圈.
        int high=maxl;
        int tot=(1+maxl)*(high)/2;
       // cout<<"tot="<<tot<<endl;
       // cout<<"high="<<high<<endl;
        if(tx==0)
        {
            if(tot+high+2+high+1<=n)
                puts("1.0");
            else
                puts("0.0");
            continue;
        }
        if(tot+ty+1>n)
        {
            puts("0.0");
            continue;
        }
        for(int i=0;i<10000;i++)
            for(int j=0;j<10000;j++)
            dp[i][j]=0.0;

        dp[0][0]=1.0;
        for(int i=0;i<=min((high+1)*2,n-tot);i++)
            for(int l=0;l<=min(i,high+1);l++)
            {
                int r=i-l;
                if(r>high+1)
                    continue;
                if(dp[l][r])
                {
                    if(l==high+1 && r<high+1)
                    {
                        dp[l][r+1]+=dp[l][r];
                        continue;
                    }
                    if(l<high+1 && r==high+1)
                    {
                        dp[l+1][r]+=dp[l][r];
                        continue;
                    }
                    dp[l+1][r]+=dp[l][r]*0.5;
                    dp[l][r+1]+=dp[l][r]*0.5;
                }
            }
        double ans=0.0;
        for(int i=min((high+1)*2,n-tot);i<=min((high+1)*2,n-tot);i++)
            for(int l=0;l<=min(i,high+1);l++)
            {
                int r=i-l;
                if(r>high+1)
                    continue;
                if(dp[l][r])
                {
                    if(tx<0 && l>=ty+1)
                        ans+=dp[l][r];

                    if(tx>0 && r>=ty+1)
                        ans+=dp[l][r];
                }
            }
        printf("%.7f\n",ans);
    }
}
