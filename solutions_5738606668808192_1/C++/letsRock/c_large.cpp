#include <iostream>
#include <algorithm>
#include <vector>

int N, J;
int c = 0;
unsigned long long e[11];
 
using namespace std;

unsigned long long mod_exp (unsigned long long n, unsigned long long e, unsigned long long mod)
{
  if(e == 0) return 1;
  if(e == 1)
    {
      return (n % mod);
    }
  else
    {
      if((e % 2) == 1)
	{
          unsigned long long temp = mod_exp(n, (e-1)/2, mod);
          return ((n * temp * temp) % mod);
	}
      else
	{
          unsigned long long temp = mod_exp(n, e/2, mod);
          return ((temp*temp) % mod); 
	}
    }
}


unsigned long long modExp(unsigned long long b, unsigned long  e, unsigned long long m)
{
  unsigned long long remainder;
  unsigned long long x = 1;

  while (e != 0)
    {
      remainder = e % 2;
      e= e/2;

      if (remainder == 1)
	x = (x * b) % m;
      b= (b * b) % m; // New base equal b^2 % m
    }
  return x;
}


#define CHECK 500
bool isPrime(string val, unsigned long long * d, unsigned int base){

  for(int k=2; k<CHECK; k++){
    unsigned long long sum = 0;
    unsigned long long exp = 0;
    for(int j=val.size() -1; j>=0; j--){
      if(val[j] == '1'){
	if(mod_exp(base,exp,k) != modExp(base, exp,k)) cout << "ne" << endl;
	sum += mod_exp(base,exp,k);
      }
      exp++;
    }
    sum %= k;
    if(sum == 0){
      *d = k;
      return false;
    }
  }
  return true;

}

void generate(int i,string s){
  
 
  if(i == 0) generate(i + 1, s + '1');
  if(i == N - 1) generate(i + 1, s + '1');
  else if(i < N){
    generate(i + 1, s + '0');
    generate(i + 1, s + '1');
  }
  else if( c < J ){
    bool ok = true;
    //unsigned int val[11];
    for(int j = 2; j <= 10; j++){
      e[j] = 0;
      if(isPrime(s,&e[j],j)){ ok = false; break; }
    }
    
    if(ok){
      cout << s;
      for(int j=2; j<=10; j++){
	cout << " " << e[j];
      }
      cout << endl;
      c++;
      if(c==J) exit(0);
    }
  }
}

int main(){

  int T;
  cin >> T;
  cin >> N >> J;
  cout << "Case #1:" << endl;
  generate(0,"");
}
