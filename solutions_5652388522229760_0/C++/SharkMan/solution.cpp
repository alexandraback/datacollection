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
int main() {
	freopen("output.txt", "w", stdout);
	int t, l;
	cin >> t;
	for (l = 0; l < t; l++) {
		bool vis[10];
		int cnt = 0;
		memset(vis, false, sizeof(vis));
		long long n, i = 1;
		cin >> n;
		if (n > 0) {
			while (1) {
				long long ans = n * i;
				long long x = ans;
				while (x > 0) {
					int a = x % 10;
					x /= 10;
					if (!vis[a]) {
						cnt++;
						vis[a] = true;
					}
				}
				if (cnt == 10)
					break;
				i++;
			}
			cout << "Case #" << l + 1 << ": " << n * i << endl;
		} else
			cout << "Case #" << l + 1 << ": INSOMNIA" << endl;
	}
	return 0;
}
