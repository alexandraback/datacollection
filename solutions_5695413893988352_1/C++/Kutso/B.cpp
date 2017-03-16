#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <sstream>

using namespace std;

const int NMAX = 100100;

long long bestans = -1;
string bests1, bests2;

long long calc(string s1, string s2) {
	stringstream ss;
	ss << s1 << " " << s2;
	unsigned long long a1, a2;
	ss >> a1 >> a2;
	long long v = a1 - a2;
	return abs(v);
}

void rec(string s1, string s2, int ind) {
	if (ind >= s1.size()) {
		int v = calc(s1, s2);
		if (bestans < 0 || v < bestans || (v == bestans && s1 < bests1) || (v == bestans && s1 == bests1 && s2 < bests2) ) {
			bestans = v;
			bests1 = s1;
			bests2 = s2;
		}
		return;
	}

	int tos1 = s1[ind] == '?' ? 10 : 1;
	int tos2 = s2[ind] == '?' ? 10 : 1;

	for (int i = 0; i < tos1; i++)
		for (int k = 0; k < tos2; k++) {
			string news1 = s1;
			string news2 = s2;
			if (news1[ind] == '?')
				news1[ind] = '0' + i;
			if (news2[ind] == '?')
				news2[ind] = '0' + k;
			rec(news1, news2, ind + 1);
		}
}

void slowsolve(string s1, string s2) {
	bestans = -1;
	bests1 = "";
	bests2 = "";
	rec(s1, s2, 0);
	//cout << bests1 << " " << bests2 << endl;
}



void DFS(string s1, string s2, int comp, int i) {
	if (i >= s1.size()) {
		long long v = calc(s1, s2);
		if (bestans < 0 || v < bestans || (v == bestans && s1 < bests1) || (v == bestans && s1 == bests1 && s2 < bests2)) {
			bestans = v;
			bests1 = s1;
			bests2 = s2;
		}
	//	cout << v << endl;
		return;
	}


	if (s1[i] != '?' && s2[i] != '?') {
		if (comp == 0)
			if (s1[i] < s2[i]) {
				comp = -1;
			}
			else
				if (s2[i] < s1[i])
					comp = 1;
		DFS(s1, s2, comp, i+1);
		return;
	}


	if (s1[i] == '?' && s2[i] == '?') {
		if (comp == 0) {
			s1[i] = s2[i] = '0';
			DFS(s1, s2, 0, i + 1);

			s1[i] = '0'; 
			s2[i] = '1';
			DFS(s1, s2, -1, i + 1);

			s1[i] = '1';
			s2[i] = '0';
			DFS(s1, s2, 1, i + 1);
			return;
		}
		if (comp == -1) {
			s1[i] = '9';
			s2[i] = '0';
		}
		if (comp == 1) {
			s1[i] = '0';
			s2[i] = '9';
		}
		DFS(s1, s2, comp, i + 1);
		return;
	}

	if (s1[i] == '?' && s2[i] != '?') {
		if (comp == 0) {
			s1[i] = s2[i];
			DFS(s1, s2, 0, i + 1);

			if (s2[i] > '0') {
				s1[i] = s2[i] - 1;
				DFS(s1, s2, -1, i + 1);
			}
			if (s2[i] < '9') {
				s1[i] = s2[i] + 1;
				DFS(s1, s2, 1, i + 1);
			}
		}
		if (comp == -1)
			s1[i] = '9';
		if (comp == 1)
			s1[i] = '0';
		DFS(s1, s2, comp, i + 1);
		return;
	}

	if (s2[i] == '?' && s1[i] != '?') {
		if (comp == 0) {
			s2[i] = s1[i];
			DFS(s1, s2, 0, i + 1);

			if (s1[i] > '0') {
				s2[i] = s1[i] - 1;
				DFS(s1, s2, 1, i + 1);
			}
			if (s1[i] < '9') {
				s2[i] = s1[i] + 1;
				DFS(s1, s2, -1, i + 1);
			}
		}
		if (comp == -1)
			s2[i] = '0';
		if (comp == 1)
			s2[i] = '9';
		DFS(s1, s2, comp, i + 1);
		return;
	}
}
void fastsolve(string s1, string s2) {
	bestans = -1;
	bests1 = "";
	bests2 = "";
	DFS(s1, s2, 0, 0);
	cout << bests1 << " " << bests2 << endl;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		printf("Case #%d: ", test);
		string s1, s2;
		cin >> s1 >> s2;
		//slowsolve(s1, s2);
		//continue;
		fastsolve(s1, s2);
		continue;

		int n = s1.size();
		int comp = 0;
		for (int i = 0; i < n; i++) {
			if (s1[i] != '?' && s2[i] != '?') {
				if (comp == 0)
					if (s1[i] < s2[i]) {
						comp = -1;
					}
					else
						if (s2[i] < s1[i])
							comp = 1;					
				continue;
			}
			if (s1[i] == '?' && s2[i] == '?') {
				if (comp == 0) {
					s1[i] = s2[i] = '0';
				}
				if (comp == -1) {
					s1[i] = '9';
					s2[i] = '0';
				}
				if (comp == 1) {
					s1[i] = '0';
					s2[i] = '9';
				}
				continue;
			}

			if (s1[i] == '?' && s2[i] != '?') {
				if (comp == 0)
					s1[i] = s2[i];
				if (comp == -1)
					s1[i] = '9';
				if (comp == 1)
					s1[i] = '0';
				continue;
			}
			if (s2[i] == '?' && s1[i] != '?') {
				if (comp == 0)
					s2[i] = s1[i];
				if (comp == -1)
					s2[i] = '0';
				if (comp == 1)
					s2[i] = '9';
				continue;
			}

		}

		cout << s1 << " " << s2 << endl;
	}


	return 0;
}