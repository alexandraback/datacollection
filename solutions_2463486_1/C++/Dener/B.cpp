#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

inline bool isPalin(long long x) {
	if (!x)
		return true;
	string res = "";
	while (x) {
		res.push_back(x % 10);
		x /= 10;
	}
	for (int i = 0, j = (int)(res.size()) - 1; i < j; i++, j--)
		if (res[i] != res[j])
			return false;
	return true;
}

void solve() {
	long long a, b;
	cin >> a >> b;
	long long l = sqrt(a * 1.0);
	while (l * l >= a)
		l--;
	while (l * l < a)
		l++;

	long long ans = 0;
	for (long long cur = l; cur * cur <= b; cur++) {
		if (!isPalin(cur))
			continue;
		if (!isPalin(cur * cur))
			continue;
		cout << cur * cur << ", ";
//		cout << "DEBUG: " << cur * cur << endl;
		ans++;
	}
	//cout << ans << endl;
}

long long numbers[] = {1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004, -1};

void solve2() {
	long long a, b;
	cin >> a >> b;
	long long ans = 0;
	for (int i = 0; numbers[i] != -1; i++) {
		if (numbers[i] >= a && numbers[i] <= b)
			ans++;
	}
	cout << ans << endl;
}

int main() {
	freopen("C-large-1.in","r", stdin);
	freopen("B_output.txt","w", stdout);
	int T;
	scanf("%d\n", &T);
	for (int i = 0; i < T; i++) {
		printf("Case #%d: ", i + 1);
		solve2();
	}
}
