#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long rev(long long x) {
  long long revx = 0;
  while (x>0) revx=revx*10+(x % 10), x /=10;
  return revx;

};

long long solve(long long n) {
  if (n<=19) return n;
  if (n % 10 == 0) return solve(n-1)+1;
  if (n<=99) {
    return n/10+(n%10)+10;
  }
  long long len=0, x=n;
  while (x>0) x/=10, len++;
  if (len % 2 ==0) {
    long long p=1, len2=len/2;
    while (len2>0) p*=10, len2--;
    long long left = n/p, right = n%p;
    if (left == p/10) {
      return solve(p*p/10) -1 + right + rev(left);
    } else {
      return solve(p*p/10) + right + rev(left);
    }
  } else { // len odd 
    long long p=1, len2=(len-1)/2;
    while (len2>0) p*=10, len2--;
    long long left = n/p/10, mid = (n/p)%10, right = n%p;
    if (left == p/10) {
      return solve(p*p) - 1 + right + rev(left) + mid*p;
    } else {
      return solve(p*p) + right + rev(left) + mid*p;
    }
  };
  return -1;
};

int main() {
  long long T,N;
  cin >> T;
  for (int t=1; t<=T; t++) {
    cin >> N;
    cout << "Case #" << t << ": " << solve(N) << endl;
  };

  return 0;
};
