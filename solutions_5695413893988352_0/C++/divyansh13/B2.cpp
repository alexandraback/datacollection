#include <iostream>
#include <cmath>
using namespace std;

int main() {
	freopen("in2.in", "r", stdin);
	freopen("out", "w", stdout);

	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		printf("Case #%d: ", i);
		string a, b;
		cin >> a >> b;
		int min = 1e9;
		string ans1 = "", ans2 = "";
		for(int p = 0; p < pow(10,a.size()); p++) {
			for(int q = 0; q < pow(10,a.size()); q++) {
				bool valid = true;
				string x = to_string(p);
				string y = to_string(q);
				if(x.size() < a.size()) {
					int len = x.size();
					for(int j = 0; j < a.size()-len; j++)
						x = "0" + x;
				}
				if(y.size() < a.size()) {
					int len = y.size();
					for(int j = 0; j < a.size()-len; j++)
						y = "0" + y;
				}
				for(int j = 0; j < a.size(); j++) {
					if(a[j] != '?' && a[j] != x[j])
						valid = false;
				}
				for(int j = 0; j < b.size(); j++) {
					if(b[j] != '?' && b[j] != y[j])
						valid = false;
				}
				if(!valid)
					continue;
				if(abs(p-q) < min) {
					min = abs(p-q);
					ans1 = x;
					ans2 = y;
				}
				else if(abs(p-q) == min) {
					if(p < stoi(ans1)) {
						ans1 = x;
						ans2 = y;
					}
					else if(p == stoi(ans1) && q < stoi(ans2)) {
						ans1 = x;
						ans2 = y;
					}
				}
			}
		}
		cout << ans1 << " " << ans2 << endl;
	}
}