#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include<functional>
#include <fstream>
#define ii pair<int,int>
#define INF 1000000000
using namespace std;
int main()
{
	freopen("outputDLarge.txt","w",stdout);
	int t, l;
	cin >> t;
	for (l = 0; l < t; l++) {
		int k, c, s;
		cin >> k >> c >> s;
		cout << "Case #" << l + 1 << ": ";
		if ((k+1) / 2 <= s && c > 1) {
			int x = (k + 1) / 2;
			int m = k;
			cout << m << ' ';
			for (int i = 1; i < x; i++) {
				m += k - 1;
				cout << m<<' ';
			}
			cout << endl;
		}
		else if (c == 1 && k==s) {
			for (int i = 1; i <= s; i++) {
				cout << i << ' ';
			}
			cout << endl;
		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}
