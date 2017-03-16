#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define X first
#define Y second
using namespace std;
char str[20];
int n;
int jum[1200000];
int rev(int x)
{
    int i=0;

    while(x>=1)
    {
        str[i++]=x%10+'0';
        x/=10;
    }
    str[i]=0;
    int a;
    sscanf(str,"%d",&a);
    //printf("%d\n",a);
    return a;
}
int dp(int idx)
{
    //printf("%d\n",idx);
    if(idx>n)
        return 99999999;
    if(jum[idx]>=0)
        return jum[idx];
    if(idx==n)
        return 0;
    //printf("%d %d\n",idx,rev(idx));
    int b=rev(idx);
    if(b>idx)
        return jum[idx]=min(dp(idx+1),dp(b))+1;
    else
        return jum[idx]=dp(idx+1)+1;
}
int main()
{
    freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,t,i,j,k;
    //printf("%d\n",rev(15));
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        memset(jum,-1,sizeof jum);
        scanf("%d",&n);
        printf("Case #%d: %d\n",t,dp(0));
    }
}

