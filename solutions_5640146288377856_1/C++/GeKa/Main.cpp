#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <memory.h>


using namespace std;

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int R, C, W;
		cin >> R >> C >> W;
		int res = R * (C / W);
		res += W - 1;
		if (C % W != 0)
			res++;
		printf("Case #%d: %d\n", t+1, res);
	}
	return 0;
}