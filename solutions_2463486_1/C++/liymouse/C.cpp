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

int check(i64d x)
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

i64d t[10000] = {1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004};

int main()
{
	freopen("C-large-1.in" , "r" , stdin);
	//freopen("input.txt" , "r" , stdin);
	freopen("C-large-1.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
    int num = 39;
    /*
    for (int i = 1; i <= 10000000; i ++)
    {
        if (check(i) && check((i64d)i * (i64d)i)) t[num++] = (i64d)i*i;
    }
    for (int i = 0; i < num; i ++) printf("%lld, " , t[i]);
    return 0;
    */
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        i64d A , B;
        scanf("%lld %lld" , &A , &B);
        int res = 0;
        for (int i = 0; i < num; i ++) if (t[i] >= A && t[i] <= B) res ++;
        printf("%d\n" , res);
    }
    return 0;
}