#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
typedef long long ll;

ll dyn[120][120];
pll A[120], B[120];

void countDyn(int ASize, int BSize)
{
	for (int i = 0; i < 110; i++)
	{
		dyn[i][0] = 0;
		dyn[0][i] = 0;
	}
	
	for (int i = 1; i <= ASize; i++)
	{
		ll maxCount = 0;
		for(int j = 1; j <= BSize; j++)
		{
			int curSkip = i;
			ll curACount = A[i].second;
			for (int k = 0; k != -1; )
			{
				ll curBCount = 0;
				ll tmax = 0;
				for (int l = 0; l < j; l++)
				{
					if (A[i].first == B[j-l].first)
						curBCount +=B[j-l].second;
					tmax = max(dyn[curSkip-1][j-l-1] + min(curBCount, curACount), tmax);
					if (curBCount >= curACount)
						break;
				}
				dyn[i][j] = max(dyn[i][j], tmax);
				k = -1;
				for (int p = curSkip - 1; p > 0; p--)
				{
					if (A[p].first == A[i].first)
					{
						curSkip = p;
						k = 0;
						curACount += A[p].second;
					}
				}
			}
			dyn[i][j] = max(dyn[i][j], dyn[i-1][j]);
			dyn[i][j] = max(dyn[i][j], dyn[i][j-1]);
		}
	}
}

void test(int testNo)
{
	memset(dyn, -1, sizeof(dyn));

	ll ASize, BSize;
	scanf("%lld%lld", &ASize, &BSize);

	ll ta, tb;
	for (int i = 0; i < ASize; i++)
	{
		scanf("%lld%lld", &ta, &tb);
		A[i+1].first = tb;
		A[i+1].second = ta;
	}

	for (int i = 0; i < BSize; i++)
	{
		scanf("%lld%lld", &ta, &tb);
		B[i+1].first = tb;
		B[i+1].second = ta;
	}

	countDyn(ASize, BSize);

    printf("Case #%d: ", testNo+1);
	cout << dyn[ASize][BSize] << endl;
    
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int TC;
    scanf("%d", &TC);
    
    for (int i = 0; i < TC; i++)
        test(i);
    
    return 0;
}