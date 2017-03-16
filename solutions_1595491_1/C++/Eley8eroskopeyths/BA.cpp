#include<iostream>
#include<cmath>

using namespace std;

int main() {

  int T,N,S,p,res;
  cin>>T;
  for(int i=1;i<=T;i++) {
    cin>>N;
    cin>>S;
    cin>>p;
    int A[N];
    for(int j=0;j<N;j++) {
      cin>>A[j];
      A[j]=A[j];
    }
    res=0;
    for(int j=0;j<N;j++) {
      if(A[j]>=3*p) res++;
      else if(A[j]>=3*p-2&&p>0) res++;
      else if(A[j]>=3*p-4&&S>0&&p>1) {
        res++;
        S--;
      }
    }

    cout<<"Case #"<<i<<": "<<res<<endl;
  }

  return 0;
}
