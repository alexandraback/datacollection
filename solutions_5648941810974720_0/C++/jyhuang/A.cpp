// Problem A. Getting the Digits
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++) {
		static char s[4000];
		scanf("%s", s);
		vector<int> a(256);
		vector<int> ans(10);

		for (int i = 0; s[i]; i++) a[s[i]]++;

		// Check 2
		while (a['W'] > 0) {
			ans[2]++; a['T']--; a['W']--; a['O']--;
		}
		// Check 6
		while (a['X'] > 0) {
			ans[6]++; a['S']--; a['I']--; a['X']--;
		}
		// Check 0
		while (a['Z'] > 0) {
			ans[0]++; a['Z']--; a['E']--; a['R']--; a['O']--;
		}
		// Check 7
		while (a['S'] > 0) {
			ans[7]++; a['S']--; a['E']--; a['V']--; a['E']--; a['N']--;
		}
		// Check 5
		while (a['V'] > 0) {
			ans[5]++; a['F']--; a['I']--; a['V']--; a['E']--;
		}
		// Check 4
		while (a['F'] > 0) {
			ans[4]++; a['F']--; a['O']--; a['U']--; a['R']--;
		}
		// Check 3
		while (a['R'] > 0) {
			ans[3]++; a['T']--; a['H']--; a['R']--; a['E']--; a['E']--;
		}
		// Check 1
		while (a['O'] > 0) {
			ans[1]++; a['O']--; a['N']--; a['E']--;
		}
		// Check 8
		while (a['T'] > 0) {
			ans[8]++; a['E']--; a['I']--; a['G']--; a['H']--; a['T']--;
		}
		// Check 9
		while (a['I'] > 0) {
			ans[9]++; a['N']--; a['I']--; a['N']--; a['E']--;
		}


		printf("Case #%d: ", ti);
		for (int i = 0; i < ans.size(); i++)
			for (int j = 0; j < ans[i]; j++) printf("%d", i);
		printf("\n");
	}

	return 0;
}
