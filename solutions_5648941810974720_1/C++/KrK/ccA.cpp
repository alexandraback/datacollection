#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string words[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char let[] = {'W', 'Z', 'X', 'G', 'S', 'V', 'F', 'O', 'N', 'T'};
int got[] = {2, 0, 6, 8, 7, 5, 4, 1, 9, 3};
const int Maxl = 26;
const int Maxd = 10;

int t;
string s;
int freq[Maxl];

int main()
{
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> s;
		fill(freq, freq + Maxl, 0);
		for (int i = 0; i < s.length(); i++)
			freq[s[i] - 'A']++;
		vector <int> res;
		for (int i = 0; i < Maxd; i++)
			while (freq[let[i] - 'A'] > 0) {
				res.push_back(got[i]);
				for (int j = 0; j < words[got[i]].size(); j++)
					freq[words[got[i]][j] - 'A']--;
			}
		sort(res.begin(), res.end());
		printf("Case #%d: ", tc);
		for (int i = 0; i < res.size(); i++)
			printf("%d", res[i]);
		printf("\n");
	}
	return 0;
}