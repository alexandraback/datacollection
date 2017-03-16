#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

const int maxn = 10000 + 10;
int v[maxn];
int M, Rhp, N;

int GetMax(int L, int R)
{
	int max_id = L;
	for (int i = L; i <= R; i++)
		if (v[i] > v[max_id]) max_id = i;
	return max_id;
}

long long Min(long long A, long long B)
{
	if (A > B) return B;
	else return A;
}

long long Max(long long A, long long B)
{
	if (A < B) return B;
	else return A;
}

/* in L is now, out R >= SEx , Assume SEx >= Rhp */
unsigned long long Search(long long now, int L, int R, long long SEx)
{
	if (L > R) return 0;
	unsigned long long tmp, Q, Q2;
	if (L == R) {
		if (now - (SEx - Rhp) < 0) tmp = 0;
		else tmp = (now - (SEx - Rhp)) * v[L];
		return tmp;
	} else {
		int max_id = GetMax(L, R);
		Q = Min(M, now + Rhp * (max_id - L));

		Q2 = Max(SEx - Rhp * (R - max_id + 1), 0);
		tmp = Search(now, L, max_id - 1, Q);
		tmp += (Q - Q2) * v[max_id];
		tmp += Search(Min(M, Q2 + Rhp), max_id + 1, R, SEx);
		return tmp;
	}
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B_L.out", "w", stdout);
	
	int TextN = 0, TT = 0;
	scanf("%d", &TextN);
	while (TextN--) {
		scanf("%d%d%d", &M, &Rhp, &N);
		for (int i = 1; i <= N; i++) scanf("%d", v+i);
		if (Rhp > M) Rhp = M;
		
		cout << "Case #" << ++TT << ": " << Search(M, 1, N, Rhp) << endl;
	}
	return 0;
}