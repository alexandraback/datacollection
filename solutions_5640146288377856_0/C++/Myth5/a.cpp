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

int f(int N, int M)
{
	if (N == M)
		return M;
	if (N <= 2 * M - 1)
		return M + 1;
	return 1 + f(N - M, M);
}

void work()
{
	int R, C, W;
	cin >> R >> C >> W;
	cout << f(C, W);
}

int main()
{
    freopen("a1.in", "r", stdin);
    freopen("a1.out", "w", stdout);

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);
        work();
        printf("\n");
    }
    
    return 0;
}

