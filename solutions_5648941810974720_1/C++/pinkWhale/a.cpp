#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int test;
	FILE *fp = NULL;
	fp = fopen("A-large.in", "r");
	FILE *fp2 = NULL;
	fp2 = fopen("output.txt", "w");
	fscanf(fp, "%d", &test);

	int alpha[26];
	char input[2001];
	string number[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
	char match[10] = { 'Z', 'O', 'W', 'R', 'U', 'F', 'X', 'S', 'G', 'N' };
	bool first[10] = { false, };
	first[0] = first[2] = first[4] = first[6] = true;
	
	vector<pair<int, char> > v;
	for (int i = 0; i < 10; i++) {
		if (first[i]) 
			v.push_back(make_pair(i, match[i]));
	}
	for (int i = 0; i < 10; i++) {
		if (!first[i])
			v.push_back(make_pair(i, match[i]));
	}

	for (int t = 1; t <= test; t++) {
		fscanf(fp, "%s", input);

		int len = strlen(input);
		memset(alpha, 0, sizeof(alpha));
		for (int i = 0; i < len; i++) {
			alpha[input[i] - 'A']++;
		}

		vector<int> ans;
		for (int i = 0; i < 10; i++) {
			int num = v[i].first;
			int idx = v[i].second - 'A';

			while (alpha[idx] > 0) {
				for (char c : number[num]) {
					alpha[c - 'A']--;
				}
				ans.push_back(num);
			}
		}
		sort(ans.begin(), ans.end());

		fprintf(fp2, "Case #%d: ", t);
		for (int digit : ans)
			fprintf(fp2, "%d", digit);
		fprintf(fp2, "\n");
		ans.clear();
	}

	return 0;
}