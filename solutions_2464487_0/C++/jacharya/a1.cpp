#include<iostream>
#include<string>


using namespace std;

int main(){
  long  j,r,t, k, i, l,m, A, B, flag, pin;
  long lay, sum, num, C,N, T, S, p, score;
  string name;
  long matr[4][4];
  cin >> T;
  getline(cin,name);
  name.clear();
  j=0;
  for(i=0;i<T;i++){
    cout<<"Case #"<<i+1<<": ";
 
    cin >>r>>t;

    sum = 0;
    j=0;
    while (sum<=t){
      sum+=(2*r+4*j+1);
      j++;
    }
    cout<<j-1<<"\n";
  }

  return 0;
}
