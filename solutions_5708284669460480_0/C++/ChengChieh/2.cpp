#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int T, k, l, s;
string KB, word;
double P[43];
int key_cnt[43], char_cnt[43];
int ans = 0;
int max_cnt;
void dfs(int dep, string st) {
	if (dep > s) {
		int cnt = 0;
		for (int i = 0; i < s; i++) {
			if (st.substr(i, l) == word) cnt ++;
		}
		if (cnt > max_cnt) max_cnt = cnt;
		ans += cnt;
		return;
	}
	int res = 0;
	for (int i = 0; i < k; i++)
	{
		dfs(dep+1, st+KB[i]);
	}
}

int main() {
	freopen("input2.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
	cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> k >> l >> s;
		
		cin >> KB;
		cin >> word;
		for (int i = 0; i < 26; i++) key_cnt[i] = 0;
		for (int i = 0; i < 26; i++) char_cnt[i] = 0;

		for (int i = 0; i < k; i++) {
			key_cnt[KB[i]-'A'] ++;
		}

		for (int i = 0; i < l; i++) {
			char_cnt[word[i]-'A'] ++;
		}

		int noanswer = 0;
		for (int i = 0; i < 26; i++) {
			if (char_cnt[i] > 0 && key_cnt[i] <= 0) {
				noanswer = -1;
				break;
			}

		}		
		if (noanswer < 0) {
			cout << "Case #" << test << ": 0.0" << endl; 
			continue;
		}


		for (int i = 0; i < 26; i++) P[i] = key_cnt[i] / k;
		ans = 0, max_cnt = 0;
		dfs(1, "");
		int temp = 1;
		for (int i = 0; i < s; i++)
			temp *= k;
		double res = 1.0*ans / temp;
		printf("Case #%d: %.7lf\n", test, max_cnt - res);
		//cout << "Case #" << test << ": " << << endl; 
	}
	return 0;
}
