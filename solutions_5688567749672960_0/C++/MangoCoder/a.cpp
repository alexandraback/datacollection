#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int M[1000001];

int rev(int i) {
	int j = 0;
	while (i) {
		j = j*10 + i%10;
		i = i/10;
	}
	return j;
}
int main() {
	int j;
	M[1] = 1;
	for (int i = 2; i <= 1000000; ++i) {
		j = rev(i);
		if (i%10 == 0 || j >= i) {
			M[i] = M[i-1] + 1;
		}
		else 
			M[i] = min(M[j], M[i-1]) + 1;
	}
	
	int T; cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		long long int N; cin >> N;
		cout << M[N] << endl;
		
	}
	return 0;
}
