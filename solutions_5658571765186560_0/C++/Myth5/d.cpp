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

bool work()
{
	int X, R, C;
	cin >> X >> R >> C;
	if (R > C)
		swap(R, C);
	if (R * C % X != 0)
		return false;
	if (R < (X + 1) / 2)
		return false;
	if (R == 2 && C == 4 && X == 4)
		return false;
	return true;
}

int main()
{
    freopen("d1.in", "r", stdin);
    freopen("d1.out", "w", stdout);

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);        
        printf("%s\n", work() ? "GABRIEL" : "RICHARD");
    }
    
    return 0;
}

