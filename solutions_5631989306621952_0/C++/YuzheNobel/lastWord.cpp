#include <iostream>
#include <string>
using namespace std;

string lastWord(const string &s) {
	string lastword = "";
	for (char c : s) {
		if (lastword.empty() || c < lastword[0])
			lastword.push_back(c);
		else
			lastword.insert(0, 1, c);
	}
	return lastword;
}

int main() {int T;
    cin>>T;
    for (int i = 1; i <= T; i++) {
    	cout << "Case #" << i << ": ";
    	string s;
    	cin >> s;
    	cout << lastWord(s) << endl;
    }
	return 0;
}