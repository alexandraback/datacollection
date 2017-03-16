#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int nxt[10000001];

int was[10000001];
int time = 0;

void Solve()
{
	int a, b;
	cin >> a >> b;
	time++;
	long long ans = 0;
	for (int i = a; i <= b; i++) {
		int t = i;
		if (was[i] == time) continue;
		int cur = 0;
		do {
			if ( a <= t && t <= b)
				cur++;
			was[t] = time;
			t = nxt[t];
		} while (t != i);
		ans += cur * (cur-1) / 2;
	}
	cout << ans << "\n";
}

void Gen() 
{
	int sz = 1;
	int pow = 10;
	int pow2 = 1;
	for (int i = 1; i <= 9999999; i++) {
		if (i >= pow) {
			pow *= 10;
			pow2 *= 10;
			sz++;
		}
		int t = i;
		do {
			t = t/10 + pow2 * (t % 10);
		} while (t < pow2);
		nxt[i] = t;
	}
}


int main()
{
	Gen();
	int nt, tt;
	cin >> nt;
	for (tt = 1; tt <= nt; tt++) {
		cout << "Case #" << tt << ": ";
		Solve(); 
	}
	return 0;
}
