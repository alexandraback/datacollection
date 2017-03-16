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

int get(int n , int m , int k)
{
    if (n < 3 || k < 5) return k;
    if (n == 3 && m == 3)
    {
        return k - 1;
    }
    else if (n == 3 && m == 4)
    {
        if (k < 8) return k-1;
        else return k-2;
    }
    else if (n == 3 && m == 5)
    {
        if (k < 8) return k-1;
        else if (k < 11) return k-2;
        return k-3;
    }
    else if (n == 3 && m == 6)
    {
        if (k < 8) return k-1;
        else if (k < 11) return k-2;
        else if (k < 14) return k-3;
        else return k-4;
    }
    else if (n == 4 && m == 4)
    {
        if (k < 8) return k-1;
        else if (k < 10) return k-2;
        else if (k < 12) return k-3;
        else return k-4;
    }
    else if (n == 4 && m == 5)
    {
        if (k < 8) return k-1;
        else if (k < 10) return k-2;
        else if (k < 12) return k-3;
        else if (k < 14) return k-4;
        else if (k < 16) return k-5;
        return k-6;
    }
    return k;
}

int main()
{
	freopen("C-small-attempt2.in" , "r" , stdin);
	freopen("C-small-attempt2.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int m , n , k;
        scanf("%d %d %d" , &n , &m , &k);

        if (n > m) {m ^= n; n ^= m; m ^= n;}
        printf("%d\n" , get(n , m , k));
    }
    return 0;
}