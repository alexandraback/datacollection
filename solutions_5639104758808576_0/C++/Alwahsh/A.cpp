#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin >> t;
	int n = 0;
	while (t--) {
		int num;
		cin >> num;
		ll res = 0;
		int num_people = 0;
		for (int i = 0; i <= num; i++) {
			char c;
			cin >> c;
			c-= '0';
			if (c > 0 && num_people < i) {
				res+= (i-num_people);
				num_people = i;
			}
			num_people+= c;
		}
		cout << "Case #" << ++n << ": " << res << endl;
	}
	return 0;
}
