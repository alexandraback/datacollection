#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <memory>

using namespace std;
using ll = long long;

#define LIM 51
int A[LIM][LIM];

void SolveCase(int caseId);

int main()
{
	for(int i = 2; i < LIM; ++i)
		for(int j = i+1; j < LIM; ++j)
			A[i][j] = 1;

	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i)
		SolveCase(i);
	return 0;
}

void SolveCase(int caseId)
{
	printf("Case #%d: ", caseId);
	ll B;
	ll M;
	scanf("%lld%lld", &B, &M);
	int maxWays = 1ll<<(B-2);
	bool isPossible = maxWays >= M;
	if(!isPossible)
	{
		puts("IMPOSSIBLE");
		return;
	}
	puts("POSSIBLE");
	if(maxWays == M)
		for(int i = 2; i <= B; ++i)
			A[1][i] = 1;
	else
	{
		A[1][B] = 0;
		for(int i = B-1; i > 0; --i, M >>= 1)
			A[1][i] = M&1;
	}
	
	for(int i = 1; i <= B; ++i, puts(""))
		for(int j = 1; j <= B; ++j)
			printf("%d", A[i][j]);
}

