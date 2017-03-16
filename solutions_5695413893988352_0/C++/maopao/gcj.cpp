#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
char str1[22];
char str2[22];
int n;
int getlen(int x)
{
    if(x==0)
        return 1;
    int ans=0;
    while(x)
    {
        ans++;
        x/=10;
    }
    return ans;
}
vector<int>ans[3];
void dfs(char str[],int pos,int flag)
{
    if(pos==n)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum=sum*10+str[i]-'0';
        }
        ans[flag].push_back(sum);
        return ;
    }
    if(str[pos]!='?')
        dfs(str,pos+1,flag);
    else
    {
        for(int i=0;i<=9;i++)
        {
            str[pos]='0'+i;
            dfs(str,pos+1,flag);
        }
        str[pos]='?';
    }
}
int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
//    freopen("A-large.in","r",stdin);
//    freopen("A-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        for(int i=0;i<3;i++)
            ans[i].clear();
        scanf("%s%s",str1,str2);
//        printf("%s %s\n",str1,str2);
        n=strlen(str1);
        dfs(str1,0,1);
        dfs(str2,0,2);
        int siz1=ans[1].size();
        int siz2=ans[2].size();
//        for(int i=0;i<siz1;i++)
//            printf("%d\n",ans[1][i]);
//        for(int i=0;i<siz2;i++)
//            printf("\t%d\n",ans[2][i]);
        int v1=0,v2=0,det=1e9;
        for(int i=0;i<siz1;i++)
        {
            for(int j=0;j<siz2;j++)
            {
//                printf("%d")
                if(abs(ans[1][i]-abs(ans[2][j]))<det)
                {
                    det=abs(ans[1][i]-abs(ans[2][j]));
                    v1=ans[1][i];
                    v2=ans[2][j];
                }
                else if(abs(ans[1][i]-abs(ans[2][j]))==det&&ans[1][i]<v1)
                {
                    det=abs(ans[1][i]-abs(ans[2][j]));
                    v1=ans[1][i];
                    v2=ans[2][j];
                }
                else if(abs(ans[1][i]-abs(ans[2][j]))==det&&ans[1][i]==v1&&ans[2][j]<v2)
                {
                    det=abs(ans[1][i]-abs(ans[2][j]));
                    v1=ans[1][i];
                    v2=ans[2][j];
                }
            }
        }
//        printf("%d %d %d\n",v1,v2,det);
        int l1=getlen(v1);
        int l2=getlen(v2);
        printf("Case #%d: ",cas);
        for(int i=0;i<n-l1;i++)printf("0");
        printf("%d ",v1);
        for(int i=0;i<n-l2;i++)printf("0");
        printf("%d\n",v2);
    }
    return 0;
}
