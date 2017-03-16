#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;

#define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
const int inf = 1000000000;

int main() {
	int test, cases = 1;
	cin >> test;
	for (cases = 1; cases <= test; cases++) {
		int n;
		string s;
		cin >> n >> s;
		int sum = 0;
		int res = 0;
		for (int i = 0; i <= n; i++) {
			if (i > 0 && s[i] != '0') {
				if (sum < i) {
					res += (i-sum);
					sum = i;
				}
			}
			sum += s[i] - '0';
		}
		cout << "Case #" << cases << ": " << res << endl;
	}
	return 0;
}
