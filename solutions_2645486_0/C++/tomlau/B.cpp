#include <stdio.h>
#include <iostream>
#include <string>

#define zero(x) memset(x, 0, sizeof(x))

using namespace std;

int main()
{
  int T, E, R, N;
  cin >> T;
  int act[10240];
  int m[6][16];

  for (int t=1; t<=T; t++) {
    cin >> E >> R >> N;
    for (int i=0; i<N; i++)
      cin >> act[i];

    zero(m);
    for (int i=N-1; i>=0; i--)
      for (int e=0; e<=E; e++) {
        int m1 = 0, m2 = 0;
        if (e > 0) m1 = m[e-1][i];
        for (int spend=0; spend<=e; spend++) {
          int e_left = min(e-spend+R, E);
          int ms = spend*act[i] + m[e_left][i+1];
          if (ms > m2) m2 = ms;
        }
        m[e][i] = max(m1, m2);
      }

    cout << "Case #" << t << ": " << m[E][0] << endl;
  }
  
  return 0;
}
