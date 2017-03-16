#include <iostream>

using namespace std;


int main() {
  int T;
  cin >> T;
  for(int t = 1; t <=T; t++) {
    int K,C,S;
    cin >> K >> C >> S;
    if (K > C*S)
      cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
    else {
      cout << "Case #" << t << ":";
      S = (K-1)/C + 1;
      //      cout << S << endl;
      for(int i = 0; i < S-1; i++) {
	long long n = 0;
	for(int j = i*C; j < (i+1)*C; j++) {
	  n*=K;
	  n+=j;
	}
	n++;
	cout << " " << n;
      }
      long long n = 0;
      for(int j = (S-1)*C; j < K; j++) {
	n*=K;
	n+=j;
      }
      n++;
      cout << " " << n << endl;
    }
  }
  return 0;
}
