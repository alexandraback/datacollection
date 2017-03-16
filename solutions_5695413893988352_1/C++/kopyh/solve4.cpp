//kopyh
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define N 112
using namespace std;
int n,m,sum,res,flag;
char s1[N],s2[N];
long long a,b;
int main()
{
    #ifndef ONLINE_JUDGE
//        freopen("in.in","r",stdin);
//        freopen("out.out","w",stdout);
    #endif
    int i,j,k,cas,T,t,x,y,z;
    scanf("%d",&T);
    cas=0;
    while(T--)
//    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s%s",s1,s2);
        n=strlen(s1);
        m=strlen(s2);
        x=n;y=m;
        if(n>m)
        {
            for(i=1;i<=m;i++)s2[n-i]=s2[m-i];
            for(;i<=n;i++)s2[n-i]='0';
        }
        else if(m>n)
        {
            for(i=1;i<=n;i++)s1[m-i]=s1[n-i];
            for(;i<=m;i++)s1[m-i]='0';
        }
        n=max(n,m);z=0;
        for(i=0;i<n;i++)
        {
            if(s1[i]!='?'&&s2[i]!='?')
            {
                if(!z)
                {
                    if(s1[i]>s2[i])z=1;
                    else if(s2[i]>s1[i])z=2;
                }
                continue;
            }
            else
            {
                if(z)
                {
                    if(z==1)
                    {
                        if(s1[i]=='?')s1[i]='0';
                        if(s2[i]=='?')s2[i]='9';
                    }
                    if(z==2)
                    {
                        if(s1[i]=='?')s1[i]='9';
                        if(s2[i]=='?')s2[i]='0';
                    }
                    continue;
                }
                flag=0;
                for(j=i+1;j<n;j++)
                {
                    if(s1[i]!='?'&&s2[i]!='?')
                    {
                        if(abs(s1[i]-s2[i])>5)
                        {
                            if(s1[i]>s2[i])flag=1;
                            else flag=2;
                            break;
                        }
                        else if(abs(s1[i]-s2[i])==5)continue;
                        else break;
                    }
                }
                if(!flag)
                {
                    if(s1[i]!='?')s2[i]=s1[i];
                    else if(s2[i]!='?')s1[i]=s2[i];
                    else
                    {
                        s1[i]=s2[i]='0';
                    }
                }
                else
                {
                    if(s1[i]!='?')
                    {
                        if(flag==1)
                        {
                            if(s1[i]=='9')s2[i]='9';
                            else s2[i]=s1[i]+1;
                        }
                        else if(flag==2)
                        {
                            if(s1[i]=='0')s2[i]='0';
                            else s2[i]=s1[i]-1;
                        }
                    }
                    else if(s2[i]!='?')
                    {
                        if(flag==2)
                        {
                            if(s2[i]=='9')s1[i]='9';
                            else s1[i]=s2[i]+1;
                        }
                        else if(flag==1)
                        {
                            if(s2[i]=='0')s1[i]='0';
                            else s1[i]=s2[i]-1;
                        }
                    }
                    else
                    {
                        if(flag==1)s1[i]='0',s2[i]='1';
                        else if(flag==2)s1[i]='1',s2[i]='0';
                    }
                }

            }
        }
        s1[n]=s2[n]='\0';
        printf("Case #%d: ",++cas);
        if(n>x)for(i=0;i<=x;i++)s1[i]=s1[i+(n-x)];
        if(n>y)for(i=0;i<=y;i++)s2[i]=s2[i+(n-y)];
        printf("%s %s\n",s1,s2);
    }
    return 0;
}
