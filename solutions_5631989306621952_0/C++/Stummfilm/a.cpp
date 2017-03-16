#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

string solve(string s){
	string result = "";

	result += s[0];

	for(int i = 1; i < s.size(); i++) {
		if(s[i] >= result[0])
			result = s[i] + result;
		else
			result += s[i];
	}

	return result;
}

int main() {
	int t;
	string s;

	cin >> t;

	for(int i = 0; i < t; i++){
		cin >> s;
		cout << "Case #" << (i + 1) << ": " << solve(s) << endl;
	}

	return EXIT_SUCCESS;
}
