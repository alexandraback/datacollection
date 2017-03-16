//Problem: Google Code Jam 2014 Qualification Round D
//Name: Deceitful War
//Author: Bruce K. B. Tong
//Tag: Sorting, Greedy

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define SMALL
//#define LARGE

#define N_SIZE 1000

void read(int &N, double a[], double b[]) {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < N; i++)
		cin >> b[i];
}

void solve(int N, double a[], double b[], int &ans1, int &ans2) {
	sort(a, a+N);
	sort(b, b+N);
	int i = 0, j = 0;
	while (i < N && j < N) {
		if (a[i] < b[j]) i++;
		j++;
	}
	ans2 = N - i;

	int j_max = N;
	ans1 = i = j = 0;
	while (i < N && j < j_max) {
		if (a[i] > b[j]) {
			j++;
			ans1++;
		} else
			j_max--;
		i++;
	}
}

int main() {
	freopen("D-sample.in", "rt", stdin);
	#ifdef SMALL
		freopen("D-small-attempt0.in", "rt", stdin);
		freopen("D-small-attempt0.out", "wt", stdout);
	#endif
	#ifdef LARGE
		freopen("D-large.in", "rt", stdin);
		freopen("D-large.out", "wt", stdout);
	#endif

	int T;		//1 <= T <= 50
	int N;		//1 <= N <= 10 (or 1,000)
	double a[N_SIZE];	//0.0 < a[i] < 1.0
	double b[N_SIZE];	//0.0 < b[i] < 1.0
	int ans1, ans2;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		read(N, a, b);
		cout << "Case #" << i << ": ";
		solve(N, a, b, ans1, ans2);
		cout << ans1 << " " << ans2;
		cout << endl;
	}
	return 0;
}