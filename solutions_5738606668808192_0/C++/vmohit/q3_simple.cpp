#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int a[16];
ll facs[13];

void func(int v){
  for(int i=0;i<16;i++)a[i]=0;
  a[0]=1;
  a[7]=1;
  a[8]=1;
  a[15]=1;
  int tmp=v;
  int i=1;
  while(tmp>0){
    a[i]=tmp%2;
    tmp=tmp/2;
    i++;
  }
  for(int i=1;i<7;i++){
    a[8+i]=a[i];
  }
  for(int i=0;i<11;i++)facs[i]=0;
  for(ll i=2;i<=10;i++){
    ll f=1;
    for(int j=15;j>7;j--){
      facs[i]+=f*a[j];
      f=f*i;
    }
  }
}

int main(){
  int qw,we,er;
  cin>>qw>>we>>er;
  cout<<"Case #1: \n";
  for(int i=2;i<52;i++){
    func(i);
    for(int j=0;j<16;j++){
      cout<<a[j];
    }
    for(int j=2;j<=10;j++){
      cout<<" "<<facs[j];
    }
    cout<<endl;
  }
  return 0;
}
