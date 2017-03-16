#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

char s[1010];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.out","w",stdout);
    int T;
    scanf("%d",&T);

    for(int ca=1;ca<=T;ca++)
    {
        int n;
        scanf("%d%s",&n,s);

        int cnt=0;
        int ans=0;
        for(int i=0;i<=n;i++)
        {
            if(cnt < i  && s[i]>'0')
                 {ans += i-cnt;
                     cnt = i;
                 }
            cnt += s[i]-'0';
        }
        printf("Case #%d: %d\n",ca,ans);
    }

    return 0;
}
