#include <iostream>

using namespace std;

// 9:31

void print2(long long x) {
  int digits[70];
  int n=0;
  while (x!=0) {
    digits[n] = ((x%2)+2)%2;
    x/=2;
    n++;
  }
  for(int i = n-1; i>=0; i--) {
    cout << digits[i];
  }
}

long long convert(long long x, int b) {
  int digits[70];
  int n=0;
  while (x!=0) {
    digits[n] = x%2;
    x/=2;
    n++;
  }
  long long s = 0;
  for(int i = n-1; i>=0; i--) {
    s*=b;
    s+=digits[i];
  }
  return s;
}

bool div(long long x, int b, long long p) {
  int digits[70];
  int n=0;
  while (x!=0) {
    digits[n] = x%2;
    x/=2;
    n++;
  }
  long long s = 0;
  for(int i = n-1; i>=0; i--) {
    s=(b*s)%p;
    s+=digits[i];
  }
  s=s%p;
  return (0==((s+p)%p));
}

long long factor(long long x, int b) {
  long long p=3;
  long long y = convert(x,b);
  
  if (y%2 == 0)
    return 2;
  while (p<40) {
    if (div(x,b,p))
      return p;
    p+=2;
  }
  return y;
}
	       



int main() {
  int T;
  cin >> T;

  cout << "Case #1:" << endl;


  int N;
  int J;
  cin >> N >> J;


  int found = 0;
  long long x = (1<<(N-2));
  x*=2;
  x+=1;

  long long proof[11];
  while (found < J) {
    int b;
    for(b = 2; b <11; b++) {
      long long y = convert(x,b);
      proof[b] = factor(x,b);
      if (y==proof[b])
	break;
    }
    if (b==11) {
      print2(x);
      for(b = 2; b<11; b++) {
	cout << " " << proof[b];
      }
      cout << endl;
      found++;
      //cout << found << endl;
    }
    x+=2;
  }
  return 0;
}
