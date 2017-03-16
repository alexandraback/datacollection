#include<cstdio>
#include<cstdlib>
long long gcd(long long fa,long long fb)
{
     if (fa%fb==0) return fb;
     else return gcd(fb,fa%fb);
}
int main()
{
    int T;
    scanf("%d",&T);
    for (int ri=1;ri<=T;ri++)
    {
        long long fa,fb,gc,tfb;
        int bj;
        bj=1;
        scanf("%lld/%lld",&fa,&fb);
        gc=gcd(fa,fb);
        fa/=gc;
        fb/=gc;
        tfb=fb;
        while (tfb%2==0)
        tfb/=2;
        if (tfb!=1)
           printf("Case #%d: impossible\n",ri);
        else
        {
            bj=0;
            while (fa<fb)
            {
                fa*=2;
                bj++;
            }
            printf("Case #%d: %d\n",ri,bj);
        }
        
       // printf("%lld\n",gcd(fa,fb));
    }
}
