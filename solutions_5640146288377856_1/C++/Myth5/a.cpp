#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int f(int C, int W)
{
	if (C == W)
		return W;
	if (C <= 2 * W - 1)
		return W + 1;
	return 1 + f(C - W, W);
}

int g(int C, int W)
{		
	if (C <= 2 * W - 1)
		return 1;
	return 1 + g(C - W, W);
}

void work()
{
	int R, C, W;
	cin >> R >> C >> W;	
	cout << (R - 1) * g(C, W) + f(C, W);
}

int main()
{
    freopen("a2.in", "r", stdin);
    freopen("a2.out", "w", stdout);

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);
        work();
        printf("\n");
    }
    
    return 0;
}

