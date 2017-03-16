#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <iostream>
#include <functional>

using namespace std;

int Init, N;
int Size[105];

void Work(int Case)
{
	scanf("%d%d", &Init, &N);
	for (int i = 0; i < N; i ++)
		scanf("%d", &Size[i]);
	sort(Size, Size + N);
	int Ans = N;
	for (int i = 0; i <= N; i ++)
	{
		int Step = (N - i), Cur = Init;
		for (int j = 0; j < i; j ++)
		{
			while (Cur <= Size[j] && Step <= Ans)
			{
				Cur = Cur * 2 - 1;
				Step ++;
			}
			Cur += Size[j];
		}
		if (Step < Ans)
			Ans = Step;
	}
	printf("Case #%d: %d\n", Case, Ans);
}

int main()
{
	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);

	int Cases;
	scanf("%d", &Cases);
	for (int Case = 1; Case <= Cases; Case ++)
		Work(Case);
	return 0;
}