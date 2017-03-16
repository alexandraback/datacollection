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

   int t,i,p,j,r,c,n,w;

   cin>>t;

   for(p = 1 ;p<=t;++p)
   {

    cin>>r>>c>>w;

    printf("Case #%d: ",p);
    int ans = 0;
    int tmp = c/w;
    ans=ans+tmp*(r-1);
    ans = ans+tmp - 1;
    ans =ans+w;
    int left = c - tmp*w;
    if(left>0)
    ans++;

        cout<<ans<<endl;
   }



    return 0;
}
