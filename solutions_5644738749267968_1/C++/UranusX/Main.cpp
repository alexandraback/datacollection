#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int N;
double A[1024], B[1024];

int GetAns(double* A, double* B)
{
	int Ans = 0;
	multiset <double> S;
	for (int i = 0; i < N; i ++)
		S.insert(A[i]);
	for (int i = 0; i < N; i ++)
	{
		multiset <double> :: iterator it = S.upper_bound(B[i]);
		if (it == S.end())
			continue;
		if (*it > B[i])
		{
			Ans ++;
			S.erase(it);
		}
	}
	return Ans;
}

void Work()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i ++)
		scanf("%lf", &A[i]);
	for (int i = 0; i < N; i ++)
		scanf("%lf", &B[i]);
	sort(A, A + N);
	sort(B, B + N);
	
	printf("%d %d\n", GetAns(A, B), N - GetAns(B, A));
}

int main()
{
	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w", stdout);
    int Cases;
    scanf("%d", &Cases);
    for (int Case = 1; Case <= Cases; Case ++)
    {
		printf("Case #%d: ", Case);
		Work();
    }
    return 0;
}