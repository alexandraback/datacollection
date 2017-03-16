#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
void solve(int T)
{
	int A,B,K;
	scanf("%d%d%d", &A, &B, &K);
	int ans = 0;
	int sub = 0;
	for(int i = 0; i < A; i ++)
		for(int j = 0; j < B; j ++)
		{
			int newval = i & j;
			if(newval < K) 
			{
				ans ++;
			}
		}
	printf("Case #%d: %d\n", T, ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; i ++)
		solve(i);
	return 0;
}
