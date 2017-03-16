#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[3000];
int main()
{
    freopen("B-small-attempt0 (1).in","r",stdin);
    freopen("B.out","w",stdout);
    int T,ca;
    cin>>T;
    for (ca=1;ca<=T;ca++)
    {
        int n,i,j,t;
        cin>>n;
        memset(a,0,sizeof a);
        for (i=1;i<2*n;i++)
         for (j=1;j<=n;j++)
          {
              cin>>t;
              a[t]++;

          }
        printf("Case #%d: ",ca);
       // for (i=1;i<=10;i++) cout<<a[i]<<endl;
        for (i=1;i<=2500;i++)
        if (a[i]%2==1) cout<<' '<<i;
          cout<<endl;

    }
       fclose(stdout);
       return 0;
}
