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

typedef struct {
    int x , y , s , t , f;
}Point;

Point q[10000];

int main()
{
    int f[4][2] = {{-1 , 0} , {0 , -1} , {1 , 0} , {0 , 1}};
	freopen("B-small-attempt1.in" , "r" , stdin);
	freopen("B-small-attempt1.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int x , y;
        scanf("%d %d" , &x , &y);
        char res[501];
        int L = 0;
        if (x > 0)
        {
            for (int i = 0; i < x; i ++)
            {
                res[L++] = 'W';
                res[L++] = 'E';
            }
        }
        else if (x < 0)
        {
            for (int i = 0; i < -x; i ++)
            {
                res[L++] = 'E';
                res[L++] = 'W';
            }
        }
        if (y > 0)
        {
            for (int i = 0; i < y; i ++)
            {
                res[L++] = 'S';
                res[L++] = 'N';
            }
        }
        else if (y < 0)
        {
            for (int i = 0; i < -y; i ++)
            {
                res[L++] = 'N';
                res[L++] = 'S';
            }
        }
        res[L] = 0;
        printf("%s\n" , res);
    }
    return 0;
}