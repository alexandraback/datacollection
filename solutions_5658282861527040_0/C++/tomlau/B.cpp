#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, t, A, B, K, a, b;

int main(){ 
  cin >> T;
  for (t=1; t<=T; t++) {
    cin >> A >> B >> K;
    int cnt = 0;
    for (a=0; a<A; a++)
      for (b=0; b<B; b++)
        if ((a&b) < K) cnt++;
    cout << "Case #" << t << ": " << cnt << endl;
  }
}

