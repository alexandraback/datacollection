#include<bits/stdc++.h>
using namespace std;
const int maxn=100+5;
char s[maxn];
int main()
{
    freopen("inB","r",stdin);
    freopen("outB","w",stdout);
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        int n=strlen(s);
        for(int i=n-1;i>=0;i--,n--) if(s[i]!='+') break;
        int ans=0;
        for(int i=0;i<n;i++) if(i==0 || s[i]!=s[i-1]) ans++;
        printf("Case #%d: %d\n",++kase,ans);
    }
}
