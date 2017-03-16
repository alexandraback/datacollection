#include <iostream>
using namespace std;

typedef long long int lli;

lli firstFactor(lli n) {
  for (lli i=2; i*i<=n; ++i) {
    if (n%i == 0)
      return i;
  }
  return 1;
}

lli transform(lli bmap, lli base) {
  lli v=0, p=1;
  while (bmap>0) {
    v += (bmap%2)*p;
    p *= base;
    bmap /= 2;
  }
  return v;
}

int main() {
  int t;
  cin >> t;
  for (int ta=1; ta<=t; ++ta) {
    cout << "Case #" << ta << ":" << endl;
    lli n, j;
    cin >> n >> j; 
    for (lli i = (1<<(n-1))+1; j>0; i+=2) {
      bool prime = false;
      for (lli b=2; !prime && b<=10; ++b) {
        if (firstFactor(transform(i, b)) == 1)
          prime = true;
      }
      if (!prime) {
        j--;
        cout << transform(i, 10);
        for (lli b=2; !prime && b<=10; ++b) {
          cout << ' ' << firstFactor(transform(i, b));
        }
        cout << endl;
      }
    }
  }
}