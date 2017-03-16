#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int a[1010];

int main()
{
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    int test;scanf("%d",&test);
    for (int t=1;t<=test;t++)
    {
        int n;scanf("%d",&n);
        int cnt=0;char ch;
        for (ch=getchar();ch<'0'||ch>'9';) ch=getchar();
        for (;ch>='0'&&ch<='9';ch=getchar()) a[cnt++]=ch-48;
        int now=0,ans=0;
        for (int i=0;i<=n;i++)
            if (a[i])
            {
                if (now<i) {ans+=(i-now);now=i;}
                now+=a[i];
            }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
