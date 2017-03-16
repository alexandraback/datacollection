#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define inf 0x3f3f3f3f
#define N 101
#define M 1001
char s[2000];
int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int T,cas=0,n;
    cin>>T;
    while (T--)
    {
        scanf("%d%s",&n,s);
        int n=strlen(s),cnt=0,ans=0;
        for (int i=0;i<n;i++)
        {
            if (cnt<i)
            {
                ans+=i-cnt;
                cnt=i;
            }
            cnt+=s[i]-'0';
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
}
