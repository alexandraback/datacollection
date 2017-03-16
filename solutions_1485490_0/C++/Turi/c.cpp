#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
//#include <cmath>
#include <cstring>
#include <iostream>
//#include <map>
//#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define MAXNM 128

int N, M;

vector<long long int> a(MAXNM), b(MAXNM);
vector<int> A(MAXNM), B(MAXNM);

long long int d[MAXNM][MAXNM];

long long int d2[MAXNM][MAXNM];

long long int solve2(int i, int j);

long long int solve(int i, int j){
	if (i >= N || j >= M)
		return 0;
	
	if (d[i][j] > -1)
		return d[i][j];
	
	int t = A[i];
	long long int best = 0;
	
	long long int sum_a = 0;
	for (int k = i; k < N; k++){
		if (A[k] == t)
			sum_a += a[k];
		long long int sum_b = 0;
		for (int l = j; l < M; l++)			
			if (B[l] == t){
				sum_b += b[l];
				if (A[k] == t) {
					long long int sol = min(sum_a, sum_b) + solve2(k + 1, l + 1);
					best = max(best, sol);
				}
			}
	}

	t = B[j];

	sum_a = 0;
	for (int k = i; k < N; k++){
		if (A[k] == t)
			sum_a += a[k];
		long long int sum_b = 0;
		for (int l = j; l < M; l++)			
			if (B[l] == t){
				sum_b += b[l];
				if (A[k] == t) {
					long long int sol = min(sum_a, sum_b) + solve2(k + 1, l + 1);
					best = max(best, sol);
				}
			}
	}

	
	return d[i][j] = best;
}

long long int solve2(int i, int j){
	if (i >= N || j >= M)
		return 0;
	if (d2[i][j] > -1)
		return d2[i][j];
	
	return d2[i][j] = max(solve(i, j), max(solve2(i+1, j), solve2(i, j+1)));
}

int main(int argc, char *argv[]){
	unsigned int T;
	
	if (argc >= 2){
		freopen(argv[1], "r", stdin);
		string outstr(argv[1]);
		int dot_pos = outstr.find_last_of('.');
		outstr = outstr.substr(0, dot_pos) + ".out";
		freopen(outstr.c_str(), "w", stdout);
	}

	cin >> T;
	for (unsigned int k = 0; k < T; k++){
		cin >> N >> M;
		
		for (int i = 0; i < N; i++)
			cin >> a[i] >> A[i];
		for (int i = 0; i < M; i++)
			cin >> b[i] >> B[i];
		
		memset(d, -1, sizeof(long long int) * MAXNM * MAXNM);
		memset(d2, -1, sizeof(long long int) * MAXNM * MAXNM);
		
		cout << "Case #" << k + 1 << ": " << solve2(0, 0) << endl;
	}
	return 0;
}
