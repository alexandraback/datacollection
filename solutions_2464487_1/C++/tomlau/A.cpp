#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
  int T, N;
  cin >> T;

  int max=4096;
  int c=0;
  for (int i=max-1; i>=1; i--)
    if (i%2 == 1) c += i*i;
    else c -= i*i;
  
  for (int t=1; t<=T; t++) {
    long long r, paint;
    cin >> r >> paint;
    
    int result=0;

    while (r < 10000000000000 && paint >= max*r+c) {
      paint -= (max*r + c);
      if (paint >= 0) result += max/2;
      r += max;
    }

    while (paint > 0) {
      paint -= (2*r + 1);
      if (paint >= 0) result++;
      r += 2;
    }

    cout << "Case #" << t << ": " << result << endl;
  }
  
  return 0;
}
