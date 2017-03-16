#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#define MAXN 100000
#define LL long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
int n,m;
char s[2000];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int T,t,i;
    scanf("%d",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%d %s",&n,s);
        int cnt=0,ans=0;
        for(i=0;i<=n;i++)
        {
            if(cnt>=i)cnt+=s[i]-'0';
            else
            {
                ans+=i-cnt;
                cnt=i;
                cnt+=s[i]-'0';
            }
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
