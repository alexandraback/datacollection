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

int check(int x)
{
    int a[120];
    int n = 0;
    while (x)
    {
        a[n ++] = x % 10;
        x /= 10;
    }
    for (int i = 0; i < n/2; i ++) if (a[i] != a[n-i-1]) return 0;
    return 1;
}

int t[10000] = {0};

int main()
{
	freopen("C-small-attempt0.in" , "r" , stdin);
	//freopen("input.txt" , "r" , stdin);
	freopen("C-small-attempt0.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
    int num = 0;
    for (int i = 1; i <= 1000; i ++)
    {
        if (check(i) && check(i * i)) t[num++] = i*i;
    }

	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int A , B;
        scanf("%d %d" , &A , &B);
        int res = 0;
        for (int i = 0; i < num; i ++) if (t[i] >= A && t[i] <= B) res ++;
        printf("%d\n" , res);
    }
    return 0;
}