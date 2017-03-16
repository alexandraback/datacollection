#include <fstream>

using namespace std;

ifstream in("c.in");
ofstream out("c.out");

const int N = 101;

int n, m;
int at[N];
long long anr[N];
int bt[N];
long long bnr[N];
long long best;

void readCase() {
	best = 0;

	in >> n >> m;

	for (int i = 1; i <= n; ++i)
		in >> anr[i] >> at[i];

	for (int i = 1; i <= m; ++i)
		in >> bnr[i] >> bt[i];
}

inline long long min(long long a, long long b) {
	return (a<b ? a:b);
}

void solveCase(int a, long long al, int b, long long bl, long long till) {
	if (till > best)
		best = till;

	if (a > n || b > m)
		return;

	for (int i = a; i <= n; ++i)
		if (at[i] == bt[b]) {
			long long cal = anr[i];
			long long val = min(cal, bl);
			cal -= val;
			bl -= val;

			if (cal == 0 && bl)
				solveCase(i + 1, anr[i+1], b, bl, till + val);
			else if (cal && bl == 0)
				solveCase(i, cal, b + 1, bnr[b+1], till + val);
			else if (cal==0 && bl == 0)
				solveCase(i+1, anr[i+1], b+1, bnr[b+1], till + val);
			else
				solveCase(i, cal, b, bl, till + val);
			break;
		}

	for (int i = b; i <= m; ++i)
		if (at[a] == bt[b]) {
			long long cbl = bnr[i];
			long long val = min(al, cbl);
			al -= val;
			cbl -= val;

			if (al == 0 && cbl)
				solveCase(a+1, anr[a+1], i, cbl, till + val);
			else if (al && cbl == 0)
				solveCase(a, al, i + 1, bnr[i+1], till + val);
			else if (al == 0 && cbl == 0)
				solveCase(a+1, anr[a+1], i+1, bnr[i+1], till + val);
			else
				solveCase(a, al, i, cbl, till + val);
			break;
		}

	solveCase(a+1, anr[a+1], b+1, bnr[b+1], till);
}

int main() {
	int t;
	in >> t;

	for (int i = 1; i <= t; ++i) {
		readCase();

		solveCase(1, anr[1], 1, bnr[1], 0);
		out << "Case #" << i << ": " <<  best << "\n";
	}
	return 0;
}
