#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

string S, ans, tmp1, tmp2;

void run_case(int tc) {
    cin >> S;
	ans.clear();tmp1.clear();tmp2.clear();
	for (int i = 0; i < S.size(); i++) {
		tmp1 = ans + S[i];
		tmp2 = S[i] + ans;
		if (tmp1.compare(tmp2) >= 0)
			ans = ans + S[i];
		else
			ans = S[i] + ans;
	}

	cout << "Case #" << tc << ": " << ans << endl;
}

int main() {
	int num = 0;
	cin >> num;
	for (int i = 1; i <= num; ++i) {
		run_case(i);
	}
	return 0;
}