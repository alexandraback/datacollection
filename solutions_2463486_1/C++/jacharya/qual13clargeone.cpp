#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;
long palindrom(long x);

int main(){
  long  j, k, i, l,m, n, A, AT, B, digits, dig, base;
  long lay, num, C,N, T, S, ans, score, temp, flag;
  long sqfr[1000];
  for (j=0;j<1000;j++)
    sqfr[j]=100000000000001;
  k=0;
  for (j = 1;j<10000000;j++){
    S=j*j;
    if (palindrom(j)==1 && palindrom(S)==1){
      sqfr[k++]=S;
           cout<<"sqfr["<<k-1<<"] = "<<sqfr[k-1]<<" and j is "<< j<< "\n";
    }
  }
  cin >> T;

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
long palindrom(long x){
  long t = x, m = 0;
    do m = m*10 + t%10;
    while(t /= 10);
    if ( m == x)
      return 1;
    else 
      return 0;
}
