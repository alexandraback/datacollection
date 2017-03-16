#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("B-large.in");
ofstream fout("B-large.out");

#define cin fin
#define cout fout

long long solve(int A, int B, int K) {
	int mask;
	for (mask = 1; ; mask *= 2)
		if (mask > A && mask > B && mask > K) break;
	if (K + 1 == mask) return (long long)(A + 1) * (B + 1);
	mask /= 2;
	if (mask == 0) return 1;
	long long ret = 0;
	if (mask <= K) {
		if ((mask & A) && (mask & B)) ret += solve(A - mask, B - mask, K - mask);
		K = mask - 1;
	}
	if (mask <= A) {
		if (mask <= B) ret += solve(A - mask, mask - 1, K);
		else ret += solve(A - mask, B, K);
		A = mask - 1;
	}
	if (mask <= B) {
		ret += solve(A, B - mask, K);
		B = mask - 1;
	}
	ret += solve(A, B, K);
	return ret;
}

void run() {
	int A, B, K;
	cin>>A>>B>>K;
	int ans = 0;
	cout<<solve(A - 1, B - 1, K - 1)<<endl;
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