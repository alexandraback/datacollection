#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("D-small-attempt0.in");
ofstream fout("D-small-attempt0.out");

#define cin fin
#define cout fout

int solve1(int n, double a[], double b[]) {
	if (n == 1) return *a > *b;
	if (*a < *b) return solve1(n - 1, a + 1, b);
	else return solve1(n - 1, a + 1, b + 1) + 1;
}

int solve2(int n, double a[], double b[]) {
	if (n == 1) return *a > *b;
	if (a[n - 1] < b[n - 1]) return solve2(n - 1, a, b);
	else return solve2(n - 1, a, b + 1) + 1;
}

void run() {
	double a[1000], b[1000];
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	for (int i = 0; i < n; ++i)
		cin>>b[i];
	sort(a, a + n);
	sort(b, b + n);
	cout<<solve1(n, a, b)<<' '<<solve2(n, a, b)<<endl;
}

int main() {
	int t;
	cin>>t;
	for (int i = 1; i <= t; ++i) {
		cout<<"Case #"<<i<<": ";
		run();
	}
	return 0;
}