#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int x=1; x<=T; x++) {
    int answer = 0, N;
    cin >> N;

    // read topics
    map<string,int> TA,TB;
    vector<string> A(N),B(N);
    for (int i=0; i<N; i++) {
      cin >> A[i] >> B[i];
      TA[A[i]]++, TB[B[i]]++;
    }

    //    cout << "CODE: " << TA["CODE"] << endl;

    // Try to remove all possible subsets
    for (long long S=0; S<(1<<N); S++) {
      bool solution = true;
      int size = 0;
      for (int i=0; i<N; i++)
	if ((S>>i)&1) {
	  size ++;
	  TA[A[i]]--, TB[B[i]]--;
	  if (TA[A[i]]<=0 || TB[B[i]]<=0) solution = false;
	}
      //      if (solution) cout << "solution: " << solution << endl;
      if (solution && size>answer) answer = size;
      for (int i=0; i<N; i++)
	if ((S>>i)&1) TA[A[i]]++, TB[B[i]]++;
    };
    cout << "Case #" << x << ": " << answer << endl;
  };
  return 0;
};
