#include <cstdio>
#include <cstring>
bool judge(char c)
{
    if(c=='a') return 1;
    if(c=='e') return 1;
    if(c=='i') return 1;
    if(c=='o') return 1;
    if(c=='u') return 1;
    return 0;
}
int max0(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    freopen("a.in","r",stdin);
    freopen("b.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        char s[110];
        int n;
        scanf("%s%d",s,&n);
        int ans0 = 0;
        int l = strlen(s);
        for(int i=0; s[i]; i++)
        {
            for(int j=i+n; j<=l; j++)
            {
                int ans = 0;
                int tmp = 0;
                for(int k=i; k<j; k++)
                {
                    if(judge(s[k]))
                    {
                        ans = max0(ans,tmp);
                        tmp = 0;
                    }else tmp++;
                }
                ans = max0(ans,tmp);
                if(ans>=n) ans0++;
            }
        }
        printf("Case #%d: %d\n",cas,ans0);
    }
    return 0;
}
