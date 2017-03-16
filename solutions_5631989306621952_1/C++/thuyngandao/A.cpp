#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
	int nTestCases;
	cin >> nTestCases;

	for (int i = 0; i < nTestCases; ++i) {
		string S;
		cin >> S;

		const char* scs = S.c_str();

		vector<char> out;
		out.push_back(scs[0]);
		for (int c = 1; c < S.length(); ++c) {
			 if(scs[c] >= out.at(0)) {
			 	out.insert(out.begin(), scs[c]);
			 } else {
			 	out.push_back(scs[c]);
			 }
		}

		cout << "Case #" << i+1 << ": ";
		for (int c = 0; c < S.length(); ++c) {
			cout << out.at(c);
		}
		cout << endl;	
	}

	return 0;
}