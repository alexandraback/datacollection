//Problem: Google Code Jam 2013 Qualification Round B
//Name: Lawnmower
//Author: Bruce K. B. Tong
//Tag: Ad Hoc

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define SMALL
//#define LARGE

void read(int &N, int &M, int a[100][100]) {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> a[i][j];
}

void print(int N, int M, int a[100][100]) {
	cout << N << " " << M << endl;
	for (int i = 0; i < N; i++, cout << endl)
		for (int j = 0; j < M; j++)
			cout << a[i][j];
	cout << endl;
}

int solve(int N, int M, int a[100][100]) {
	int row[100] = {0}, col[100] = {0};
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			row[i] = max(row[i], a[i][j]);
			col[j] = max(col[j], a[i][j]);
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) 
			if (a[i][j] < row[i] && a[i][j] < col[j]) return 0;
	return 1;
}

int main() {
	freopen("B-sample.in", "rt", stdin);
	#ifdef SMALL
		freopen("B-small-attempt0.in", "rt", stdin);
		freopen("B-small-attempt0.out", "wt", stdout);
	#endif
	#ifdef LARGE
		freopen("B-large.in", "rt", stdin);
		freopen("B-large.out", "wt", stdout);
	#endif

	int T;				//1 <= T <= 100
	int N, M;			//1 <= N, M <= 10 (or 100)
	int a[100][100];
	
	cin >> T;
	for (int i = 1; i <= T; i++) {
		read(N, M, a);
		//print(N, M, a);
		cout << "Case #" << i << ": ";
		int ans = solve(N, M, a);
		if (ans)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
	return 0;
}