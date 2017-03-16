#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	/*
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);
	*/

	/*
	freopen("A-small-attempt2.in", "r", stdin);
	freopen("A-small-attempt2.out", "w", stdout);
	*/

	/*
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	*/
	int nCases;
	cin >> nCases;

	string nums[] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
	string target = "ZXGSVUHTIE";
	int ind[] = { 0, 6, 8, 7, 5, 4, 3, 2, 9, 1 };

	int buckets[26];
	int result[10];

	for (int i = 1; i <= nCases; i++) {
		cout << "Case #" << i << ": ";

		string s;
		cin >> s;

		memset(buckets, 0, sizeof(buckets));
		memset(result, 0, sizeof(result));

		for (int i = 0; i < s.length(); i++) {
			buckets[s[i] - 'A']++;
		}

		for (int i = 0; i < 10; i++) {
			int index = ind[i];
			
			result[index] = buckets[target[i] - 'A'];
			for (int j = 0; j < nums[index].length(); j++) {
				buckets[nums[index][j] - 'A'] -= result[index];
			}
		}

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < result[i]; j++) {
				cout << i;
			}
		}

		cout << endl;
	}

	return 0;
}