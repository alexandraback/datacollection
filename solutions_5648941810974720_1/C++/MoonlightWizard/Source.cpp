#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <list>
using namespace std;

int main() {
	int t;
	freopen("A-large.in", "r", stdin);
	freopen("A-large-practice.out", "w", stdout);
	cin >> t;
	cin.get();
	for (int i = 0; i < t; i++) {
		string x;
		
		getline(cin, x);
		vector<int> all;
		while (count(x.begin(), x.end(), 'Z') > 0 && x.size() > 0) {
			x.erase(x.find_first_of("Z"),1);
			x.erase(x.find_first_of("E"),1);
			x.erase(x.find_first_of("R"),1);
			x.erase(x.find_first_of("O"),1);
			all.push_back(0);
		}
		while (count(x.begin(), x.end(), 'X') > 0) {
			x.erase(x.find_first_of("S"),1);
			x.erase(x.find_first_of("I"),1);
			x.erase(x.find_first_of("X"),1);
			//x.erase(x.find_first_of("o"));
			all.push_back(6);
		}
		while (count(x.begin(), x.end(), 'G') > 0) {
			x.erase(x.find_first_of("E"),1);
			x.erase(x.find_first_of("I"),1);
			x.erase(x.find_first_of("G"),1);
			x.erase(x.find_first_of("H"),1);
			x.erase(x.find_first_of("T"),1);
			all.push_back(8);
		}
		while (count(x.begin(), x.end(), 'W') > 0) {
			x.erase(x.find_first_of("T"),1);
			x.erase(x.find_first_of("W"),1);
			x.erase(x.find_first_of("O"),1);
			//x.erase(x.find_first_of("o"));
			all.push_back(2);
		}
		while (count(x.begin(), x.end(), 'H') > 0) {
			x.erase(x.find_first_of("T"),1);
			x.erase(x.find_first_of("H"),1);
			x.erase(x.find_first_of("R"),1);
			x.erase(x.find_first_of("E"),1);
			x.erase(x.find_first_of("E"),1);
			all.push_back(3);
		}
		while (count(x.begin(), x.end(), 'U') > 0) {
			x.erase(x.find_first_of("F"),1);
			x.erase(x.find_first_of("O"),1);
			x.erase(x.find_first_of("U"),1);
			x.erase(x.find_first_of("R"),1);
			all.push_back(4);
		}
		while (count(x.begin(), x.end(), 'F') > 0) {
			x.erase(x.find_first_of("F"),1);
			x.erase(x.find_first_of("I"),1);
			x.erase(x.find_first_of("V"),1);
			x.erase(x.find_first_of("E"),1);
			all.push_back(5);
		}
		while (count(x.begin(), x.end(), 'V') > 0) {
			x.erase(x.find_first_of("S"),1);
			x.erase(x.find_first_of("E"),1);
			x.erase(x.find_first_of("V"),1);
			x.erase(x.find_first_of("E"),1);
			x.erase(x.find_first_of("N"),1);
			all.push_back(7);
		}
		while (count(x.begin(), x.end(), 'I') > 0) {
			x.erase(x.find_first_of("N"),1);
			x.erase(x.find_first_of("I"),1);
			x.erase(x.find_first_of("N"),1);
			x.erase(x.find_first_of("E"),1);
			all.push_back(9);
		}
		while (count(x.begin(), x.end(), 'O') > 0) {
			x.erase(x.find_first_of("O"),1);
			x.erase(x.find_first_of("N"),1);
			x.erase(x.find_first_of("E"),1);
			//x.erase(x.find_first_of("o"));
			all.push_back(1);
		}
		sort(all.begin(), all.end());
		cout << "Case #" << i + 1 << ": ";
		for (int i = 0; i < all.size(); i++) {
			cout << all[i];
		}
		cout << endl;
	}
}