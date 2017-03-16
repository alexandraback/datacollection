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

Int A[1 << 10];
Int B[1 << 10];
Int C[1 << 10];


int SolveTest(int test)
{
	int n;
	scanf("%d", &n);

	int i;
	FOR(i, 0, n)
		scanf("%lld", &C[i]);

	sort(C, C + n);

	Int sum = -1;
	int aCnt = 0;
	int bCnt = 0;

	while(sum != 0)
	{
		sum = 0;
		aCnt = 0;
		bCnt = 0;
		random_shuffle(C, C + n);
		RFOR(i, n, 0)
		{
			if(sum == 0 && aCnt + bCnt != 0)
				break;

			if(sum < 0)
			{
				A[aCnt] = C[i];
				++aCnt;
				sum += C[i];
			}
			else
			{
				B[bCnt] = C[i];
				++bCnt;
				sum -= C[i];
			}
		}
	}
	
	printf("Case #%d:\n", test + 1);
	sum = 0;
	FOR(i, 0, aCnt)
		sum += A[i];
	FOR(i, 0, bCnt)
		sum -= B[i];

	if(sum != 0)
		fprintf(stderr, "Case #%d: Error! sum = %lld\n", test + 1, sum);

	FOR(i, 0, aCnt)
	{
		printf("%lld", A[i]);
		if(i == aCnt - 1)
			printf("\n");
		else
			printf(" ");
	}

	FOR(i, 0, bCnt)
	{
		printf("%lld", B[i]);
		if(i == bCnt - 1)
			printf("\n");
		else
			printf(" ");
	}

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
