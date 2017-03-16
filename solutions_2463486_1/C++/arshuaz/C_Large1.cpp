#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<long long> FS;

bool IsPalindrome(long long N) {
	string S;

	while(N > 0) {
		S += (char)(N%10);
		N /= 10;
	}

	int head = 0;
	int tail = (int)S.size() - 1;
	while(head < tail) {
		if(S[head] != S[tail]) return false;
		head++; tail--;
	}

	return true;
}

int main() {
	for(long long i=1; i<=10000000; i++) {
		if(IsPalindrome(i) && IsPalindrome(i*i)) FS.push_back(i*i);
	}

	freopen("C_Large1.in", "r", stdin);
	freopen("C_Large1.out", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int TC=1; TC<=T; TC++) {
		long long a, b;
		long long ret = 0;
		scanf("%lld %lld\n", &a, &b);
		for(int i=0; i<FS.size(); i++) {
			if(a <= FS[i] && FS[i] <= b) ret++;
		}
		printf("Case #%d: %d\n", TC, ret);
	}
}