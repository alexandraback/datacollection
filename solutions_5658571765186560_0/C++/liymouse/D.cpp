#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

typedef long long i64d;

using namespace std;

int main()
{
	freopen("D-small-attempt1.in" , "r" , stdin);
	freopen("D-small-attempt1.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int x , m , n;
        scanf("%d %d %d" , &x , &m , &n);
        if (m > n) swap(m , n);
        int res = 0;
        if (x == 1) res = 1;
        else if (x == 2)
        {
            if ((m * n) % 2 == 0) res = 1;
            else res = 0;
        }
        else if (x == 3)
        {
            if (m == 1) res = 0;
            else if ((m * n) % 3 == 0) res = 1;
            else res = 0;
        }
        else if (x == 4)
        {
            if (m <= 2) res = 0;
            else if ((m * n) % 4 == 0) res = 1;
            else res = 0;
        }
        else res = 0;
        if (res == 0) printf("RICHARD\n");
        else printf("GABRIEL\n");
    }
    return 0;
}