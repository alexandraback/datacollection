#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#define maxn 1000100
#define ll long long
using namespace std;
int vis[26];
void init()
{
   memset(vis,0,sizeof(vis));
   vis['a'-'a']=vis['e'-'a']=vis['i'-'a']=vis['o'-'a']=vis['u'-'a']=1;
}
char str[maxn];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w+",stdout);
    init();
    int ncase,time=0;
    scanf("%d",&ncase);
    while(ncase--)
    {
        int n,i,j;
        printf("Case #%d: ",++time);
        scanf("%s%d",str,&n);
        int len=strlen(str);
        int num=0,po=-1;
        ll ans=0;
        for(int i=0;i<len;i++)
        {
            if(vis[str[i]-'a'])
            {
                num=0;
                ans+=po+1;
            }
            else
            {
                num++;
                if(num>=n)
                {
                    po=i-n+1;
                }
                ans+=po+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
