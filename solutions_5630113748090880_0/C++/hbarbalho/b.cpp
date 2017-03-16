#include<iostream>
using namespace std;

int main(){
  long long t,T,N,i,j,h;
  long long vet[2501];
  cin >> T;
  for(t=1;t<=T;++t){
    cin >> N;
    for(i=0;i<=2500;++i)
      vet[i]=0;
    for(i=0;i<2*N-1;++i){
      for(j=0;j<N;++j){
        cin >> h;
        vet[h]+=1;
      }
    }
    cout << "Case #"<<t<<":";
    for(i=0;i<=2500;++i)
      if(vet[i]%2!=0)
        cout << " "<<i;
    cout << endl;
  }
  return 0;
}
