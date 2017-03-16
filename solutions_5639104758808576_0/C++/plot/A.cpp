#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

int solve(string s){
	int j = 0;
	int claps = 0;
	int friends = 0;
	for(int i = 0; i < s.size(); i++){
		int x = s.at(i) - '0';
		while(x != 0 && i > claps){
			claps++;
			friends++;
		}
		claps += x;
	}
	return friends;
}

int main() {
	int t, n;
	string s;
	
	cin >> t;
	
	for(int i = 0; i < t; i++){
		cin >> n;
		cin >> s;

		cout << "Case #" << (i + 1) << ": " << solve(s) << "\n";
	}
	
	return EXIT_SUCCESS;
}
//software-properties
