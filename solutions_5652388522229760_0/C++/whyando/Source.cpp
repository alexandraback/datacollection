#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace::std;

ofstream fout("out.txt");
ifstream fin("in.txt");

int T,t;
vector<bool> seen(10, false);

bool allSeen() {
	for (int i = 0; i < 10; i++) {
		if (!seen[i])
			return false;
	}
	return true;
}

void process(long n) {
	if (n == 0) {
		fout << "Case #" << t << ": " << "INSOMNIA" << endl;
		cout << "Case #" << t << ": " << "INSOMNIA" << endl;
		return;
	}

	for (int i = 0; i < 10; i++)
		seen[i] = false;

	for (long i = 1;; i++) {
		string s = to_string(i*n);
		//cout << s << endl;
		for (int j = 0; j < s.length(); j++) {
			int d = s[j] - '0';
			seen[d] = true;
		}
		if (allSeen()) {
			fout << "Case #" << t << ": " << i*n << endl;
			cout << "Case #" << t << ": " << i*n << endl;
			return;
		}
	}
	
}

int main() {	
	
	fin >> T;
	for (t = 1; t <= T; t++) {
		long n;
		fin >> n;
		process(n);		
	}
}

