#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long Int64;

const int maxn = 100000;
const int maxl = 100;

int digit[maxl];
int palinRoots[maxn];
Int64 goods[maxn];
int N, pop;

bool IsGood(Int64 num) {
	int length = 0;
	for (; num; num /= 10)
		digit[length++] = num % 10;
	for (int i = 0; i < length / 2; i++)
		if (digit[i] != digit[length - 1 - i]) return false;
	return true;
}

void GeneratePalindromes(int num) {
	int length = 0;
	for (; num; num /= 10)
		digit[length++] = num % 10;
	for (int i = 0; i < length / 2; i++)
		swap(digit[i], digit[length - 1 - i]);
	// length * 2
	for (int i = 0; i < length; i++)
		digit[length + i] = digit[length - 1 - i];
	int result = 0;
	for (int i = length * 2 - 1; i >= 0; i--)
		result = result * 10 + digit[i];
	palinRoots[N++] = result;
	// length * 2 - 1
	for (int i = 1; i < length; i++)
		digit[length - 1 + i] = digit[length - 1 - i];
	result = 0;
	for (int i = length * 2 - 2; i >= 0; i--)
		result = result * 10 + digit[i];
	palinRoots[N++] = result;
}

void Init() {
	N = 0;
	for (int i = 1; i < 10000; i++)
		GeneratePalindromes(i);
	sort(palinRoots, palinRoots + N);
/*
	printf("N = %d\n", N);
	for (int i = 0; i < N; i++)
		printf(" %d", palinRoots[i]);
	printf("\n");
*/
	pop = 0;
	for (int i = 0; i < N; i++) {
		Int64 temp = palinRoots[i];
		temp *= temp;
		if (IsGood(temp)) goods[pop++] = temp;
	}
/*
	cout << pop << endl;
	for (int i = 0; i < pop; i++)
		cout << goods[i] << " ";
*/
}

int main() {
	Init();
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		Int64 A, B;
		cin >> A >> B;
		cout << upper_bound(goods, goods + pop, B) - lower_bound(goods, goods + pop, A) << endl;
	}
	return 0;
}
