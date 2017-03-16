#include <iostream>
#include <deque>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	for(int Te = 0; Te < T; ++Te) {
		string S;
		cin >> S;
		deque<char> R;
		for(char c : S) {
			if(R.empty() || c >= R[0]) {
				R.push_front(c);
			} else {
				R.push_back(c);
			}
		}
		string RS(R.begin(), R.end());
		cout << "Case #" << Te + 1 << ": " << RS << "\n";
	}
	
	return 0;
}
