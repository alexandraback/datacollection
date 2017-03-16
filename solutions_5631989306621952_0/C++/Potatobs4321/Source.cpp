#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string TheLastWord(string str) {
	string ans;
	ans += str[0];
	for (int i = 1; i < str.size(); ++i) {
		if (str[i] >= ans[0]) {
			ans = str[i] + ans;
		}
		else {
			ans += str[i];
		}
	}
	return ans;
}

int main() {
	ifstream input("A-small-attempt0.in");
	ofstream output("TheLastWord_small_answer.txt");
	string num;
	getline(input, num);
	int n = stoi(num);
	for (int i = 0; i < n; ++i) {
		output << "case #" << i + 1 << ": ";
		getline(input, num);
		output << TheLastWord(num) << endl;
	}
	return 0;
}