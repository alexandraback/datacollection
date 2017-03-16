#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int T;
int A,B,K;
int main(void){
  cin >> T;
  for(int t = 1; t <= T; t++){
    cin >> A >> B >> K;
    int ans = 0;
    for(int a = 0; a < A; a++){
      for(int b = 0; b < B; b++){
	if((a & b) < K) ans++;
      }
    }
    cout << "Case #" << t << ": " << ans << endl;
  }
}
