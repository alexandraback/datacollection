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

const int debug = 0;
#define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
const int inf = 1000000000;

int main() {
	int test, cases = 1;
	cin >> test;
	for (cases = 1; cases <= test; cases++) {
		int n;
		int parity[3000] = {0};
		cin >> n;
		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = 0; j < n; j++) {
				int a; cin >> a; parity[a]++;
			}
		}
		cout << "Case #" << cases << ":";
		for (int i = 0; i < 3000; i++) {
			if (parity[i] % 2) cout << " " << i;
		}
		cout << endl;
	}
	return 0;
}
