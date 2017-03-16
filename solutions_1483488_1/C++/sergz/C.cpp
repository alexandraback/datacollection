#include <iostream>
#include <set>
#include <utility>
#include <math.h>

using namespace std;

long
convert(long x) {
  long result = 0;
  int n = 0;
  
  while(x > 0) {
    result += (x%10) << n;
    x /= 10;
    n += 4;
  }
  
  return result;
}

long
decode(long x) {
  long result = 0;
  int n = 1;
  
  while(x > 0) {
    result += n*(x&0xf);
    n *= 10;
    x >>= 4;
  }
  
  return result;
}

int
count_digits(long x) {
  int result = 0;
  
  while(x > 0) {
    result++;
    x /= 10;
  }
  
  return result;
}

int
main() {
  int T;
  
  cin >> T;
  
  for(int i = 1; i <= T; i++) {
    long result = 0;
    set<pair<long, long> > p;
    
    long A, B;
    cin >> A >> B;
    
    for(long j = A; j <= B; j++) {
      int n = count_digits(j);
      long x = convert(j);
      long y = x;
      long b = convert(B);
      
      for(int k = 1; k < n; k++) {
        int d = y&0xf;
        
        y = (d << ((n-1)*4)) + (y >> 4);
        
        if((y > x) && (y <= b)) {
          p.insert(make_pair(x, y));
        }
      }
    }
    
    cout << "Case #" << i << ": " <<  p.size() << endl;
  }
  
  return 0;
}
