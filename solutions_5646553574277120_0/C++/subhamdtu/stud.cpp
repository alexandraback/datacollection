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


int main()
{

   int t,i,p,j,r,c,d,v;
   int den[6];

   cin>>t;

   for(p = 1 ;p<=t;++p)
   {

    cin>>c>>d>>v;


    int ans = 0;

     for(i=1;i<=d;++i)
        cin>>den[i];

printf("Case #%d: ",p);

         int sum = 0;
         i = 1;
       while(i<=d)
       {
          if(sum>=v)
            break;
          if(den[i]>sum+1)
          {
           sum=(2*sum+1);
           ans++;
          }
          else
          {
           sum+=den[i];
           i++;
          }
       }

       while(sum<v)
       {
        sum=(2*sum+1);
        ans++;
       }
        cout<<ans<<endl;
   }



    return 0;
}
