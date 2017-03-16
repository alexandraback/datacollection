#include<iostream>
#include<cstdio>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cassert>
using namespace std;
using ll = long long;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	getchar();
	for (int tcase = 1; tcase <= t; tcase++) {
		string s;
		getline(cin, s);
		s.push_back('+');
		int answer = 0;
		for (int i = 1; i < s.size(); i++)
			answer += (s[i] != s[i-1]);
		printf("Case #%d: %d\n", tcase, answer);
	}

#ifdef LOCAL
	cerr << "time : " << (double)clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}