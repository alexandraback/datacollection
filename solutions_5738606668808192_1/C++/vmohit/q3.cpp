#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int a[32];
ll facs[13];

void func(int v){
  for(int i=0;i<32;i++)a[i]=0;
  a[0]=1;
  a[15]=1;
  a[16]=1;
  a[31]=1;
  int tmp=v;
  int i=1;
  while(tmp>0){
    a[i]=tmp%2;
    tmp=tmp/2;
    i++;
  }
  for(int i=1;i<15;i++){
    a[16+i]=a[i];
  }
  for(int i=0;i<11;i++)facs[i]=0;
  for(ll i=2;i<=10;i++){
    ll f=1;
    for(int j=31;j>15;j--){
      facs[i]+=f*a[j];
      f=f*i;
    }
  }
}

int main(){
  int qw,we,er;
  cin>>qw>>we>>er;
  cout<<"Case #1: \n";
  for(int i=2;i<502;i++){
    func(i);
    for(int j=0;j<32;j++){
      cout<<a[j];
    }
    for(int j=2;j<=10;j++){
      cout<<" "<<facs[j];
    }
    cout<<endl;
  }
  return 0;
}
