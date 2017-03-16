#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("C.in");
ofstream fout("C.out");

long long int T, A, B;
int ans;

long long int make_palin(long long int N, bool even) {
	int cijfers[100];
	int L = 0;
	while (N > 0) {
		cijfers[L] = N%10;
		N = N /10;
		L++;
	}
	long long int sol = 0;
	for (int i = L-1; i >= 0; i--)
		sol = 10*sol + cijfers[i];
	if (even)
		sol = 10*sol + cijfers[0];
	for (int i = 1; i < L; i++)
		sol = 10*sol + cijfers[i];
	return sol;
}

bool is_palin(long long int N) {
	int cijfers[100];
	int L = 0;
	while (N > 0) {
		cijfers[L] = N%10;
		N = N /10;
		L++;
	}
	for (int i = 0; i < L; i++)
		if (cijfers[i] != cijfers[L-1-i])
			return false;
	return true;
}

int main() {
	fin >> T;
	for (int t = 1; t <= T; t++) {
		fin >> A >> B;
		ans = 0;
		for (long long int i = 1; i <= 30000; i++) {
			long long int X = make_palin(i,false);
			long long int X2 = X*X;
			if ((A <= X2) and (X2 <= B))
			if (is_palin(X*X))
			ans++;
			
			X = make_palin(i,true);
			X2 = X*X;
			if ((A <= X2) and (X2 <= B))
			if (is_palin(X*X))
			ans++;		
		}
		fout << "Case #" << t << ": " << ans << "\n";
	}
	return 0;
}

