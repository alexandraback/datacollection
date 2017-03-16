#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <string>
#pragma warning(disable:4996)

using namespace std;

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int w[256][256];
int L, X;
string s;

int make(int a, int b)
{
	int p = -1 + 2 * (a*b > 0);
	return p*w[abs(a)][abs(b)];
}

int make2(int pos)
{
	int ans = 1;
	for (int i = pos; i < L; i++) ans = make(ans, s[i]);
	return ans;
}

#define make3(pos) \
	for (int i=pos; i<L; i++) {\
		ans = make(ans,s[i]);\
		if (ans == p) return judge(i+1,p+1);\
	}
bool judge(int pos, int p)
{
	if (p == 'l') {
		int ans = make2(pos);
		X--;
		int sum = make2(0);
		if (sum == 1) return ans == 1;
		if (X % 2) ans = make(ans, sum), X--;

		if (sum != -1) X /= 2;
		if (X % 2) ans = make(ans, -1);
		return ans == 1;
	}
	if (pos == L) X--, pos = 0;
	if (X == 0) return false;
	int ans = 1;
	make3(pos);
	for (int j = 0; j < 3; j++)
	{
		if (--X == 0) return false;
		make3(0);
	}
	return false;
}

int main()
{
	w[1][1] = 1;
	for (int i = 'i'; i <= 'k'; i++) w[1][i]=w[i][1]=i, w[i][i] = -1;
	w['i']['j'] = 'k'; w['j']['i'] = -'k';
	w['j']['k'] = 'i'; w['k']['j'] = -'i';
	w['k']['i'] = 'j'; w['i']['k'] = -'j';
//	freopen("C-small-attempt3.in", "r", stdin);
//	freopen("C-small-attempt3.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> L >> X;
		cin >> s;
		cout << "Case #" << t << ": ";
		if (judge(0, 'i')) cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}