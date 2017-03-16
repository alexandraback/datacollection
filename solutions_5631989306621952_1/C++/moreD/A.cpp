#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>

#define LL long long
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define PII pair<int, int>
#define PID pair<int, double>

using namespace std;


int main(){
	int T;
	cin >> T;
	for (int v = 0; v < T; ++v) {
		cout << "Case #" << v + 1 << ": ";
		string str, ans, empty;
		cin >> str;
		for (int i = 0; i < str.length(); ++i) {
			if (empty + str[i] + ans < ans + str[i])
				ans = ans + str[i];
			else
				ans = empty + str[i] + ans;
		}
		cout << ans << endl;
	}
}
