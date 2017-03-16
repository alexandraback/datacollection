#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;

void Making(string val, vector<string> &vt, char str[20], int index, int len)
{
	if (index == len) {
		vt.push_back(val);
		return;
	}

	if (str[index] == '?') {
		for (int i = 0; i < 10; i++) {
			string temp = val;
			temp.push_back(i + '0');
			Making(temp, vt, str, index + 1, len);
		}
	}
	else {
		val += str[index];
		Making(val, vt, str, index + 1, len);
	}
}

long long StrToL(string val)
{
	long long ret = val[0];
	for (int i = 1; i < val.length(); i++) {
		ret *= 10;
		ret += val[i];
	}

	return ret;
}

bool Compare(pair<string, string> a, pair<string, string> b)
{
	long long a_1 = StrToL(a.first), a_2 = StrToL(a.second), b_1 = StrToL(b.first), b_2 = StrToL(b.second);

	if (a_1 < b_1) {
		return true;
	}

	if (a_2 < b_2)
		return true;

	return false;
}

int main()
{
	int T;

	scanf("%d", &T);
	for (int w = 0; w < T; w++) {
		char A[20], B[20];

		scanf("%s %s", A, B);

		vector<string> vt_a, vt_b;

		string temp;
		Making(temp, vt_a, A, 0, strlen(A));
		Making(temp, vt_b, B, 0, strlen(B));

		int min_diff = 987654321;
		for (int i = 0; i < vt_a.size(); i++) {
			for (int m = 0; m < vt_b.size(); m++) {
				long long a = StrToL(vt_a[i]);
				long long b = StrToL(vt_b[m]);

				if (abs(a - b) < min_diff)
					min_diff = abs(a - b);
			}
		}

		vector<pair<string, string>> vt;
		for (int i = 0; i < vt_a.size(); i++) {
			for (int m = 0; m < vt_b.size(); m++) {
				long long a = StrToL(vt_a[i]);
				long long b = StrToL(vt_b[m]);

				if (abs(a - b) == min_diff) {
					vt.push_back(pair<string, string>(vt_a[i], vt_b[m]));
				}
			}
		}
		sort(vt.begin(), vt.end(), Compare);

		printf("Case #%d: %s %s\n", w+1, vt[0].first.c_str(), vt[0].second.c_str());
	}

	return 0;
}