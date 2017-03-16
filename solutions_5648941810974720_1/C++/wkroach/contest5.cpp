#include<cstdio>
#include<cstdlib>
#include<time.h>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>

//#include<bits/c++std.h>

#define Size 1000005
#define inf 2e9
#define INF 2e18
#define LL long long int
#define i64 __int64
#define ULL unsigned long long
#define Mod 1000000007
#define pi 4*atan(1)
#define eps 1e-8
#define lson now*2,l,l+(r-l)/2
#define rson now*2+1,l+(r-l)/2+1,r
using namespace std;
int n,m,k;
int ql,qr,pos;
int vis[20];
int main()
{
    #ifndef ONLINE_JUDGE
//        freopen("input.txt","r",stdin);
//        freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE
    int t;
    int x,y,z;
    int Case=0;
    cin>>t;
    while(t--)
//    while(scanf("%d",&n)==1)
    {
        memset(vis,0,sizeof(vis));
        string s;
        cin>>s;
        for(int i=0;i<s.size();++i)
        {
            if(s[i] == 'Z')
            {
                vis[0]++;
            }
            else if(s[i] == 'U')
            {
                vis[4]++;
            }
            else if(s[i] == 'G')
            {
                vis[8]++;
            }
            else if(s[i] == 'W')
            {
                vis[2]++;
            }
            else if(s[i] == 'X')
            {
                vis[6]++;
            }
            else if(s[i] == 'R')
            {
                vis[3]++;
            }
            else if(s[i] == 'S')
            {
                vis[7]++;
            }
        }
        if(vis[4] + vis[0] < vis[3])
        {
            vis[3] = vis[3] - vis[4] - vis[0];
        }
        else
        {
            vis[3] = 0;
        }
        if(vis[6] < vis[7])
        {
            vis[7] = vis[7] - vis[6];
        }
        else
        {
            vis[7] = 0;
        }
        for(int i=0;i<s.size();++i)
        {
            if(s[i] == 'V')
            {
                vis[5]++;
            }
            else if(s[i] == 'O')
            {
                vis[1]++;
            }
            else if(s[i] == 'N')
            {
                vis[9]++;
            }
        }
        if(vis[5] > vis[7])
        {
            vis[5] = vis[5] - vis[7];
        }
        else
        {
            vis[5] = 0;
        }
        if(vis[1] > vis[0] + vis[4] + vis[2])
        {
            vis[1] = vis[1] - vis[0] - vis[4] - vis[2];
        }
        else
        {
            vis[1] = 0;
        }
        if(vis[9] > vis[7] + vis[1])
        {
            vis[9] = (vis[9] - vis[7] - vis[1]) / 2;
        }
        else
        {
            vis[9] = 0;
        }
        printf("Case #%d: ", ++Case);
        for(int i=0;i<10;++i)
        {
            if(vis[i])
            {
                for(int j=0;j<vis[i];++j)
                {
                    printf("%d",i);
                }
            }
        }
        cout<<endl;
    }
    return 0;
}

