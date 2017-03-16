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
	freopen("B-large.in" , "r" , stdin);
	freopen("B-large.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d:" , ca);
        int a[2600] = {0};
        int n;
        vector<int> b;
        scanf("%d" , &n);
        for (int i = 0; i < 2 * n - 1; i ++)
        {
            int x;
            for (int i = 0; i < n; i ++)
            {
                scanf("%d" , &x);
                a[x] ++;
            }
        }
        for (int i = 0; i < 2600; i ++)
            if (a[i] % 2 == 1) b.push_back(i);
        sort(b.begin() , b.end());
        for (int i = 0; i < b.size(); i ++)
            printf(" %d" , b[i]);
        printf("\n");
    }
    return 0;
}