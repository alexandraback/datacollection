#include <iostream>

using namespace std;

int main () {
  int T;
  cin >> T;
  for (int t=1; t<=T; t++) {
    long long A, B, K;

    cin >> A >> B >> K;

    long long sol=0;
    for (int a=0; a<A; a++)
      for (int b=0; b<B; b++)
	if ((a&b)<K) sol++;
    cout << "Case #" << t << ": " << sol << endl;
  };    

  return 0;
};
