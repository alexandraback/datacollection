#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));
#define infi 1000000000
using namespace std;
long long solve(string& first, string & second, int idx) {
		for (int i = 0; i < first.size(); i++) {
		if (first[i] == '?') {
			if (i < idx && second[i] != '?')
				first[i] = second[i];
			else
				first[i] = '0';
		}
		if (second[i] == '?') {
			if (i < idx)
				second[i] = first[i];
			else
				second[i] = '9';
		}
	}
	stringstream ss1, ss2;
	ss1 << first;
	ss2 << second;
	long long f, s;
	ss1 >> f;
	ss2 >> s;
	return f - s;
}
long long my_distance(const string & str1, const string & str2) {
	int comparison = 0;
	int idx;
	for (int i = 0; i < str1.size(); i++)
	{
		if (str1[i] != '?' && str2[i] != '?' && str1[i] != str2[i]) {
			comparison = str1[i] > str2[i] ? 1 : -1;
			idx = i;
			break;
		}
	}
	if (comparison == 0)
		return 0;

	string first = comparison == 1 ? str1 : str2;
	string second = comparison == 1 ? str2 : str1;

	long long res1 = solve(first, second, idx);

	first = comparison == 1 ? str2 : str1;
	second = comparison == 1 ? str1 : str2;
	bool works = false;
	for (int i = idx - 1; i > 0; i--) {
		if (first[i] == '?' && second[i] == '?') {
			first[i] = '1';
			second[i] = '0';
			works = true;
			idx = i;
			break;
		}
		if (first[i] == '?' && second[i] != '9') {
			first[i] = second[i] + 1;
			works = true;
			idx = i;
			break;
		}
		if (second[i] == '?' && first[i] != '0') {
			second[i] = first[i] + 1;
			works = true;
			idx = i;
			break;
		}
	}
	if (works) {
		long long res2 = solve(first, second, idx);
		res1 = min(res1, res2);
	}
	return res1;
}

pair<string, string> solve(const string& str1, const string& str2) {
	string first = str1;
	string second = str2;

	for (int i = 0; i < first.size(); i++)
		{
			long long minm = 1LL << 61;
			string bestf, bests;
			for (int j = 0; j <= 9; j++) {
				for (int k = 0; k <= 9; k++) {
					bool f = false, s = false;
					if (first[i] == '?') {
						first[i] = '0' + j;
						f = true;
					}
					if (second[i] == '?') {
						second[i] = '0' + k;
						s = true;
					}

					long long res = my_distance(first, second);
					if (res < minm) {
						minm = res;
						bestf = first;
						bests = second;
					}
					if (f) first[i] = '?';
					if (s) second[i] = '?';
				}
			}
			first = bestf;
			second = bests;
		}
	return make_pair(first, second);
}

string expand(int x, int size) {
	stringstream ss;
	ss << x;
	string str;
	ss >> str;
	while (str.size() < size) {
		str = "0" + str;
	}
	return str;
}

bool match (int x, const string& mask) {
	string p = expand(x, mask.size());
	for (int i = 0; i < p.size(); i++) {
		if (p[i] != mask[i] && mask[i] != '?')
			return false;
	}
	return true;
}

pair<string, string> bruteForce(const string& str1, const string& str2) {
	int minm = 1000;
	string first, second;
	for (int i = 0 ; i < 1000; i++) {
		if(!match(i, str1)) {
			continue;
		}
		for (int j = 0; j < 1000; j++)
		{
			if (!match(j, str2)) {
				continue;
			}

			if (minm > max(i, j) - min(i, j)) {
				minm = max(i, j) - min(i, j);
				first = expand(i, str1.size());
				second = expand(j, str1.size());
			}
		}
	}
	return make_pair(first, second);
}

int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);
		cerr << testCounter << endl;
		string first, second;

		cin >> first >> second;

		pair<string, string> res1 = solve(first, second);
		/*pair<string, string> res2 = bruteForce(first, second);
		if (res1.first != res2.first || res1.second != res2.second) {
			cerr << first << " " << second << " " << res1.first << " " << res2.first << " " << res1.second << " " << res2.second << endl;
		}*/
		cout << res1.first << " " << res1.second << endl;
	}
	return 0;
}
