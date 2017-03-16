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
	freopen("A-small-attempt0.in" , "r" , stdin);
	freopen("A-small-attempt0.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        char s[1010];
        scanf("%s" , s);
        string res = "";
        res += s[0];

        for (int i = 1; i < strlen(s); i ++)
        {
            if (s[i] >= res[0]) res = s[i] + res;
            else res = res + s[i];
        }
        printf("%s\n" , res.c_str());
    }
    return 0;
}