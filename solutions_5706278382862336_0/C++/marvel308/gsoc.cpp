#include<stdio.h>
#include<math.h>
#define ll long long int
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    int t,l1;
    scanf("%d",&t);
    for(l1=1;l1<=t;l1++)
    {
        //int ans=1,flag=0;
        double x,y,m,n,j=2,i;
        scanf("%lf/%lf",&x,&y);
        ll yo=gcd((ll)x,(ll)y);
        //printf("yo=%d\n",yo);
        x=x/yo;
        y=y/yo;
        int flag=0;
        double ga=1.0;
        for(ga=1.0;ga<=pow(2,40);ga=ga*2)
        {
            if(ga==y)
                flag=1;
            
        }
        if(flag==0)
        {
            printf("Case #%d: impossible\n",l1);
            continue;
        }
        m=x/y;
        double ha=1.0;
        int ans=0;
        while(ans<=40)
        {
          if(m>=ha)
          {
              printf("Case #%d: %d\n",l1,ans);
              break;
          }
          ha=ha/2.0;
          ans++;
        }
    }
    return 0;
}

