#include<stdio.h>

long long int pp[50];

void compute()
{
    long long int xx=1;
    pp[0]=1;
    pp[1]=2;

    int i;
    for(i=2;i<41;i++)
      pp[i]=pp[i-1]*(long long int )2;

}

long long int gcd(long long int a,long long int b)
{
    if(b==0)
      return a;

    return gcd(b,a%b);
}

int check(long long int xx)
{
    return xx && (!(xx&(xx-1)));
}

int main()
{

     freopen("ques4.in","r+",stdin);
     freopen("outques14.out","w+",stdout);


     //freopen("inp1.in","r+",stdin);
     //freopen("out1.out","w+",stdout);

      compute();


      int t;
      scanf("%d",&t);

      int k=0;
      while(t--)
        {
            k++;
            long long int p,q;
            //char cc;
            scanf("%lld/%lld",&p,&q);
            //printf("%lld %lld\n",p,q);

            //long long int ll=2;


            if(q%2 != 0 || p>q)
                {
                    printf("Case #%d: %s\n",k,"impossible");
                    continue;
                }

            long long int xx=gcd(p,q);
            q=q/xx;
            p=p/xx;

            if(!check(q))
                {
                    printf("Case #%d: %s\n",k,"impossible");
                    continue;
                }

            int ans=0;
            int flag=1;
            while(q%2==0 && q>p)
              {
                  if(q%2==1)
                    {
                        flag=0;
                        break;
                    }

                  q=q/2;
                  ans++;
              }

            if(q <= p)
                printf("Case #%d: %d\n",k,ans);
            else
                printf("Case #%d: %s\n",k,"impossible");

        }
      return 0;
}
