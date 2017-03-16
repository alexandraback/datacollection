#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int n;
int app[26];
string nums[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX",
"SEVEN", "EIGHT", "NINE" };
string s;
int numbers[10];

void elim_apps(int x, char c) {
	if (app[c - 'A']) {
		for (int i = 0; i < nums[x].size(); i++) {
			if (nums[x][i]!=c) app[nums[x][i] - 'A'] -= app[c - 'A'];
		}
		numbers[x] = app[c - 'A'];
		app[c - 'A'] = 0;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	
	for (int t = 1; t <= tests; t++) {
		cin >> s;

		fill(app, app + 26, 0);
		fill(numbers, numbers + 10, 0);

		for (int i = 0; i < s.size(); i++) {
			app[s[i] - 'A']++;
		}

		elim_apps(0, 'Z');
		elim_apps(2, 'W');
		elim_apps(4, 'U');
		elim_apps(6, 'X');
		elim_apps(8, 'G');
		elim_apps(1, 'O');
		elim_apps(3, 'R');
		elim_apps(5, 'F');
		elim_apps(7, 'S');
		elim_apps(9, 'I');


		cout << "Case #" << t << ": ";
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < numbers[i]; j++) {
				cout << i;
			}
		}

		cout << "\n";
	}

	return 0;
}