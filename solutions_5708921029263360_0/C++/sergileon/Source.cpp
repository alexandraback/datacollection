#pragma comment(linker, "/STACK:134217728")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <numeric>
#include <complex>
#include <functional>
#include <cmath>
#include <time.h>

using namespace std;

typedef long long LL;

int k;
vector<int> p;
vector<int> res;
bool used[33];
int answ = -1;
int Us[3333];
int T1[3333]; int Us1[3333];
int T2[3333]; int Us2[3333];
int T3[3333]; int Us3[3333];
int Time = 1;
void inc(int val, int *T, int *Us) {
	if (T[val] < Time) {
		T[val] = Time;
		Us[val] = 1;
	}
	else {
		Us[val]++;
	}
}

bool check(int val, int *Us) {
		return Us[val] <= k;
}
bool check() {
	for (int i = 0; i < p.size(); i++) {
		if (!used[i])
			continue;
		if (Us[p[i]] == Time) {
			return false;
		}
		Us[p[i]] = Time;
		int v1 = (p[i] / 100) * 10 + p[i] % 10;
		int v2 = p[i] / 10;
		int v3 = p[i] % 100;
		inc(v1, T1, Us1);
		inc(v2, T2, Us2);
		inc(v3, T3, Us3);
		if (!(check(v1, Us1) && check(v2, Us2) && check(v3, Us3))) {
			return false;
		}
	}
	return true;
}
void go(int pos, int cnt) {
	if (pos == p.size()) {
 		if (cnt <= answ) {
			return;
		}
		else {
			Time++;
			if (check()) {
				res.clear();
				answ = cnt;
				for (int i = 0; i < p.size(); i++) {
					if (used[i]) {
						res.push_back(p[i]);
					}
				}
			}
			
		}
	}
	else {
		used[pos] = true;
		go(pos + 1,cnt + 1);
		used[pos] = false;
		go(pos + 1, cnt);
	}
}
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out", "w", stdout);
	int t;
	scanf("%d",&t);
	int number = 1;
	while (t-- > 0) {
		int a, b, c;
		cin >> a >> b >> c;
		cin >> k;
		p.clear();
		answ = 0;
		res.clear();
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				for (int t = 0; t < c; t++) {
					p.push_back((i + 1) * 100 + (j + 1) * 10 + t + 1);
				}
			}
		}

		printf("Case #%d: ", number++);
		go(0, 0);
		cout << res.size() << endl;
			for (int i = 0; i < res.size(); i++) {
				cout << res[i] / 100 << ' ' << (res[i] / 10) % 10 << ' ' << res[i] % 10 << endl;
			}
		
	}
	return 0;
}