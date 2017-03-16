#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

#include<vector>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

#define SI(x) scanf("%d ",&x)
#define SL(x) scanf("%lld",&x)
#define MXN 102
typedef long long LL;
using namespace std;

int dp[MXN][MXN];
int points[MXN];
int N,S,p;

int solve(int ind,int sleft)
{
    if(ind>=N) return 0;
    if(dp[ind][sleft]!=-1) return dp[ind][sleft];

    int r = 0;

    for(int s1 = 0;s1<=10;s1++)
    {
        for(int s2 = max(0,s1-2);s2<=min(s1+2,10);s2++)
        {
            for(int s3 = max(0,s1-2);s3<=min(s1+2,10);s3++)
            {       
                if(abs(s2-s3)>2) continue;
                if(s1+s2+s3!=points[ind]) continue;
                int m = max(max(abs(s2-s3), abs(s2-s1)),abs(s1-s3));
                int y = (max(max(s1,s2),s3)>=p)?1:0;
                if(m==2)
                {
                    if(sleft>0) r = max(r,y+solve(ind+1,sleft-1));
                }
                else
                {
                    r = max(r,y+solve(ind+1,sleft));  
                }
            }   
        }
    }

    return (dp[ind][sleft] = r);

}


int main()
{
//    freopen("in.in","r",stdin);
    freopen("small-B-output.txt","w",stdout);
    
    int T, tnum = 1;
    SI(T);

    while(T-- >0)
    {
        memset(dp,-1,sizeof dp);
        SI(N); SI(S); SI(p);
        for(int i=0;i<N;i++) SI(points[i]);

        int ans = solve(0,S);
        printf("Case #%d: %d\n",tnum,ans);
        tnum++;
    }


    fclose(stdout);
	return 0;
}
