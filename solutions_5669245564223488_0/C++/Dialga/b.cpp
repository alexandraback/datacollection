#include <cstdio>
#include <cstring>
int d[110],le[30],n,ans;
char s[110][110],ss[110][110];
void dfs(int x,int num,char c)
{
    if (num==n+1)
    {
        ans++;
        return;
    }
    int l,i,tag,lee[26];
    for (i=1;i<=n;i++)
    if (!d[i]&&s[i][0]==c)
    {
        tag=0;
        for (int j=0;j<=strlen(s[i]);j++)
        {
            if (le[s[i][j]-'a'])
            {
                tag=1;
                break;
            }
            if (c==s[i][j])
            {
                continue;
            }
            else
            {
                le[c-'a']=1;
                c=s[i][j];
            }
        }
        if (tag==0)
        {

        }
    }
}
int main()
{
    int t,cc,j,k;
    scanf("%d",&t);
    for (cc=1;cc<=t;cc++)
    {
        int tag=0;
        ans=0;
        scanf("%d",&n);
        for (i=1;i<=n;i++)
        {
            scanf("%s",ss[i]);
            j=k=0;
            s[i][j]==ss[i][j];
            while (j<strlen(ss[i]))
            {
                j++;
                if (ss[i][j]!=ss[i][j-1])
                {
                    k++;
                    s[i][k]=ss[i][j];
                }
            }
            k++;
            s[i][k]='\0';
        }
        for (i=1;i<=n;i++)
        {
            memset(le,0,sizeof le);
            memset(d,0,sizeof d);
            char c='\0';
            for (int j=0;j<strlen(s[i]);j++)
            {
                if (le[s[i][j]-'a'])
                {
                    tag=1;
                    break;
                }
                if (c=='\0')
                    c=s[i][j];
                else if (si[i][j]==c)
                    continue;
                else
                {
                    le[c-'a']=1;
                    c=s[i][j];
                }
            }
            if (tag==1)
                break;
            d[i]=1;
            dfs(i,1,c);
        }
        printf("Case #%d: %d\n",cc,ans);
    }
    return 0;
}
