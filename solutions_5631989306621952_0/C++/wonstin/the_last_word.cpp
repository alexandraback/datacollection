#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

void solve_case(string S, long case_num) {
  	string answer = "";

    for (int i = 0; i < S.length(); ++i) {
      if (i == 0) {
        answer = S[i];
        continue;
      }
      if (S[i] >= answer[0]) {
        answer = S[i] + answer;
      } else {
        answer = answer + S[i];
      }
    }

  	cout << "Case #" << case_num+1 << ": " << answer << endl;
}

int main() {
  	int T;
  	cin >> T;
  	for (int i = 0; i < T; i++) {
		string S;
		cin >> S;
   	 	solve_case(S, i);
  	}
}
