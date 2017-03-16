#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

long long a[1000000]={1ll,4ll,9ll,121ll,484ll,10201ll,12321ll,14641ll,40804ll,44944ll,1002001ll,1234321ll,4008004ll,100020001ll,102030201ll,104060401ll,121242121ll,123454321ll,125686521ll,400080004ll,404090404ll,10000200001ll,10221412201ll,12102420121ll,12345654321ll,40000800004ll,1000002000001ll,1002003002001ll,1004006004001ll,1020304030201ll,1022325232201ll,1024348434201ll,1210024200121ll,1212225222121ll,1214428244121ll,1232346432321ll,1234567654321ll,4000008000004ll,4004009004004ll};
int cas=0;
int main()
{
   freopen("input.txt","r",stdin);
   freopen("out.txt","w",stdout);
   int T;
   cin>>T;
   while(T--)
   {
    int num=0;
    for(int i=0;i<100;i++)
     if(a[i])
         num++;
     else
         break;
     long long l,r,ans=0;
     cin>>l>>r;
     for(int i=0;i<=num;i++)
     {
         if(a[i]<=r && a[i]>=l)
             ans++;
     }
     cout<<"Case #"<<++cas<<": "<<ans<<endl; 
   }
   return 0;
}
