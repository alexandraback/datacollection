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
int vis[20][2];
string str[20][2];
string solve(int n)
{
    stack<int>s;
    while(!s.empty())
        s.pop();
    int tmp = n;
    while(tmp)
    {
        s.push(tmp%10);
        tmp /= 10;
    }
    string str;
    while(!s.empty())
    {
        str.push_back(s.top() + '0');
        s.pop();
    }
}
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
        cin>>n;
        for(int i=0;i<n;++i)
        {
            cin>>str[i][0];
            cin>>str[i][1];
        }
        int ans1 = 0, ans2 = 0;
        for(int i=0;i<n;++i)
        {
            int tmp = 0;
            int tmp1 = 0;
            for(int j=0;j<n;++j)
            {
                if(str[i][0] == str[j][0])
                {
                    tmp++;
                }
            }
            for(int j=0;j<n;++j)
            {
                if(str[i][1] == str[j][1])
                {
                    tmp1++;
                }
            }
            ans1 = max(ans1,min(tmp,tmp1));
        }
//        for(int i=0;i<n;++i)
//        {
//            int tmp = 0;
//            for(int j=0;j<n;++j)
//            {
//                if(str[i][1] == str[j][1])
//                {
//                    tmp++;
//                }
//            }
//            ans2 = max(ans2, tmp);
//        }
        printf("Case #%d: ", ++Case);
        printf("%d\n",ans1-1);
    }
    return 0;
}

