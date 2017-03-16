#include<stdio.h>

void play(int t)
{
    long long a=0,b=0;
    char inp[100];
    int i,cnt=0;
    scanf ("%lld/%lld",&a,&b);
    while(a<b && b%2 == 0)
    {
        b/=2;
        cnt++;
    }

    if (a>=b)a-=b;
    while(b%2 == 0)
    {
        b/=2;
        if (a>=b)a-=b;
    }
    //printf ("%lld %lld\n",a,b);
    if (a!=0)printf ("Case #%d: impossible\n",t);
    else printf ("Case #%d: %d\n",t,cnt);
    //return 0;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("txt.txt","w",stdout);
    int t,i;
    scanf ("%d",&t);
    for(i=0;i<t;++i)play(i+1);
    return 0;
}
