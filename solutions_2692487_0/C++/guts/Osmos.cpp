#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

#define RT freopen("a.in", "r", stdin)
#define WT freopen("b.out", "w", stdout)
#define LL long long int
#define MAX 1000000

int A, N, Mot[MAX + 1];

//int Solve(int i) {
//	sort(Mot, Mot + N);
//	int ret = 0;
//	for(int i = 0; i < N; ++i) {
//		if(A > Mot[N - 1]) break;
//		if(A > Mot[i]) A += Mot[i];
//		else {
//			if(A != 1) A += (A - 1);
//			--i;
//			++ret; 
//		}
//	}
//	return ret;
//}

int Solve(int sum, int i) {
	if(i == N) return 0;
	if(sum > Mot[N - 1]) return 0;
	if(sum > Mot[i])
		return Solve(sum + Mot[i], i + 1);
	else {
		if(sum == 1)
			return 1 + Solve(sum, i + 1);
		return min(Solve(sum, i + 1) + 1, Solve(sum + sum - 1, i) + 1);
	}
}

int main() {
	RT, WT;
	int cases; cin >> cases;
	for(int c = 0; c < cases; ++c) {
		cin >> A >> N;
		for(int i = 0; i < N; ++i) cin >> Mot[i];
		sort(Mot, Mot + N);
		printf("Case #%d: %d\n", c + 1, Solve(A, 0));
	}
	return 0;
}