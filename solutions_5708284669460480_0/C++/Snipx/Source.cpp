#include <iostream>
#include <fstream>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int buf[200];

int main() {
	//ios_base::sync_with_stdio(false);

	ifstream cin("input.txt");
	ofstream cout("output.txt");

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int k, l, s;
		cin >> k >> l >> s;
		string target, keyboard;
		cin >> keyboard >> target;

		int num = 1;
		for (int i = 0; i < s; i++) {
			num *= k;
		}

		int maxOccur = 0;
		int totalOccur = 0;
		
		for (int mask = 0; mask < num; mask++) {
			string curWord = "";
			
			for (int j = 0; j < s; j++)
				buf[j] = 0;
			int temp = mask;
			int c = 0;
			while (temp > 0) {
				buf[c++] = temp % k;
				temp /= k;
			}

			for (int j = 0; j < s; j++)
				curWord += keyboard[buf[j]];

			int curOccur = 0;

			for (int i = 0; i <= s - l; i++) {
				if (curWord.substr(i, l) == target) {
					curOccur++;
				}
			}

			maxOccur = max(maxOccur, curOccur);
			totalOccur += curOccur;
		}

		double ans = maxOccur - double(totalOccur) / double(num);

		cout.precision(7);
		cout << "Case #" << test << ": " << fixed << ans << endl;
	}


	//system("pause");
	return 0;
}