#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;
long powk(long n,long k);

int main(){
  long  j, k, i, l,m, n, A, AT, B, digits, dig, base;
  long lay, num, C,N, T, S, p, score, temp, flag;
  cin >> T;
  j=0;
  for(i=0;i<T;i++){
    num=0;
    cout<<"Case #"<<i+1<<": ";
    cin >>A>>B;
    base=10;
    AT=A;
    while (AT/10>0)
    {
      AT=AT/10;
      base=base*10;
    }
    for (n = A;n<B;n++)
    {
      flag=0;
      digits=10;
      while (digits<B)
      {
	temp = (n%digits)*(base/digits)+n/digits;
	if (temp==n)
	  flag=1;
	if (temp>n&&temp<=B&&flag==0)
	  num++;
	digits*=10;
      }
    }
  cout <<num<<"\n";
  }
  return 0;
}
