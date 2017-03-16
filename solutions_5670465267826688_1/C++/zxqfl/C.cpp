#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define ever ;;
#define foreach(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)
#define LINF ((ll) 1e16)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rlong(x);
#define rfloat(x) scanf("%lf", &(x))

const int MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int table[8][8];
const int k1 = 0;
const int kI = 2;
const int kJ = 4;
const int kK = 6;

int str[50000];
char baseStr[50000];
int L, baseL;
ll X, spare;
int ALL[10000];
int dp[40000][3][8][8];

int f(int p, int stage, int quat, int sp)
{
	if (p == L) return stage == 2 && quat == kK && sp == 0;
	int& ans = dp[p][stage][quat][sp];
	if (ans >= 0) return ans;
	ans = 0;
	if (stage == 0 && quat == kI)
		ans |= f(p, 1, k1, sp);
	if (stage == 1 && quat == kJ)
		ans |= f(p, 2, k1, sp);
	if (sp)
		ans |= f(p, stage, table[quat][ALL[p % baseL]], sp - 1);
	ans |= f(p + 1, stage, table[quat][str[p]], sp);
	return ans;
}

int main()
{
	table[k1][k1] = k1;
	table[k1][kI] = kI;
	table[k1][kJ] = kJ;
	table[k1][kK] = kK;

	table[kI][k1] = kI;
	table[kI][kI] = k1 ^ 1;
	table[kI][kJ] = kK;
	table[kI][kK] = kJ ^ 1;

	table[kJ][k1] = kJ;
	table[kJ][kI] = kK ^ 1;
	table[kJ][kJ] = k1 ^ 1;
	table[kJ][kK] = kI;

	table[kK][k1] = kK;
	table[kK][kI] = kJ;
	table[kK][kJ] = kI ^ 1;
	table[kK][kK] = k1 ^ 1;
	jij(8, 8)
	{
		int a = i % 2;
		int b = j % 2;
		if (a && b)
			table[i][j] = table[i^1][j^1];
		else if (a)
			table[i][j] = table[i^1][j] ^ 1;
		else if (b)
			table[i][j] = table[i][j^1] ^ 1;
	}

	nrint(T);
	jjl(test, T)
	{
		rint(L);
		rlong(X);
		scanf("%s", baseStr);
		ji(L)
		{
			if (baseStr[i] == 'i')
				str[i] = kI;
			else if (baseStr[i] == 'j')
				str[i] = kJ;
			else
				str[i] = kK;
		}
		spare = 0;
		if (X < 3)
			spare = 0;
		else
		{
			spare = X - 3;
			X = 3;
		}
		baseL = L;
		for (int i = L; i < L * X; i++)
			str[i] = str[i - L];
		L *= X;
		ji(baseL)
		{
			ALL[i] = k1;
			jj(baseL) ALL[i] = table[ALL[i]][str[(i+j)%baseL]];
		}
		spare %= 8;
		memset(dp, -1, sizeof dp);
		printf("Case #%d: %s\n", test + 1, f(0, 0, k1, spare) ? "YES" : "NO");
		fprintf(stderr, "Case #%d: %s\n", test + 1, f(0, 0, k1, spare) ? "YES" : "NO");
	}
}