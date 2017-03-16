#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int T; cin >> T;
  string S;
  for (int i = 0; i < T; i++) {
    cin >> S;
    int n = S.size(), cnt = 0; 
    for (int j = n - 1; j >= 0; j--) {
      if (S[j] == '-') {
	cnt++;
	for (int k = 0; k <= j; k++) {
	  if (S[k] == '-') S[k] = '+';
	  else S[k] = '-';
	}
      }
    }
    printf("Case #%d: %d\n", i + 1, cnt);
  }  
  return 0;
}
