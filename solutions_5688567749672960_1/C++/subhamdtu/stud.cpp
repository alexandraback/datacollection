#include<bits/stdc++.h>
#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define p(n) printf("%d\n",n)
#define ll long long
#define pb push_back
#define mp make_pair

#define LN 21
ll mod=1000000007;
using namespace std;

ll rever(ll num)
{
    int tmp[15];
    int dig = 0;
    while(num>0)
    {
      tmp[dig++]=num%10;
      num=num/10;
    }
    ll ans=0;
    for(int i=0;i<dig;++i)
    ans=ans*10+tmp[i];

    return ans;
}

ll calc(int i)
{
    ll req = 1;
    for(int p = 1;p<=i-1;++p)
        req=req*10;
    ll act = req/10;

    ll mina  = req-act;
    ll va=0;
    for(int p=1;p<=i-2;++p)
    {
        va=va*10+9;
        ll  tans =va;
        int digl = i-1-p;
        ll tva = va;
        for(int j=1;j<=digl;++j)
            tva=tva*10;
        tva+=1;

        tans+=1;
        tans+=(req-tva);
        mina = min(mina,tans);
    }
    return mina;

}

int main()
{

   int t,i,p,j;
   ll n ;
   cin>>t;

   for(p = 1 ;p<=t;++p)
   {
    cin>>n;
    printf("Case #%d: ",p);
    ll ans = 0;
    ll tmp = n;
    int dig = 0;
    int ar[16];
    ll dp[16];
    while(tmp>0)
    {
        ar[dig++]=tmp%10;
        tmp=tmp/10;
    }
    dp[1] = 0;
     dp[2] = 10;
     dp[3] = 29 ;
     for(i = 4;i<=dig;++i)
    dp[i] = dp[i-1]+calc(i);
    ans  = dp[dig];

    int firdig = ar[dig-1];
     if(dig==1)
        cout<<n<<endl;
     else
     {
        ll num = 1;
        for(i=1;i<=dig-1;++i)
            num = num *10;

         ll  mina = n-num;
         ll val = 0;
         for(i=dig-1;i>=1;--i)
         {
           ll tans = 0;

            val = val*10 + ar[i];
            int digl = i;
            ll tval = val;

            for(j = 1;j<=digl;++j)
                tval = tval*10;
            tval+=1;

            if(tval<=n)
            {
            tans = rever(val)+1+n-tval;
            mina = min(mina,tans);
            }
            else
            {
            tval = val-1;
            for(j = 1;j<=digl;++j)
                tval = tval*10;
                tval+=1;
             tans = rever(val-1)+1+n-tval;
             mina = min(mina,tans);
            }
         }
          ans = ans+mina;
          cout<<ans<<endl;
       }
     }



    return 0;
}
