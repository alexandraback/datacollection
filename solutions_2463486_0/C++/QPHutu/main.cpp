#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>
#include <queue>
#include <vector>
#include <cstdlib>
#include <string>
#define N 10000100
using namespace std;
long long a[N];
int top=0;
void predeal()
{
    for(int i=1;i<1000;i++)
    {
        char ch[30];
        sprintf(ch,"%d",i);
        int len=strlen(ch);
        for(int j=len;j<len*2;j++)
            ch[j]=ch[len*2-j-1];
        ch[len*2]='\0';len*=2;

        long long now=0;
        sscanf(ch,"%I64d",&now);
        now=now*now;
        sprintf(ch,"%I64d",now);
        int n=strlen(ch);
        int find=0;
        for(int j=0;j<n;j++)
            if(ch[j]!=ch[n-1-j])
            {
                find=1;break;
            }
        if(!find)a[top++]=now;
    }
    for(int i=1;i<10000;i++)
    {
        char ch[30];
        sprintf(ch,"%d",i);
        int len=strlen(ch);
        for(int j=len;j<len*2-1;j++)
            ch[j]=ch[len*2-j-2];
        ch[len*2-1]='\0';len=len*2-1;

        long long now=0;
        sscanf(ch,"%I64d",&now);
        now=now*now;
        sprintf(ch,"%I64d",now);
        int n=strlen(ch);
        int find=0;
        for(int j=0;j<n;j++)
            if(ch[j]!=ch[n-1-j])
            {
                find=1;break;
            }
        if(!find)a[top++]=now;
    }
    sort(a,a+top);
//    cout<<top<<endl;
//    for(int i=0;i<top;i++)
//        cout<<a[i]<<" ";cout<<endl;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("output.txt","w",stdout);
    predeal();
    int t,T=0;
    scanf("%d",&t);
    while(t--)
    {
        long long l,r;
        scanf("%I64d%I64d",&l,&r);
        int ans=0;
        for(int i=0;i<top;i++)
            if(a[i]>=l&&a[i]<=r)
                ans++;
//        printf("%I64d %I64d\n",l,r);
        printf("Case #%d: %d\n",++T,ans);
    }
    return 0;
}
