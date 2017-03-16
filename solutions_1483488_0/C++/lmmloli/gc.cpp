#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 2000005;
bool visit[maxn];
inline int f(int a, int b ,int x)
{
    memset(visit,0,sizeof(visit));
    char s[20] ,tmp[20], p[20];
    int i,val,sum;
    sprintf(s,"%d",x);
    int len=strlen(s);
    sum=0;
    for (i=1;i<len;i++)
    {
       if (s[i]=='0') continue;
       strncpy(tmp,s+i,len);
       strncpy(p,s,i);
       p[i]='\0';
       strcat(tmp,p);
       sscanf(tmp,"%d", &val);
       if (val>=a && val<=b && val>x && !visit[val])
       {
           visit[val]=true;
           sum++;
       }
    }
    return sum;
}
int main()
{
    int t,a,b,i,ans,ca=0;
    freopen("C-small-attempt1.in","r",stdin);
    freopen("gc.out","w",stdout);
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&a,&b);
        ans=0;
        for (i=a;i<=b;i++)
        {
            ans =ans + f(a,b,i);
        }
        printf("Case #%d: %d\n",++ca,ans);
    }
    return 0;
}
