#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

LL result = 0;

inline bool isvalid(vector<string> &s, int end)
{
	int table[26];
	memset(table, 0, sizeof(table));

	char lastc = '\0';
	for (int i=0; i<=end; i++) {
		string ss = s[i];
		int len = ss.length();

		for (int j=0; j<len; j++) {
			if (ss[j] != lastc && table[ss[j]-'a']) {
				return false;
			}
			table[ss[j]-'a'] ++;
			lastc = ss[j];
		}
	}

	return true;
}

inline void permutation(vector<string> &s, int start, int end) {
	int i;
	if (start >= end) 
	{
		if (isvalid(s, end-1)) {
			result ++;
		}
		return;
	}

	for (i = start; i < end; i++) 
	{
		swap(s[i], s[start]);
		if (isvalid(s, start)) {
			permutation(s, start+1, end);
		}
		swap(s[i], s[start]);
	}
}

int main()
{
	freopen("E:\\Projects\\VS2010\\gcj2014\\gcj2014\\Round1C\\B\\B-small-attempt1.in", "r", stdin);
	freopen("E:\\Projects\\VS2010\\gcj2014\\gcj2014\\Round1C\\B\\B-small.out", "w", stdout);
	int T;

	cin >>T;

	for (int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";

		int n;

		cin >> n;

		vector<string> strs(n);
		for (int i=0; i<n; i++) {
			cin >> strs[i];
			string str;
			int len = strs[i].length();
			char lastc = '\0';
			for (int j=0; j<len; j++) {
				if (strs[i][j] !=lastc) {
					lastc = strs[i][j];
					str.push_back(lastc);
				}
			}
			strs[i] = str;
		}
		result = 0;

		int table[26];
		memset(table, 0, sizeof(table));
		permutation(strs, 0, n);

		cout << result << endl;
	}
	return 0;
}