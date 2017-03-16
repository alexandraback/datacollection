#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[2000];
int b[2000];
int v1[2000];
int v2[2000];

int m, n, ans;

void playb() {
	int t = -1, t2 = -1, t3 = 2147483, t4 = 2147483;
	for (int i = 0; i < n; i++)
		if (!v2[i] && b[i] <= m) {
			if (v1[i]) {
				if (t3 > b[i]) {
					t3 = b[i];
					t = i;
				}
			}
			else {
				if (t4 > b[i]) {
					t4 = b[i];
					t2 = i;
				}
			}
		}
	
	//cout << "b: " << t2 << ' ' << t << endl;
	if (t2 != -1) {
		m += 2;
		ans++;
		v2[t2] = 1;
		return;
	}
	if (t != -1) {
		m++;
		ans++;
		v2[t] = 1;
		return;
	}
}

void playa() {
	int t1 = -1, t2 = -1;
	for (int i = 0; i < n; i++)
		if (!v1[i] && !v2[i] && a[i] <= m) {
			if (t2 < b[i]) {
				//cout << "A: " << i << ' ' << a[i] << ' ' << b[i] << ' ' << m << endl;
				t2 = b[i];
				t1 = i;
			}
		}
	
	//cout << "a: " << t1 << endl;
	if (t1 != -1 && t2 != -1) {
		m += 1;
		ans++;
		v1[t1] = 1;
		return;
	}
}

bool playall() {
	bool t = true;
	for (int i = 0; t && i < n; i++)	
		if (!v2[i])
			t = false;
	return t;
}

int main() {
	int t;
	cin >> t;
	
	for (int C = 1; C <= t; C++) {
		ans = 0;
		m = 0;
		
		memset(v1, 0, sizeof v1);
		memset(v2, 0, sizeof v2);
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i] >> b[i];
		
		int t = -1, t2;
		while (t != m) {
			t = m;
			t2 = t - 1;
			while (t2 != m) {
				t2 = m;
				playb();
			}
			if (playall())
				break;
			playa();
		}
		
		if (!playall())
			printf("Case #%d: Too Bad\n", C);
		else
			printf("Case #%d: %d\n", C, ans);
	}
	return 0;
}