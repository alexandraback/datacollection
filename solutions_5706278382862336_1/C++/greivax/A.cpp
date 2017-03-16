#include <cstdio>
#include <iostream>
using namespace std;

long long gcd(long long a, long long b){
  if(b == 0) return a;
  else return gcd(b, a % b);
}

int xavilog(long long a){
  if(a == 1)
    return 0;
  if(a % 2)
    return -1000;
  return 1 + xavilog(a >> 1);
}

int xavilog2(long long a){
  if(a == 1) return 0;
  return 1 + xavilog2(a >> 1);
}

int main(){
  long long P, Q;
  int t;
  cin >> t;
  for(int i = 0; i < t; ++i){
    scanf("%lld/%lld\n",&P, &Q);
    long long g = gcd(P, Q);
    P /= g;
    Q /= g;
    int r = xavilog(Q);
    cout << "Case #" << 1 + i << ": ";
    if(r < 0)
      cout << "impossible" << endl;
    else {
      int q = xavilog2(P);
      cout << r - q << endl;
    }
  }
}
