#include <cassert>
#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

string mappers[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int counter[256];
int values[10];
int order[10] = {0, 2, 4, 6, 8, 3, 5, 7, 1, 9};
char keys[10] = {'Z', 'W', 'U', 'X', 'G', 'T', 'F', 'V', 'O', 'I'};
int T;

int main() {
	scanf("%d", &T);
	for (int it = 1; it <= T; it++) {
		string s;
		cin >> s;
		memset(counter, 0, sizeof counter);
		for (int i = 0; i < s.size(); i++) {
			counter[s[i]]++;
		}
		memset(values, 0, sizeof values);
		for (int i = 0; i < 10; i++) {
			int digit = order[i];
			values[digit] = counter[keys[i]];
			for (int j = 0; j < mappers[digit].size(); j++) {
				counter[mappers[digit][j]] -= values[digit];
			}
		}
		for (int i = 0; i < 256; i++) {
			if (counter[i] != 0) {
				assert(false);
			}
		}
		printf("Case #%d: ", it);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < values[i]; j++) {
				printf("%d", i);
			}
		}
		printf("\n");
	}
	return 0;
}