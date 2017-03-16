#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char s[2000000];
int p[2000000];
int f[300];
inline int find(int x)
{
    if(p[x]==x)
        return x;
    return p[x]=find(p[x]);
}
int main()
{
    freopen("1.in","r",stdin);
    freopen("2.txt","w",stdout);
    int T;
    f['a']=1;
    f['e']=1;
    f['i']=1;
    f['o']=1;
    f['u']=1;
    scanf("%d",&T);
    int cas=0;
    while(T--)
    {
        int n;
        scanf("%s",s);
        scanf("%d",&n);
        int len=strlen(s);
        for(int i=0;i<len;i++)
            p[i]=i;
        int flag=-1;
        int L;
        s[len]='a';
        for(int i=0;i<=len;i++)
        {
            if(flag==-1&&!f[s[i]])
            {
                L=i;
                flag=1;
            }
            if(f[s[i]])
            {
                for(int j=L;j<i;j++)
                    p[j]=i-1;
                flag=-1;
                L=i;
            }
        }
        long long P=0,q=n-1;
        long long last=-1;
        long long ans=0;
        while(P<len&&q<len)
        {
            int fp=find(P);
            int fq=find(q);
            if(fp==fq&&!f[s[P]]&&!f[s[q]])
            {
                ans+=(P-last)*(len-q);
                last=P;
            }
            P++;
            q++;
        }
        printf("Case #%d: %lld\n",++cas,ans);
    }
}
