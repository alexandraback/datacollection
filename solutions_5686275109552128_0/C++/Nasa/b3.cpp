#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1000
int n,a[MAX],c,mn;

int main(){
  int i,j,x,t,u;
  cin>>t; for (u=0; u<t; u++){
    cin>>n;
    for (i=0; i<n; i++){ cin>>a[i]; }
    mn=1000;
    for (j=1; j<=mn; j++){
      c=0;
      for (i=0; i<n; i++) c+=(a[i]-1)/j;
      mn=min(mn,c+j);
    }
    cout<<"Case #"<<(u+1)<<": "<<mn<<endl;
  }
  return 0;
}
