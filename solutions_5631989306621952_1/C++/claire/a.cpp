#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;
int v[10];

int main() {
	int o, cas = 0;
	scanf("%d", &o);
	//for (int p = 0; p <= 1000000; p++) {
	while (o--) {
		string s;
		cin>>s;
		int n = s.size();
		string ans = "";
		for (int i = 0; i < n; i++) {
			char ch = s[i];
			if (i == 0 || ch >= ans[0]) {
				ans = ch + ans;
			} else {
				ans = ans + ch;
			}
		}
		printf("Case #%d: ", ++cas);
		cout<<ans<<endl;
	}
}