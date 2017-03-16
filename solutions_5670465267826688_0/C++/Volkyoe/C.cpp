#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"algorithm"
using namespace std;
typedef long long LL;
typedef pair<int, int> II;
int t, T;
LL L, X;
int M[][4] = {	{0,  1,  2,  3},
				{1,  0,  3,  2},
				{2,  3,  0,  1},
				{3,  2,  1,  0}};
int S[][4] = {	{1,  1,  1,  1},
				{1, -1,  1, -1},
				{1, -1, -1,  1},
				{1,  1, -1, -1}};
char s[10005];
int V[10005];
II getMul(int Mul, int Sign, LL P) {
	if (P == 0) return II(0, 1);
	if (P == 1) return II(Mul, Sign);
	int xMul = getMul(Mul, Sign, P / 2).first;
	int xSign = S[xMul][xMul];
	xMul = M[xMul][xMul];
	return (P % 2 == 0)? II(xMul, xSign): II(M[xMul][Mul], xSign * S[xMul][Mul] * Sign);
}
LL getI(int _M, int _S) {
	for (int j = 0; j < min(4LL, X); j++) {
		II TMP = getMul(_M, _S, j);
		int xMul = TMP.first, xSign = TMP.second;
		int Mul = 0, Sign = 1;
		for (int i = 0; i < L; i++) {
			Sign *= S[Mul][V[i]];
			Mul = M[Mul][V[i]];
			if (M[xMul][Mul] == 1 && xSign == S[xMul][Mul] * Sign)
				return L * j + i + 1;
		}
	}
	return L * X;
}
LL getK(int _M, int _S) {
	for (int j = 0; j < min(4LL, X); j++) {
		II TMP = getMul(_M, _S, j);
		int xMul = TMP.first, xSign = TMP.second;
		int Mul = 0, Sign = 1;
		for (int i = 1; i <= L; i++) {
			Sign *= S[V[L - i]][Mul];
			Mul = M[V[L - i]][Mul];
			if (M[Mul][xMul] == 3 && xSign == S[Mul][xMul] * Sign)
				return L * j + i;
		}
	}
	return L * X;
}
int main() {
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-small-attempt1.txt", "w", stdout);
	scanf("%d", &T);
	while (t < T) {
		scanf("%lld%lld%s", &L, &X, s);
		int Mul = 0, Sign = 1;
		for (int i = 0; i < L; i++) {
			V[i] = s[i] - 'h';
			Sign *= S[Mul][V[i]];
			Mul = M[Mul][V[i]];
		}
		//printf("Mul = %d, Sign = %d\n", Mul, Sign);
		if (getMul(Mul, Sign, X) != II(0, -1)) {
			printf("Case #%d: NO\n", ++t);
			continue;
		}
		LL makeI = getI(Mul, Sign);
		LL makeK = getK(Mul, Sign);
		//printf("%lld %lld\n", makeI, makeK);
		printf("Case #%d: %s\n", ++t, (makeI + makeK < L * X)? "YES": "NO");
	}
}
