#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=15000;
char s[maxn];
char ans[maxn];
int main()
{
    freopen("A-small-attempt0 (1).in","r",stdin);
    freopen("A-small-attempt0.in","w",stdout);
    int t,ca=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        printf("Case #%d: ",ca++);
        int n=strlen(s);
        int be=1100,en=1100;
        ans[be]=s[0];
       // be--;
        for(int i=1;i<n;i++)
        {
            if(s[i]>=ans[be])
            ans[--be]=s[i];
            else
            ans[++en]=s[i];
            //cout<<s[i]<<" "<<ans[be]<<endl;
        }
        for(int i=be;i<=en;i++)
        printf("%c",ans[i]);
        printf("\n");
    }
    return 0;
}
