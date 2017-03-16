#include <iostream>
using namespace std;

#define ll long long

int main(){
  int Te;
  cin>>Te;
  for(int te=0;te<Te;te++){
    ll k,c,s;
    cin>>k>>c>>s;
    ll v=0,f=1;
    for(ll i=0;i<c;i++){
      v=v+f;
      if(i!=(c-1))f=f*k;
    }
    cout<<"Case #"<<te+1<<": ";
    for(ll i=1;i<=k;i++){
      cout<<(i-1)*v+1<<" ";
    }
    cout<<endl;

  }
  return 0;

}
