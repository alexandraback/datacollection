#include <iostream>
#include <algorithm>
#include <vector>

int N, J;
int c = 0;
unsigned long long e[11];
 
using namespace std;

bool isPrime(unsigned long long n, unsigned long long * d){
  if(n <= 1) return false;
  else if(n <= 3) return true;
  else if(n % 2 == 0){
    *d = 2;
    return false;
  }
  else if(n % 3 == 0){
    *d = 3;
    return false;
  }
  int i = 5;
  while(i*i <= n){
    if(n % i == 0){ 
      *d = i;
      return false;
    }
    else if(n % (i + 2) == 0){
      *d = i + 2;
      return false;
    }

    i += 6;
  }
  return true;
}

unsigned long long base10(string n, unsigned int base){
  unsigned long long cur = 1;
  unsigned long long val = 0;
  for(int i=n.length() - 1; i>=0; i--){
    val += (n[i] - '0') * cur;
    cur *= base;
  }
  return val;
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
      //val[j] = base10(s,j);
      if(isPrime(base10(s,j),&e[j])){ ok = false; break; }
    }
    
    if(ok){
      cout << s;
      for(int j=2; j<=10; j++){
	cout << " " << e[j];
      }
      cout << endl;
      c++;
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
