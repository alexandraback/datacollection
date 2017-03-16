#define INPUT "test.in"
#define OUTPUT "test.out"
#define MAXN 2000000

#include <fstream>
// #include <iostream>

using namespace std;

int get_digit_count(int a)
{
	int count = 0;
	do {
		count++;
	} while ((a /= 10) > 0);
	return count;
}

int solve(int a, int b)
{
	int res = 0, s;
	int l = get_digit_count(a);
	int ten[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
	
	const int max_n = b;
	int matched[max_n + 1];

	for (int i = a; i <= b; i++) matched[i] = -1;

	for (int i = a; i <= b; i++) {
		for (int t = 1; t < l; t++) {
			s = i % ten[t] * ten[l - t] + i / ten[t];
			if (s > i && s <= b && matched[s] != i) {
				matched[s] = i;
				res++;
			}
		}
	}

	return res;
}

void print(int res, int i, ofstream &ouf)
{
	ouf << "Case #" << i << ": " << res << endl;
}

void work()
{
	int t, a, b, res;
	ifstream inf(INPUT);
	ofstream ouf(OUTPUT);

	inf >> t;
	for (int i = 0; i < t; i++) {
		inf >> a >> b;
		res = solve(a, b);
		print(res, i + 1, ouf);
	}
}

int main()
{
	work();
	return 0;
}

