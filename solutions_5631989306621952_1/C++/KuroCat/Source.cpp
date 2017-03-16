#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

int main() {
	ifstream in("A-large.in");
	ofstream out("largeoutput.txt");
	int caseNum;
	in >> caseNum;
	for (int i = 1; i <= caseNum; ++i) {
		string str;
		string res = "";
		in >> str;
		int len = str.length();
		res += str[0];
		for (int j = 1; j < len; ++j) {
			if (str[j] >= res[0]) {
				res = str[j] + res;
			}
			else {
				res = res + str[j];
			}
		}
		out << "Case #" << i << ": " << res << endl;
	}
	return 0;
}