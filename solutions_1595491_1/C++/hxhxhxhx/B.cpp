#define INPUT "test.in"
#define OUTPUT "result.out"
#define MAXN 100

#include <iostream>
#include <fstream>

using namespace std;

int solve(int t, int s, int p, int total[])
{
	int res = 0;
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < t; i++) {
		int l = total[i];
		int a = l / 3;

		if (l == 0) {
			if (p == 0) res++;
		} else if (l == 1) {
			if (p <= 1) res++;
		} else if ((l >= 29) || (l % 3 == 0 && a >= p) || (l % 3 == 1 && a + 1 >= p) || (l % 3 == 2 && a + 1 >= p)) {
			count1++;
		} else if ((l % 3 == 0 && a + 1 >= p) || (l % 3 == 1 && a + 1 >= p) || (l % 3 == 2 && a + 2 >= p)) {
			count2++;
		}
	}
	if (count2 > s) {
		res += count1 + s;
	} else {
		res += count1 + count2;
	}
	return res;
}

void print(int res, int j, ofstream &ouf)
{
	ouf << "Case #" << j + 1 << ": " << res << endl;
}

void init()
{
	ifstream inf(INPUT);
	ofstream ouf(OUTPUT);
	int n;
	inf >> n;

	int t, s, p;
	int total[MAXN];
	int res = 0;
	for (int i = 0; i < n; i++) {
		inf >> t >> s >> p;
		for (int j = 0; j < t; j++)
			inf >> total[j];
		res = solve(t, s, p, total);
		print(res, i, ouf);
	}
}

int main()
{
	init();

	return 0;
}


