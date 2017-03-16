#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

char A[128];
char B[128];
int AA[128];
int BB[128];
int CC[128];
int DD[128];

int check(Int a)
{
	stringstream ss;
	ss << a;
	string s = ss.str();
	string t = s;
	reverse(ALL(t));
	return s == t ? 1 : 0;
}

int find(Int a, Int b)
{
	Int i;
	int res = 0;
	for(i = 1; i*i <= b; ++i)
		if(a <= i*i && check(i) != 0 && check(i*i) != 0)
			++res;

	return res;
}

int cmp(int A[], int B[])
{
	int i;
	RFOR(i, 128, 1)
		if(A[i] != B[i])
			break;

	return A[i] < B[i] ? 1 : 0;
}

int f(int pos, int len)
{
	int i, j;
	FOR(i, 0, len + len)
		if(DD[i] > 9)
			return 0;

	int rev = len - 1 - pos;
	if(pos > rev)
		return (cmp(DD, AA) == 0 && cmp(BB, DD) == 0) ? 1 : 0;

	int res = 0;
	for(int i = (pos == 0 ? 1 : 0); i*i < 10; ++i)
	{
		CC[pos] = i;
		CC[rev] = i;

		FOR(j, 0, len)
			if(j <= pos || rev <= j)
			{
				DD[j + pos] += CC[j]*CC[pos];
				if(pos != rev)
					DD[j + rev] += CC[j]*CC[rev];
			}

		res += f(pos + 1, len);

		FOR(j, 0, len)
			if(j <= pos || rev <= j)
			{
				DD[j + pos] -= CC[j]*CC[pos];
				if(pos != rev)
					DD[j + rev] -= CC[j]*CC[rev];
			}
	}

	return res;
}
int SolveTest(int test)
{
	scanf("%s%s", A, B);

	//Int a, b;
	//sscanf(A, "%lld", &a);
	//sscanf(B, "%lld", &b);
	//int r = find(a, b);

	int aLen = strlen(A);
	int bLen = strlen(B);

	reverse(A, A + aLen);
	reverse(B, B + bLen);

	CLEAR(AA, 0);
	CLEAR(BB, 0);
	CLEAR(CC, 0);
	CLEAR(DD, 0);

	int i;
	FOR(i, 0, aLen)
		AA[i] = A[i] - '0';
	FOR(i, 0, bLen)
		BB[i] = B[i] - '0';

	int res = 0;
	for(i = 1; i + i - 1 <= bLen; ++i)
		res += f(0, i);

	//if(res != r)
	//	throw 0;

	printf("Case #%d: %d\n", test + 1, res);
	return 0;
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);

	int T, t;
	char buf[1 << 7];
	gets(buf);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
	{
		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
		SolveTest(t);
	}

	return 0;
};
