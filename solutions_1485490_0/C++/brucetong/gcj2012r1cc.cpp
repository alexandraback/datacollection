//Problem: GCJ 2012 Round 1C C
//Name: Box Factory
//Author: Bruce K. B. Tong

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <list>

using namespace std;

#define SMALL
//#define LARGE

#define SIZE 100

#define INF 1.0E+15	//for double
#define a1d(a, n) for(int i=0; i<(int)(n); i++) {cout << a[i]; cout << endl;} cout << endl;
#define a2d(a, h, w) for(int i=0; i<(int)(h); i++) {for(int j=0; j<(int)(w); j++) cout << a[i][j] << " " ; cout << endl;}
#define lf(it,l) for(it=l.begin(); it!=l.end(); ++it) {cout << *it << " ";} cout << endl;
#define lr(rit,l) for(rit=l.rbegin(); rit!=l.rend(); ++rit) {cout << *rit << " ";} cout << endl;
#define mem(a,b) memset(a,b,sizeof(a))

long long f[SIZE+1][SIZE+1];

void read(int &N, int &M, long long a[SIZE], int A[SIZE], long long b[SIZE], int B[SIZE]) {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> a[i] >> A[i];
	for (int i = 0; i < M; i++)
		cin >> b[i] >> B[i];
}

long long compute(int N, int M, long long a[SIZE], int A[SIZE], long long b[SIZE], int B[SIZE]) {
	for (int i = 0; i <= N; i++)
		f[i][0] = 0;
	for (int j = 0; j <= M; j++)
		f[0][j] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (A[i-1] == B[j-1]) {
				long long num = min(a[i-1], b[j-1]);
				a[i-1] -= num;
				b[j-1] -= num;
				f[i][j] = num + max(max(f[i-1][j-1], f[i][j-1]), f[i-1][j]);
				/*
				if (a[i-1] == 0)
					f[i][j] = num + max(f[i-1][j-1], f[i][j-1]);
				else
					f[i][j] = num + max(f[i-1][j-1], f[i-1][j]);
				*/
			} else {
				f[i][j] = max(f[i-1][j], f[i][j-1]);
			}
		}
	}
	return f[N][M];
}

int main() {
	freopen("C-sample.in", "rt", stdin);
	#ifdef SMALL
		freopen("C-small-attempt1.in", "rt", stdin);
		freopen("C-small-attempt1.out", "wt", stdout);
	#endif
	#ifdef LARGE
		freopen("C-large.in", "rt", stdin);
		freopen("C-large.out", "wt", stdout);
	#endif

	int T;					//1 <= T <= 100
	long long a[SIZE];		//1 <= a[i], b[i] <= 10^16
	long long b[SIZE];
	int A[SIZE];			//1 <= A[i], B[i] <= 100
	int B[SIZE];
	int N;					//1 <= N <= 3 (or 100)
	int M;					//1 <= M <= 100

	cin >> T;

	for (int i = 1; i <= T; i++) {
		read(N, M, a, A, b, B);
		cout << "Case #" << i << ": ";
		mem(f, 0);
		cout << compute(N, M, a, A, b, B);
		cout << endl;
	}
	
	return 0;
}