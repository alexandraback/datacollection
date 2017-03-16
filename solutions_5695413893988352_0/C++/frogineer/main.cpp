#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

bool comparePair(pair<int, int> first, pair<int, int> second) {
	if(first.first == -1 && first.second == -1) return false;
	int diff1 = abs(first.first - first.second);
	int diff2 = abs(second.first - second.second);
	if(diff1 < diff2) return true;
	else if(diff1 > diff2) return false;
	else if(first.first < second.first) return true;
	else if(first.first > second.first) return false;
	else if(first.second < second.second) return true;
	else return false;
}

pair<int, int> findScore(string c, string j) {
	pair<int, int> lowestDiff = make_pair(-1, -1);
	for(int i = 0; i < c.length(); i++) {
		if(c[i] == '?') {
			for(int digit = 0; digit < 10; digit++) {
				string newC = c;
				newC.replace(i, 1, to_string(digit));
				pair<int, int> poss = findScore(newC, j);
				if(comparePair(lowestDiff, poss) == false) {
					lowestDiff = poss;
				}
			}
			return lowestDiff;
		}
	}
	for(int i = 0; i < j.length(); i++) {
		if(j[i] == '?') {
			for(int digit = 0; digit < 10; digit++) {
				string newJ = j;
				newJ.replace(i, 1, to_string(digit));
				pair<int, int> poss = findScore(c, newJ);
				if(comparePair(lowestDiff, poss) == false) {
					lowestDiff = poss;
				}
			}
			return lowestDiff;
		}
	}
	return make_pair(atoi(c.c_str()), atoi(j.c_str()));
}

string padWithZeros(int num, int length) {
	string s = to_string(num);
	while(s.length() < length) {
		s = "0" + s;
	}
	return s;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
	int t;
	cin >> t;
	for(int caseNum = 1; caseNum <= t; caseNum++) {
		string c, j;
		cin >> c >> j;
		pair<int, int> scores = findScore(c, j);
		cout << "Case #" << caseNum << ": " << padWithZeros(scores.first, (int) c.length())
			<< " " << padWithZeros(scores.second, (int) j.length()) << endl;
	}
	return 0;
}