#include <bits/stdc++.h>
/*#include <boost/multiprecision/cpp_int.hpp> */
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define gc getchar_unlocked
#define pp pair<int,int>
#define bigint boost::multiprecision::cpp_int
#define bsize 600
using namespace std;


int main()
{
   int t,r,c,w,cas=1;
   cin>>t;
   while(t--)
   {
       cin>>r>>c>>w;
       int ans=(r-1)*(c/w);
       ans+= (c-1)/w;
       ans+=w;
       
       
       printf("Case #%d: %d\n",cas++,ans);
   }
    
return 0;
}