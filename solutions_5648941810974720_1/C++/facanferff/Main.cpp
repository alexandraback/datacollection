#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

char s[2005];
bool used[2005] = {};

void mark(char c) {
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (!used[i] && s[i] == c) {
			used[i] = true;
			return;
		}
	}
}

void solve() {
	int len = strlen(s);
	vector<int> numbers;
	int num_used = 0;
	memset(used, false, sizeof used);
	while (num_used < len) {
		bool done = false;
		for (int i = 0; i < len; i++) {
			if (!used[i]) {
				if (s[i] == 'Z') {
					// ZERO
					used[i] = true;
					mark('E');
					mark('R');
					mark('O');
					numbers.push_back(0);
					num_used += 4;
					done = true;
				}
			}
		}

		for (int i = 0; i < len; i++) {
			if (!used[i]) {
				if (s[i] == 'W') {
					// TWO
					used[i] = true;
					mark('T');
					mark('O');
					numbers.push_back(2);
					num_used += 3;
					done = true;
				}
			}
		}

		for (int i = 0; i < len; i++) {
			if (!used[i]) {
				if (s[i] == 'U') {
					// FOUR
					used[i] = true;
					mark('F');
					mark('O');
					mark('R');
					numbers.push_back(4);
					num_used += 4;
					done = true;
				}
			}
		}

		for (int i = 0; i < len; i++) {
			if (!used[i]) {
				if (s[i] == 'X') {
					// SIX
					used[i] = true;
					mark('S');
					mark('I');
					numbers.push_back(6);
					num_used += 3;
					done = true;
				}
			}
		}

		for (int i = 0; i < len; i++) {
			if (!used[i]) {
				if (s[i] == 'G') {
					// EIGHT
					used[i] = true;
					mark('E');
					mark('I');
					mark('H');
					mark('T');
					numbers.push_back(8);
					num_used += 5;
					done = true;
				}
			}
		}

		for (int i = 0; i < len; i++) {
			if (!used[i]) {
				if (s[i] == 'F') {
					// FIVE
					used[i] = true;
					mark('I');
					mark('V');
					mark('E');
					numbers.push_back(5);
					num_used += 4;
					done = true;
				}
			}
		}

		for (int i = 0; i < len; i++) {
			if (!used[i]) {
				if (s[i] == 'S') {
					// SEVEN
					used[i] = true;
					mark('E');
					mark('V');
					mark('E');
					mark('N');
					numbers.push_back(7);
					num_used += 5;
					done = true;
				}
			}
		}

		for (int i = 0; i < len; i++) {
			if (!used[i]) {
				if (s[i] == 'H') {
					// THREE
					used[i] = true;
					mark('T');
					mark('R');
					mark('E');
					mark('E');
					numbers.push_back(3);
					num_used += 5;
					done = true;
				}
			}
		}

		for (int i = 0; i < len; i++) {
			if (!used[i]) {
				if (s[i] == 'O') {
					// ONE
					used[i] = true;
					mark('N');
					mark('E');
					numbers.push_back(1);
					num_used += 3;
					done = true;
				}
			}
		}

		for (int i = 0; i < len; i++) {
			if (!used[i]) {
				if (s[i] == 'N') {
					// NINE
					used[i] = true;
					mark('I');
					mark('N');
					mark('E');
					numbers.push_back(9);
					num_used += 4;
					done = true;
				}
			}
		}

		if (!done) break;
	}

	//printf("::%d %d\n", num_used, len);
	sort(numbers.begin(), numbers.end());
	for (int i = 0; i < numbers.size(); i++)
		printf("%d", numbers[i]);
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	for (int ctest = 1; ctest <= t; ctest++) {
		scanf(" %s", s);

		printf("Case #%d: ", ctest);
		solve();
	}
	return 0;
}
