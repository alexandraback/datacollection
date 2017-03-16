#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

const int N = 11;
const int L = 500;
const int OFF = 250;

int nattack[N];
int d[N];
int delta_d[N];

int w[N], e[N];
int delta_p[N];

int s[N], delta_s[N];

int height[L];
int mx[L];

struct A_t
{
	int date;
	int west, east;
	int strength;
	A_t(){}
	A_t(int d, int w, int e, int s):date(d), west(w), east(e), strength(s) {}
};

bool operator<(const A_t& a, const A_t& b)
{
	return a.date < b.date;
}

vector<A_t> attacks;

int Attack(int w, int e, int s)
{
	int t = 0;
	for (int i = w; i <= e; i++) {
		if (height[i] < s) 
			t = 1;
		if (mx[i] < s) mx[i] = s;
	}
	return t;
}

int main()
{
	int T, x, y;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++){
		int n;
		cin>>n;
		attacks.resize(0);
		for (int i = 0; i < n; i++) {
			cin>>d[i]>>nattack[i]>>w[i]>>e[i]>>s[i]>>delta_d[i]>>delta_p[i]>>delta_s[i];
			w[i] += OFF, e[i] = e[i] - 1 + OFF;
			for (int j = 0; j < nattack[i]; j++)
			{
				attacks.push_back(A_t(d[i] + j * delta_d[i], w[i] + j * delta_p[i], e[i] + j * delta_p[i], s[i] + j * delta_s[i]));
//				printf("\nday %d, attack[%d, %d] with strength %d\n", d[i] + j * delta_d[i], w[i] + j * delta_p[i], e[i] + j * delta_p[i], s[i] + j * delta_s[i]);
			}
		}
		sort(attacks.begin(), attacks.end());
		memset(height, 0, sizeof(height));
		int i = 0, j = 0, m = attacks.size();			
		int ans = 0;
		while (j < m) {
			memcpy(mx, height, sizeof(height));
			while (j < m && attacks[i].date == attacks[j].date) {
				ans += Attack(attacks[j].west, attacks[j].east, attacks[j].strength);
				j++;
			}
			memcpy(height, mx, sizeof(mx));
			i = j;
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
