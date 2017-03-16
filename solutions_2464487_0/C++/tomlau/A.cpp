#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
  int T, N;
  cin >> T;

  for (int t=1; t<=T; t++) {
    long long r, paint;
    cin >> r >> paint;
    
    int result=0;
    while (paint > 0) {
      paint -= (2*r + 1);
      if (paint >= 0) result++;
      r += 2;
   }

    cout << "Case #" << t << ": " << result << endl;
  }
  
  return 0;
}
