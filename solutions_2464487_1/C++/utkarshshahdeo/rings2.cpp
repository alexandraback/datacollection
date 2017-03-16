#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
     freopen("C:\\Users\\Utkarsh\\Desktop\\input.in","r",stdin);
     freopen("C:\\Users\\Utkarsh\\Desktop\\out.txt","w",stdout);
    long long r,c,i,ans,a,b;
    unsigned long long l;
    int t,k;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%lld %llu",&r,&l);
        if(r<1000000000ll)
        {
        a=sqrtl((2*r-1)*(2*r-1)+8*l);
        b=(1-2*r)+a;
        c=b/4;
        printf("Case #%d: %lld\n",k,c);
        }
        else
        {
           c=0;
          ans=0;
          while(1)
          {
            ans=(r+1)*(r+1)-(r*r);
            if(ans>l)
            break;
            l=l-ans;
            r=r+2;
            c++;
          }
          printf("Case #%d: %lld\n",k,c);
        }
    }
    return 0;
}
