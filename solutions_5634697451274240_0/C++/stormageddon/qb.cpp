#include <iostream>
#include <string>

using namespace std;

int main() {
	int cases=0;
	cin >> cases;
	int caseNum=0;
	string junk;
	getline(cin,junk);
	while (caseNum < cases) {
		caseNum++;
		int flips=0;
		string stack="";
		getline(cin,stack);
		char prev=stack[0];
		for (int i=1; i<stack.size(); i++) {
			if (stack[i]!=prev) flips++;
			prev=stack[i];
		}
		if (prev=='-') flips++;
		cout << "Case #" << caseNum << ": " << flips << endl;
	}
	return 0;
}

