#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
using namespace std;



int find(long long p, long long q) {
	int cnt = 1;
	int qq = q;
	while ((qq % 2 == 0) && (qq > 2)) {
		qq /= 2;
		cnt++;
	}
	if (qq > 2)
		return -1;

	int c = 0;
	for (int i = 0; i < cnt; i++) {
		if (p > q / 2) {
			return c + 1;
		}
		else {
			c++;
			q /= 2;
		}
	}
	return c;
}

void frac(long long &p, long long &q) {
	while ((p % 2 == 0) && (q % 2 == 0)) {
		p /= 2;
		q /= 2;
	}
	if (q % p == 0) {
		q /= p;
		p = 1;
		return;
	}
	for (long long div = 3; div < sqrt(p); div += 2) {
		if (p % div == 0) {
			long long qua = p / div;
			while (q % div == 0) {
				p /= div;
				q /= div;
			}
			while (q % qua == 0) {
				p /= qua;
				q /= qua;
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int CaseNum;
	cin >> CaseNum;
	for (int Case = 1; Case <= CaseNum; Case++)
	{
		cout << "Case #" << Case << ": ";
		fprintf(stderr, "Case #%d\n", Case);

		long long p, q;
		char trash;
		cin >> p >> trash >> q;

		frac(p, q);
		int result = find(p, q);
		if (result == -1)
			cout << "impossible" << endl;
		else
			cout << result << endl;
	}
}