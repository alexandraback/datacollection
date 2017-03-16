#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int ca,cas;
int i,j,k,n,m,ans;
int v[20];
string a[20],b[20];

int main(){

    freopen("c_s.in","r",stdin);
    freopen("c_s.out","w",stdout);

    scanf("%d",&cas);
    for (ca=1;ca<=cas;ca++){
      scanf("%d",&n);
      ans=0;
      memset(v,0,sizeof(v));
      for (i=1;i<=n;i++) cin>>a[i]>>b[i];
      for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
          for (k=1;k<=n;k++)
            if (i!=j && i!=k && j!=k){
              if (a[i]==a[k] && b[j]==b[k]) v[k]|=1;
            }

      for (i=1;i<=n;i++) ans+=v[i];
      printf("Case #%d: %d\n",ca,ans);


    }


    return 0;
}
