#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#define ll long long
using namespace std;
const int N=10009;
ll e,r,n,a[N],b[N],c[N];
map<ll,int> tr;
void  init()
{
    scanf("%lld%lld%lld",&e,&r,&n);
    for(int i=0;i<n;i++) scanf("%d",a+i),b[i]=a[i];
//    sort(b,b+n);
//    int cnt=2;
//    tr.clear();
//    tr[b[0]]=1;
//    c[0]=b[0];
//    for(int i=1;i<n;i++)
//    if(b[i]!=b[i-1])
//    {
//        c[cnt]=b[i];
//        tr[b[i]]=cnt++;
//    }
         ll now=e,ans=0;
      for(int i=0;i<n;i++)
      {
          int j=i+1;
          for(;j<n&&a[i]>=a[j];j++);
          if(j==n)
          {
              ans+=now*a[i];
              now=r;
              continue;
          }
          if((now+(j-i)*r)<=e)
          {
             now+=r;
          }else
          {
              if(now>=((now+(j-i)*r)-e))
              {
                  ans+=((now+(j-i)*r)-e)*a[i];
                  now+=-((now+(j-i)*r)-e)+r;
              }else
              {
                  ans+=now*a[i];
                  now=r;
              }
          }
      }
      cout<<ans<<endl;


}
int main()
{

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int w;cin>>w;
    for(int id=1;id<=w;id++)
    {
        printf("Case #%d: ",id);
        init();
    }
//    cout << "Hello world!" << endl;
    return 0;
}
