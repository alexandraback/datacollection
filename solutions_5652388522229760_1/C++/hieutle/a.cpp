#include <iostream>
#include <unordered_set>
#include <stdio.h>
// #define TEST

using namespace std;

int main()
{
	#ifndef TEST
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		int n;
		cin >> n;
		cout << "Case #" << tt << ": ";
		if (n == 0) {
			cout << "INSOMNIA" << endl;
			continue;
		} 
		int cnt = 10, known[10], res = n;
		for (int i = 0; i < 10; i++) 
			known[i] = 0;

		int temp, rem;
		while (cnt > 0) {
			temp = res;
			while (temp > 0) {
				rem = temp % 10;
				temp = (temp - rem) / 10;
				if (known[rem] == 0) {
					known[rem] = 1;
					cnt--;
				}
			}
			res += n;
		}

		cout << res - n << endl;
	}
}
