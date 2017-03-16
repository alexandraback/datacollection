#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define N 11000000
#define LoL __int64
using namespace std;

int cnt[N];
char str[100];

int ok()
{
    int n=strlen(str);
    int m=n/2;
     for (int i=0;i<m;i++)
        if (str[i]!=str[n-i-1])
            return 0;
    return 1;
}

int check(int x)
{
    sprintf(str,"%d",x);
    if (ok()==0)
        return 0;
    LoL num=(LoL)x*x;
    sprintf(str,"%I64d",num);
    return ok();

}



int main()
{
    int i,j,t,n,x,y;
    LoL a,b;

    freopen("C-large-1.in","r",stdin);
    freopen("dataClarge1.out","w",stdout);
    cnt[0]=0;
    cnt[1]=1;
    for (i=2;i<N;i++)
        cnt[i]=cnt[i-1]+check(i);

    scanf("%d",&t);
    int ys=0;
    while (t--)
    {
        scanf("%I64d%I64d",&a,&b);
        //cout<<a<<b<<endl;
        x=sqrt(a);
        y=sqrt(b);
        if ((LoL)x*x<a)
            x++;
        if ((LoL)y*y>b)
            y--;
        //printf("%d %d\n",x,y);
        printf("Case #%d: %d\n",++ys,cnt[y]-cnt[x-1]);
    }

    return 0;
}
