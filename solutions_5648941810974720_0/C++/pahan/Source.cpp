#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>
#include<unordered_set>
#include<unordered_map>
#include<ctime>
#include<cstdlib>
#include<climits>
#include<string>
#include<cstring>
using namespace std;
using ll = long long;

int code(char c) {
	return c - 'A';
}

void exclude(vector<int> &a, string s, int times) {
	for (int i = 0; i < s.size(); i++)
		a[code(s[i])] -= times;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	srand(time(NULL));

	int tnumber;
	cin >> tnumber;
	for (int i = 1; i <= tnumber; i++) {
		cout << "Case #" << i << ": ";
		string s;
		cin >> s;
		vector<int> a(26, 0);
		for (int i = 0; i < s.size(); i++)
			a[code(s[i])]++;
		vector<int> b(10, 0);
		exclude(a, "ZERO", b[0] = a[code('Z')]);
		exclude(a, "TWO", b[2] = a[code('W')]);
		exclude(a, "SIX", b[6] = a[code('X')]);
		exclude(a, "EIGHT", b[8] = a[code('G')]);
		exclude(a, "FOUR", b[4] = a[code('U')]);
		exclude(a, "FIVE", b[5] = a[code('F')]);
		exclude(a, "SEVEN", b[7] = a[code('V')]);
		exclude(a, "THREE", b[3] = a[code('R')]);
		exclude(a, "ONE", b[1] = a[code('O')]);
		exclude(a, "NINE", b[9] = a[code('I')]);
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < b[i]; j++)
				cout << i;
		cout << endl;
	}

	return 0;
}