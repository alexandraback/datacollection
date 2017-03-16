#include <iostream>
#include <fstream>

using namespace std;

typedef long long LL;
ifstream fin("A-small-attempt0.in");
ofstream fout("A-small-attempt0.out");

long long reverse(LL x)
{
	LL r = 0;

	while (x > 0) {
		r = r * 10 + x % 10;
		x /= 10;
	}

	return r;
}

#define MAX 1000000

long dist[MAX + 1];

void preprocess()
{
	for (int i = 1; i <= MAX; i++)
		dist[i] = i;

	for (int i = 1; i <= MAX; i++) {
		if (dist[i + 1] > dist[i] + 1)
			dist[i + 1] = dist[i] + 1;
		LL r = reverse(i);

		if (r <= MAX && dist[r] > dist[i] + 1) {
			dist[r] = dist[i] + 1;
		}
	}
}

void solve()
{

	LL n;

	fin >> n;
	fout << dist[n] << endl;
}

int main()
{
	preprocess();

	int tests, ct;

	fin >> tests;

	for (ct = 1; ct <= tests; ct++) {
		fout << "Case #" << ct << ": ";
		solve();
	}

	return 0;
}