#include <iostream>
#include <vector>


using namespace std;

int main() {
  int T,N;
  cin >> T;
  for (int t=1; t<=T; t++) {
    cin >> N;
    vector <long long> D(N),H(N),M(N);
    vector <long long> start, looptime;
    for (int i=0; i<N; i++) {
      cin >> D[i] >> H[i] >> M[i];
      for (int j=0; j<H[i]; j++) {
	start.push_back(D[i]);
	looptime.push_back(M[i]+j);
      }
    }

    int n = start.size(), answer = 0;
    //    for (int i=0; i<n; i++) cout << "hiker " << start[i] << " " << looptime[i] << endl;
    if (n < 2) answer = 0;
    if (n == 2) {
      if (looptime[0]<=looptime[1]) { // #0 fastest
	answer = looptime[1] * (360 - start[1]) < looptime[0] * ( 720 - start[0] ) ? 0 : 1;
      } else { // #1 fastest
	answer = looptime[0] * (360 - start[0]) < looptime[1] * ( 720 - start[1] ) ? 0 : 1;
      }
    } else {
      answer = 42;
    }
      
    cout << "Case #" << t << ": " << answer << endl;
  };
};
