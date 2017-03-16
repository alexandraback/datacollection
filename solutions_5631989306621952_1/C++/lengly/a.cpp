#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;

string s;

void work() {
	string ans = "";
	for(int i=0;i<s.size();i++) {
		if (ans == "") {
			ans = s[i];
		} else if (s[i] >= ans[0]) {
			ans = s[i] + ans;
		} else {
			ans = ans + s[i];
		}
	}
	cout << ans << endl;
}

int main() {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int t;
	scanf("%d\n", &t);
	for(int i=0;i<t;i++) {
		getline(cin, s);
		printf("Case #%d: ", i+1);
		work();
	}

	return 0;
}

