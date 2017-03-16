#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;
long powk(long n,long k);

int main(){
  long  j, k, i, l,m, n, A, AT, B, digits, dig, base;
  long lay, num, C,N, T, S, ans, score, temp, flag;
  long sqfr[5];
  cin >> T;
  j=0;
  sqfr[0]=1;
  sqfr[1]=4;
  sqfr[2]=9;
  sqfr[3]=121;
  sqfr[4]=484;
  sqfr[5]=1001;
  for(i=0;i<T;i++){
    num=0;
    cout<<"Case #"<<i+1<<": ";
    cin >>A>>B;
    j=0;
    while (A>sqfr[j])
      j++;
    k=j;
    while (B>=sqfr[k])
      k++;
    ans = k-j;
  cout <<ans<<"\n";
  }
  return 0;
}
