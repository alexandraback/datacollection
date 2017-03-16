#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <bitset>


using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;


string solve(string S) {
	int L = (int) S.size();
	string res = "";

	for (int i = 0; i < L; i++) {
		char cur = S[i];
		if (cur >= res[0]) {
			res = cur + res;
		} else {
			res = res + cur;
		}
	}

	return res;
}

int main() {
	ifstream in ("in.txt");
	ofstream out ("out.txt");

	int T; in >> T;
	string line;
	getline(in, line);

	for (int i = 1; i <= T; i++) {
		getline(in, line);

		string res = solve(line);

		out << "Case #" << i << ": " << res << endl;
	}

	return 0;
} 