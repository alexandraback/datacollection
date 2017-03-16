#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include "stdio.h"

using namespace std;

int main() {
	int t;
	cin >> t;

	int n;
	string s1[20], s2[20];
	for (int tcount = 1; tcount <= t; ++tcount) {
		cin >> n;

		map<string, int> m1, m2;

		for (int i = 0; i < n; ++i) {
			cin >> s1[i] >> s2[i];
			if (m1.find(s1[i]) == m1.end())
				m1.insert(pair<string, int>(s1[i], 1));
			else
				m1[s1[i]] ++;

			if (m2.find(s2[i]) == m2.end())
				m2.insert(pair<string, int>(s2[i], 1));
			else
				m2[s2[i]] ++;
		}

		for (int i = 0; i < n; ++i) {
			if (m1[s1[i]] == 1)
				m2[s2[i]] = 0;
			if (m2[s2[i]] == 1)
				m1[s1[i]] = 0;
		}

		int count1 = 0, count2 = 0;
		for (map<string, int>::iterator iter = m1.begin(); iter != m1.end(); iter++)
			if (iter->second >= 2)
				++count1;
		for (map<string, int>::iterator iter = m2.begin(); iter != m2.end(); iter++)
			if (iter->second >= 2)
				++count2;

		int result = n;
		for (int i = 0; i < n; ++i) {
			if (m1[s1[i]] == 1 || m2[s2[i]] == 1)
				--result;
		}
		if (count1 > count2)
			result -= count1;
		else
			result -= count2;

		cout << "Case #" << tcount << ": " << result;

		cout << endl;
	}

	return 0;
}