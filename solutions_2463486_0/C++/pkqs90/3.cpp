#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#define  maxn 20000005
#define  ll   long long
using namespace std;
ll x,y,cnt,ans,t;
ll a[400]={1,4,9,121,484,10201,12321,14641,40804,
44944,1002001,1234321,4008004,100020001,102030201,
104060401,121242121,123454321,125686521,400080004,
404090404ll,10000200001ll,10221412201ll,12102420121ll,12345654321ll,
40000800004ll,1000002000001ll,1002003002001ll,1004006004001ll,
1020304030201ll,1022325232201ll,1024348434201ll,1210024200121ll,
1212225222121ll,1214428244121ll,1232346432321ll,1234567654321ll,4000008000004ll,4004009004004ll};
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin>>t;
    for(int k=1;k<=t;k++){
       scanf("%lld%lld",&x,&y);
       //cin>>x>>y;
       ans=0;
       for(int i=0;i<=50;i++)
          if(x<=a[i]&&a[i]<=y)
             ans++;
       printf("Case #%d: %d\n",k,ans);
    }
    //system("pause");
    return 0;
}
