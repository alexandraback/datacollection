#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

int R, C, W;

inline void init()
{
	scanf("%d %d %d", &R, &C, &W);
}

int solve()
{
	int i, ans = 0;

	if(W==1)
		return R*C;

	for(i=C-W; i>0; i-=W)
		ans++;
	ans *= R;

	return ans + W;
}

int main()
{
	int T, i;

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d", &T);

	for(i=1; i<=T; i++)
	{
		init();
		printf("Case #%d: %d\n", i, solve());
	}

	return 0;
}