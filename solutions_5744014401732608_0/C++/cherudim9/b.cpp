#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

int n, l;
long long M;
long long a[1000];
int ans[1000];

int main(){

  a[1]=1;
  a[2]=1;
  for(int i=2; a[i]*2.0<1.1e18; i++){
    a[i+1]=a[i]*2;
    l=i+1;
    cout<<a[i+1]<<", ";
  }
  cout<<endl<<l<<endl;

  freopen("b.in","r",stdin);
  freopen("b.out","w",stdout);

  int T;
  cin>>T;
  for(int tt=1; tt<=T; tt++){
    printf("Case #%d: ",tt);

    cin>>n>>M;

    if (a[n]<M)
      cout<<"IMPOSSIBLE"<<endl;
    else{
      cout<<"POSSIBLE"<<endl;

      for(int i=n-1; i>=1; i--)
        if (a[i]<=M){
          M-=a[i];
          ans[i]=1;
        }else
          ans[i]=0;

      for(int i=1; i<=n; i++)
        if (i!=n){
          for(int j=1; j<n; j++)
            cout<<(i<j);
          cout<<ans[i];
          cout<<endl;
        }else{
          for(int j=1; j<=n ;j++)
            cout<<0;
          cout<<endl;
        }

    }
  }
  
  return 0;
}
