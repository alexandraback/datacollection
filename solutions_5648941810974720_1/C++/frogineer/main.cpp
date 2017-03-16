#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

string idealOrder[] = {"ZERO", "TWO", "SIX", "EIGHT", "SEVEN", "FIVE", "FOUR", "THREE", "ONE", "NINE"};
int numbers[] = {0, 2, 6, 8, 7, 5, 4, 3, 1, 9};

string findString(string s, string number) {
	string intersection;
	set_intersection(s.begin(), s.end(), number.begin(), number.end(), back_inserter(intersection));
	if(intersection.length() != number.length())
		return "0";
	string difference;
	set_difference(s.begin(), s.end(), number.begin(), number.end(), back_inserter(difference));
	return difference;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int t;
	cin >> t;
	for(int i = 0; i < 10; i++) {
		sort(idealOrder[i].begin(), idealOrder[i].end());
	}
	for(int caseNum = 1; caseNum <= t; caseNum++) {
		string s;
		cin >> s;
		vector<int> number;
		sort(s.begin(), s.end());
		for(int i  = 0; i < 10; i++) {
			string newString = findString(s, idealOrder[i]);
			while(newString != "0") {
				number.push_back(numbers[i]);
				s = newString;
				newString = findString(s, idealOrder[i]);
			}
		}
		sort(number.begin(), number.end());
		cout << "Case #" << caseNum << ": ";
		for(int i = 0; i < number.size(); i++)
			cout << number[i];
		cout << endl;
	}
	return 0;
}