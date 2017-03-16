#include <iostream>
using namespace std;
#define ll long long

int arr[10];

void func(ll a){
  ll tmp=a;
  while(tmp>0){
    arr[tmp%10]=1;
    tmp=tmp/10;
  }
}

int main(){
  int Te;
  cin>>Te;
  for(int te=1;te<=Te;te++){
    for(int i=0;i<10;i++){
      arr[i]=0;
    }
    ll n;
    cin>>n;
    if(n==0){
      cout<<"Case #"<<te<<": "<<"INSOMNIA\n";
    }
    else{
        ll v=n; int fl=0,j;
        while(true){
          func(v);
          fl=1;
          for(j=0;j<10;j++){
            if(arr[j]==0){fl=0; break;}
          }
          if(fl==1){
            cout<<"Case #"<<te<<": "<<v<<endl;
            break;
          }
          v=v+n;
        }
    }
  }
  return 0;
}
