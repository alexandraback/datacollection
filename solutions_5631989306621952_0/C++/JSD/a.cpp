#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <stack>

using namespace std;

typedef unsigned int uint;
typedef long long L; // LL
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;


string s;
int len;
void parse() {
	cin >> s;
	len = s.length();
}

void solve() {
	string ans = "";
	string s1, s2;
	for (int i = 0; i < len; i++){
		s1 = ans;
		s1 += s[i];

		string s3 = "";
		s3 += s[i];
		s2 = s3 + ans;
		if (s1 < s2)
			ans = s2;
		else ans = s1;

		
 	}

	cout << ans << endl;
}

int main() {
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++){
		parse();
		cout << "Case #" << i <<": ";
		solve();
	}
	return 0;
}



