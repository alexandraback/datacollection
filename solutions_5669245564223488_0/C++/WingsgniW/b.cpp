#include<cstdio>
#include<cstdlib>
#include<cstring>
int f[15],d[15];
int n,len,bj,ans;
char s[10000];
char tr[11][200];
int ff[26];
void dfs(int no)
{
   // printf("%d\n",ans);
    if (no==n+1)
    {
        memset(ff,0,sizeof(ff));
        bj=0;
        strcpy(s,"");
        for (int i=1;i<=n;i++)
        {
            strcat(s,tr[d[i]]);
        }
        len=strlen(s);
       // printf("%s\n",s);
        for(int i=0;i<len;i++)
        if (ff[s[i]-'a']==0)
        {
            for (int j=i+1;j<len;j++)
            if (s[j]==s[i]&&s[j-1]!=s[i])
            bj=1;
            ff[s[i]-'a']=1;
        }
        if (bj==0)
        {
               ans++;
            //   printf("%d %s\n",ans,s);
        }     
        return;
    }
    for (int i=0;i<n;i++)
    if (f[i]==0)
    {
        d[no]=i;
        f[i]=1;
        dfs(no+1);
        f[i]=0;
    }
}
int main()
{int T;
scanf("%d",&T);
for(int ri=0;ri<T;ri++)
{
    ans=0;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    scanf("%s",tr[i]);
    for (int i=0;i<n;i++)
    {
    
    for (int j=1;j<strlen(tr[i]);j++)
    while (tr[i][j]==tr[i][j-1])
    {    
    for(int k=j;k<strlen(tr[i])-1;k++)
    tr[i][k]=tr[i][k+1];
    tr[i][strlen(tr[i])-1]='\0';
    }
   // printf("%s\n",tr[i]);
    }
    memset(f,0,sizeof(f));
    dfs(1);
    printf("Case #%d: %d\n",ri+1,ans);
}
}
