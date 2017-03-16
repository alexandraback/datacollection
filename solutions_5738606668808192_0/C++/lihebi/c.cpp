/**
 * 

1
16 50

1
32 500

1
6 3

Case #1:
100011 5 13 147 31 43 1121 73 77 629
111111 21 26 105 1302 217 1032 513 13286 10101
111001 3 88 5 1938 7 208 3 20 11

 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

/**
 * i => 2-base    0101010
 * set it to the 1-x bit
 */
void get(char *buf, int i) {
  int a = 0;
  for (int ct=2;i!=0;ct+=2) {
    a = i & 1;
    if (a==1) {
      buf[ct] = '1';
      buf[ct+1] = '1';
    }
    i>>=1;
  }
}

void solve(int N, int J) {
  char buf[N+1];
  for (int i=0;i<J;i++) {
    /**
     * reset
     */
    for (int j=0;j<N;j++) buf[j]='0';
    buf[N] = '\0';
    buf[0] = '1';
    buf[1] = '1';
    buf[N-2] = '1';
    buf[N-1] = '1';
    get(buf, i);
    cout << buf << " ";
    cout << "3 4 5 6 7 8 9 10 11" << "\n";
  }
}

int main() {
  int T;
  cin>>T;
  int N;
  int J;
  /**
   * lenght of N, J output jamcoin
   */
  cin >> N >> J;

  cout << "Case #1:\n";
  solve(N, J);
  cout  << "\n";
}
