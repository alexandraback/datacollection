#include <bits/stdc++.h>

using namespace std;

int i, t, j, k, l, a[30], ans[30];
string s, uniq_l = "ZOWTUFXSGI", word[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};


int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.ans", "w", stdout);
	
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		cin >> s;
		
		for (j = 0; j < 26; j++) {
			a[j] = 0;
			ans[j] = 0;
		}
		
		for (j = 0; j < s.length(); j++)
			a[s[j] - 'A']++;
		
// 		for (j = 0; j < 26; j++)
// 			cout << (char) ('A' + j) << ": " << a[j] << " ";
// 		cout << endl;
		for (j = 0; j < 10; j += 2) {
			if (a[uniq_l[j] - 'A'] > 0) {
// 				cout << j << " " << uniq_l[j] << endl;
				l = a[uniq_l[j] - 'A'];
				ans[j] += l;
				for (k = 0; k < word[j].length(); k++)
					a[word[j][k] - 'A'] -= l;
				
// 				for (k = 0; k < 26; k++)
// 					cout << (char) ('A' + k) << ": " << a[k] << " ";
// 				cout << endl;

			}
		}
		
		for (j = 1; j < 10; j += 2) {
			if (a[uniq_l[j] - 'A'] > 0) {
// 				cout << j << " " << uniq_l[j] << endl;
				l = a[uniq_l[j] - 'A'];
				ans[j] += l;
				for (k = 0; k < word[j].length(); k++)
					a[word[j][k] - 'A'] -= l;
				
// 				for (k = 0; k < 26; k++)
// 					cout << (char) ('A' + k) << ": " << a[k] << " ";
// 				cout << endl;

			}
		}
		
		printf("Case #%d: ", i + 1);
		
		for (j = 0; j < 10; j++) {
			for (k = 0; k < ans[j]; k++)
				printf("%d", j);
		}
		
		printf("\n");
	}
	
	return 0;
}