#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
static int caseNum = 1;

void last(const string& input, ofstream &out) {
	vector<char> win;
	for (int i = 0; i < input.length();i++) {
		if (i == 0) {
			win.push_back(input[i]);
			continue;
		}
		if (input[i] >= *(win.begin())) win.insert(win.begin(), input[i]);
		else win.push_back(input[i]);
	}
	cout << "Case #" << caseNum << ": ";
	for (int i = 0; i < win.size();i++) {
		cout << win[i];
	}
	cout << endl;
	out << "Case #" << caseNum << ": ";
	for (int i = 0; i < win.size();i++) {
		out << win[i];
	}
	out << endl;
}
int main() {
	string temp;
	ifstream file("A-small-attempt0.in");
	ofstream out("output.out");
	int T;
	file >> temp;
	T = stoi(temp);
	if (T >= 1 && T <= 100) {
		while (T != 0) {
			file >> temp;
			last(temp, out);
			T--;
			caseNum++;
		}
	}
	return 0;
}