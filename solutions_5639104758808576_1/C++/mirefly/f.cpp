#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

int solve(vector<int> a) {
	int  n = a.size();	
	vector<int> s(n, 0);
	for (int i = 1; i < n; i++) {
		s[i] = s[i - 1] + a[i - 1];
		//cout << s[i];
	}
	int ret = 0;
	int tmp;
	for (int i = 1; i < n; i++) {
		tmp = i - s[i];
		if (tmp > ret) {
			ret = tmp;
			continue;
		}
	}
	return ret;
}


int main() {
	int nt;
	cin >> nt;
	int num;
	for (int i = 0; i < nt; i++) {
		cin >> num;
		char a;
		getchar();
		vector<int> v(num + 1);
		for (int j = 0; j < num + 1; j++) {
			scanf("%c", &a);
			v[j] = int(a - '0');
		}
		cout << "Case #" << i + 1 << ": " << solve(v) << endl;
		getchar();
	}
	return 0;
}
