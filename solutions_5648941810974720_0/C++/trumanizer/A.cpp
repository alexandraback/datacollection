#include <iostream>
#include <string>
#include <vector>

using namespace std;

char * str[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", 
		"FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
vector<string> digit (str, str + 10);
int order[] = {0, 2, 6, 8, 3, 4, 7, 5, 1, 9};
int cnt[10];
int fre[26];

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	string s;
	for (int tt = 1; tt <= t; tt++) {
		cin >> s;
		for (int i = 0; i < 26; i++) fre[i] = 0;
		for (int i = 0; i < 10; i++) cnt[i] = 0;
		for (int i = 0; i < s.size(); i++)
			fre[s[i] - 'A']++;

		for (int d : order) {
			bool ok = true;
			while (ok) {
				for (int i = 0; i < digit[d].size(); i++)
					fre[digit[d][i] - 'A']--;
				for (int i = 0; i < digit[d].size(); i++)
					if (fre[digit[d][i] - 'A'] < 0) {
						ok = false;
						break;
					}

				if (ok) 
					cnt[d]++;
				else {
					for (int i = 0; i < digit[d].size(); i++)
						fre[digit[d][i] - 'A']++;
				}
			} 
		}

		cout << "Case #" << tt << ": ";
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < cnt[i]; j++)
				cout << i;
		}
		cout << endl;
	}	
}
