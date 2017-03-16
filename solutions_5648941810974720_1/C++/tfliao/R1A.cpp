#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string S;

string digits[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int order[] = {0, 2, 4, 6, 8, 3, 7, 1, 5, 9};
char tester[] = {"ZOWTUVXSGE"};

void input()
{
	cin >> S;
}

void solv()
{
	vector<int> ans ;
	int cnt[128] = {0};
	for (int i=0;i<S.length(); ++i) {
		cnt[S[i]] ++;
	}
	
	for (int i=0;i<10;++i) {
		int d = order[i];
		char t = tester[d];
		
		if (cnt[t] > 0) {
			int n = cnt[t];
			for (int j=0;j<n;j++) ans.push_back(d);
			for (int j=0;j<digits[d].length();++j) {
				cnt[digits[d][j]] -= n;
			}
		}
	}

	sort(ans.begin(), ans.end());
	for (int i=0;i<ans.size();++i) printf("%d", ans[i]);
	printf("\n");
	
}

int main()
{
	int T, nCase = 1;
	cin >> T;
	for (nCase = 1; nCase <= T; ++nCase) {
		input();
		
		printf("Case #%d: ", nCase);
		solv();
	}
	
	return 0;
}