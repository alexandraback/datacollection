//Problem: Google Code Jam 2013 Round 1A B
//Name: Manage your Energy
//Author: Bruce K. B. Tong
//Tag: DP, Unbounded Knapsack (variation)

#include <cstdio>
#include <iostream>
//#include <vector>
//#include <algorithm>

using namespace std;

#define SMALL
//#define LARGE

#define N_SIZE 10000
//#define E_SIZE 10000000	//for large dataset
#define E_SIZE 5			//for small dataset

#define a2d(a, h, w) for(int i=0; i<(int)(h); i++) {for(int j=0; j<(int)(w); j++) cout << a[i][j] << " "; cout << endl;}

int f[N_SIZE+1+1][E_SIZE+1];

void read(int &E, int &R, int &N, int v[]) {
	cin >> E >> R >> N;
	for (int i = 1; i <= N; i++)
		cin >> v[i];			//note: v is 1-indexed array
}

void print(int E, int R, int N, int v[]) {
	cout << E << " " << R << " " << N << endl;;
	for (int i = 1; i <= N; i++)
		cout << v[i] << " ";
	cout << endl;
}

int solve(int E, int R, int N, int v[]) {
	for (int i = 0; i <= N+1; i++)
		for (int j = 0; j <= E; j++)
			f[i][j] = 0;
	/*
	for (int i = 0; i <= N+1; i++)
		f[i][0] = 0;
	for (int i = 0; i <= E; i++)
		f[N+1][i] = 0;
		*/
	for (int i = N; i > 0; i--)
		for (int j = E; j >= R; j--) {
			f[i][j] = f[i+1][min(j+R,E)];
			for (int k = max(0, j+R-E); k <= j; k++)
				f[i][j] = max(f[i][j], f[i+1][min(j-k+R,E)]+k*v[i]);
		}
	return f[1][E];
}
/*
int solve(int E, int R, int N, int v[]) {
	for (int i = 0; i < N; i++)
		f[i][0] = 0;
	for (int i = 0; i < E; i++)
		f[0][i] = 0;
	for (int i = 1; i <= N; i++)
		for (int j = R; j <= E; j++)
			for (int k = 0; k <= j; k++)
				f[i][j] = max(f[i-1][min(j+R,E)], f[i-1][min(j-k+R, E)]+k*v[i]);
			
			//if (j < v[i])
			//	f[i][j] = f[i-1][min(E, j+R)];
			//else
			//	f[i][j] = max(f[i-1][j], f[i-1][min(E, j+R-1)]+v[i]);
			
	return f[N][E];
}*/

int main() {
	freopen("B-sample.in", "rt", stdin);
	#ifdef SMALL
		freopen("B-small-attempt3.in", "rt", stdin);
		freopen("B-small-attempt3.out", "wt", stdout);
	#endif
	#ifdef LARGE
		freopen("B-large.in", "rt", stdin);
		freopen("B-large.out", "wt", stdout);
	#endif

	int T;				//1 <= T <= 100
	int E;				//1 <= E <= 5 (or 10^7)
	int R;				//1 <= R <= 5 (or 10^7)
	int N;				//1 <= N <= 10 (or 10^4)
	int v[N_SIZE+1];
	
	cin >> T;
	for (int i = 1; i <= T; i++) {
		read(E, R, N, v);
		//print(E, R, N, v);
		cout << "Case #" << i << ": ";
		cout << solve(E, R, N, v);
		cout << endl;
		//a2d(f, N+1+1, E+1);
	}
	return 0;
}