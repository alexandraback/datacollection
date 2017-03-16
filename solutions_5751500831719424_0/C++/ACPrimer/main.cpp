#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
using namespace std;
const int maxn = 105;
const int inf = 0x3f3f3f3f;
char tr[maxn];
int cnt[maxn][maxn];
int n;
int com(int id,char s[])
{
    char t[maxn];
    int j=0;
    t[j]=s[0];
    cnt[id][j]=0;
    for(int i=0;s[i];)
    {
        while(s[i]==t[j])
        {
            i++;
            cnt[id][j]++;
        }
        t[++j]=s[i];
    }
    t[++j]=0;
    if(id==0)
    {
        strcpy(tr,t);
        return 0;
    }
    return strcmp(tr,t);
}
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int Abs(int x)
{
    if(x<0) return -x;
    return x;
}
int ops(int id)
{
    int a[maxn];
    for(int i=0;i<n;i++) a[i]=cnt[i][id];
    qsort(a,n,sizeof(a[0]),cmp);
    int ans=0;
    for(int i=0;i<n;i++) ans+=Abs(a[i]-a[n/2]);
    return ans;
}
int main()
{
    int T,ncase=0;
    cin>>T;
    while(T--){
        memset(tr,0,sizeof(tr));
        memset(cnt,0,sizeof(cnt));
        cin>>n;
        char s[maxn];
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            if(!flag) continue;
            if(com(i,s)) flag=false;
        }
        if(!flag)
        {
            printf("Case #%d: Fegla Won\n",++ncase);
            continue;
        }
        int ans=0;
        for(int i=0;tr[i];i++) ans+=ops(i);
        printf("Case #%d: %d\n",++ncase,ans);
    }
    return 0;
}

