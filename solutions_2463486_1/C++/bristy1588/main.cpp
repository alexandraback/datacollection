#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
ll A,B;
inline bool checkpal(ll num)
{
    ll r[30];
    if(num< A || num>B)
        return false;
   ll tmp = num; int i =0;
    while(tmp!=0)
    {
       r[i]= tmp%10;
       i++;
       tmp/=10;
    }
    bool fl = true;
    int j;

    for(j = 0; j < (i/2); j++)
    {
        if(r[j]!=r[i-j-1]) fl= false;
    }

    return fl;
}
inline int make_pal(ll id,ll f)
{
  ll  tmp = id;
  ll  now = 0;
  ll  tmp2 = id;
  if(f>0) tmp2/=10;

    while(tmp>f)
    {
        now = now*10 + (tmp2%10);
        tmp2/=10;
        tmp/=10;
        id*=10;
    }

    id +=now;

  ll  k2 = id*id;
    if(checkpal(k2))
        return 1;
    return 0;
}

int main()
{
    int t,tc;

    freopen("C-large-11.in","r",stdin);
    freopen("Sol_C_large-11.out","w",stdout);

    ll ai,bi;
    scanf("%d",&t);
    tc =0;
    while(tc<t)
    {
        tc++;
        cin>>A>>B;

        ai = sqrt(A*1.0)-1;
        ai = min(ai,0ll);
        bi = sqrt(B*1.0)+1;


       ll kk  = bi;
       ll lim = 1;

        while(1)
        {
            if(kk ==0)
                break;
            kk = kk/10;
            lim = lim*10;
        }

        lim = sqrt(lim*1.0);
        lim = lim*10;

       ll ans = 0;
        for(ll i = 1; i <=lim ; i++)
        {
           int a1 = make_pal(i,0ll);
          int  a2 = make_pal(i,9ll);
            ans = ans+a1+a2;
        }

        printf("Case #%d: ",tc);
        cout<<ans<<endl;

    }
    return 0;
}
