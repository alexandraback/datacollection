//author: whd

#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define mp make_pair
#define pb push_back
#define x first
#define y second

using namespace std;
typedef long long big;

typedef pair<int, int> pii;
string str;
int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int cas, cass;
	scanf("%d", &cas);
	vector<string> ans;
	for (cass = 1; cass <= cas; cass++) {
		printf("Case #%d: ", cass);
		cin >> str;
		string ans;
		for (int i = 0; i < str.size(); i++) {
			if (!i) {
				ans.push_back(str[i]);
			} else {
				if (str[i] < *ans.begin()) {
					ans.push_back(str[i]);
				} else {
					ans = str[i] + ans;
				}
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
}

