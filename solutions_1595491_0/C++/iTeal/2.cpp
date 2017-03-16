#include <iostream>

#define MIN(a,b) (a)<(b)?(a):(b)

using namespace std;

int main (int argc, char const *argv[])
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		int ans = 0;
		int n, s, p;
		cin >> n >> s >> p;
		int t;
		int t1 = 3 * p - 2;
		int t2 = 3 * p - 4;
		if (p == 0) t1 = t2 = 0;
		if (p == 1) t1 = t2 = 1;
		int sp = 0;
		for(int j = 0; j < n; j++) {
			cin >> t;
			if (t >= t1) ans++;
			else if (t >= t2) sp++;
		}
		ans += MIN(s,sp);
		cout << ans << endl;
	}
	return 0;
}