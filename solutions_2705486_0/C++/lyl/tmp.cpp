#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <fstream>
using namespace std;

set<string> dt;

void ffind(string wd, int fi, vector<int>& v1, vector<int>& v2) {
	int len = wd.length();
	if (dt.count(wd) > 0) {
		v1.push_back(0);
		if (fi < len) 
			v2.push_back(4);
		else 
			v2.push_back(4 - fi + len);
		return;
	}

	for (int j = fi; j < len; j++) {
		string wd1 = wd;
		for (char z = 'a'; z <= 'z'; z++) {
			wd1[j] = z;
			if (dt.count(wd1) > 0) {
				v1.push_back(1);
				if (len - 1 - j >= 4)
					v2.push_back(4);
				else
					v2.push_back(len - 1 - j);
			}
		}
	}

	for (int j = fi; j < len; j++)
		for (int k = j + 5; k <= len; k++) {
			string wd2 = wd;
			for (char z1 = 'a'; z1 <= 'z'; z1++)
				for (char z2 = 'a'; z2 <= 'z'; z2++) {
					wd2[j] = z1;
					wd2[k] = z2;
					if (dt.count(wd2)) {
						v1.push_back(2);
						if (len - 1 - k >= 4)
							v2.push_back(4);
						else
							v2.push_back(len - 1 - k);
					}
				}
		}
}

int n;
int dp[4010][5];

int main() {
	ifstream fin;
	fin.open("garbled_email_dictionary.txt");
	string ln;
	while (getline(fin, ln))
		dt.insert(ln);
	fin.close();


	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		string ss;
		cin >> ss;
		n = ss.length();
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++)
			for (int ll = 1; ll <= 10; ll++) {
				if (i - ll + 1 < 0)
					break;

				string wd = "";

				for (int k = i - ll + 1; k <= i; k++)
					wd += ss[k];

				for (int j = 0; j <= 4; j++) {
					if ((i - ll + 1 == 0) || (dp[i - ll][j] >= 0)) {
						vector<int> v1, v2;
						ffind(wd, 4 - j, v1, v2);
						for (int k = 0; k < v1.size(); k++) {
							if (i - ll + 1 == 0) {
								if (dp[i][v2[k]] < 0 || v1[k] < dp[i][v2[k]])
									dp[i][v2[k]] = v1[k];
							
							} else {
								if (dp[i][v2[k]] < 0 || dp[i - ll][j] + v1[k] < dp[i][v2[k]])
									dp[i][v2[k]] = dp[i - ll][j] + v1[k];
							}
						}
					}
				}
			}
		
		int ans = 1000000000;
		for (int i = 0; i < 5; i++)
			if (dp[n - 1][i] >= 0)
				ans = min(ans, dp[n - 1][i]);
		printf("Case #%d: %d\n", tt, ans);
	}
}
