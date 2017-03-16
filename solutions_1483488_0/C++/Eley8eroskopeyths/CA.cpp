#include<iostream>
#include<cmath>

using namespace std;

int len(int n) {
  return (int) ceil(log10(n));
}

int main() {

  int T,A,B,res,tmp,tmpp;
  cin>>T;
  for(int i=1;i<=T;i++) {
    cin>>A;
    cin>>B;
    res=0;
    for(int k=A;k<B;k++) {
      int l=len(k);
      int arr[l-1];
      for(int j=1;j<l;j++) {
        tmp=k/pow(10,j);
        tmp=tmp+(k%((int)pow(10,j)))*pow(10,l-j);
        arr[j-1]=tmp;
        if(tmp>k&&tmp<=B) {
          bool cont=true;
          for(int m=0;m<j-1&&cont;m++) if(arr[m]==tmp) cont=false;
          if(cont) res++;
        }
      }
    }
    cout<<"Case #"<<i<<": "<<res<<endl;
  }

  return 0;
}
