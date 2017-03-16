/*
  Google Code Jam 2013
  Round 1C, Problem A
  Coded by Michael Oliver
*/
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;

class Substring {
  public:
	int start, end;
	Substring (int s, int e) : start(s), end(e) {}
	bool operator== (Substring &s) { return (start==s.start && end==s.end); }
};

bool isVowel(char k) {
	return (k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u');
}

bool hasNConsec (int s, int e, int n, string &name) {
	int num = 0;
	for (int i=s; i <= e; i++) {
		if (!isVowel(name[i])) {
			num++;
			if (num >= n) return true;
		} else {
			num = 0;
		}
	}
	return false;
}

unsigned int nValue(string &name, int n) {
	vector<Substring> matches;
	for (int i=0; i < name.length(); i++) {
		for (int j=i+n-1; j < name.length(); j++) {
			if (hasNConsec(i, j, n, name)) {
				Substring sub(i, j);
				matches.push_back(sub);
			}
		}
	}
	return matches.size();
}

int main() {
	int num_cases;
	cin >> num_cases;
	for (int i=1; i <= num_cases; i++) {
		string name;
		int n;
		cin >> name >> n;
		cout << "Case #" << i << ": " << nValue(name, n) << endl;
	}
	return 0;
}
