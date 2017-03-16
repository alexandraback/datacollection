#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
#define maxn 1005
#define INF 1000000000
#define LL long long
int a[50],b[50],k[50];
int tot;
int getcas0(int a,int b)
{
    if(a==0 && b==0) return 1;
    if(a^b) return 2;
    return 3;
}
int getcas1(int a,int b)
{
    return a&b;
}
LL dfs(int cur,int end)
{
    if(cur < end) return 1;
    if(cur == end)
    {
        if(a[cur]==b[cur] && a[cur]==0) return 1;
        if(a[cur]^b[cur]) return 2;
        if(k[cur]==1) return 4;
        return 3;
    }
    if(k[cur] == 0) return dfs(tot,cur+1)*dfs(cur-1,end)*getcas0(a[cur],b[cur]);
    else return dfs(tot,cur+1)*(getcas0(a[cur],b[cur])*(1<<cur)+getcas1(a[cur],b[cur])*dfs(cur-1,end));
}
int main()
{
    int T,cas=1,A,B,K;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&A,&B,&K);
        A--;B--;K--;
        tot = 0;
        int cnt=0;
        while(A)
        {
            a[cnt++] = A%2;
            A>>=1;
        }
        tot = max(tot,cnt);
        cnt=0;
        while(B)
        {
            b[cnt++] = B%2;
            B>>=1;
        }
        tot = max(tot,cnt);
        cnt=0;
        while(K)
        {
            k[cnt++] = K%2;
            K>>=1;
        }
        tot = max(tot,cnt);
        LL res = 0;
        for(int i=cnt;i>=0;i--)
            res+=dfs(tot,0);
        printf("Case #%d: %lld\n",cas++,res);
    }
    return 0;
}
