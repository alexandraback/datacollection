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

#define NUM 1000000007

int check(string ss)
{
    int a[26] = {0};
    int last = -1;
    for (int i = 0; i < ss.length(); i ++)
    {
        int k = ss[i]-'a';
        if (a[k] == 0)
        {
            if (last >= 0) a[last] = 2;
            a[k] = 1; last = k;
        }
        else if (k == last && a[k] == 1)
        {

        }
        else return 0;
    }
    return 1;
}

string zip(char *s)
{
    string res = "";
    int L = strlen(s);

    res += s[0];
    for (int i = 1; i < L; i ++)
    {
        if (s[i] != s[i-1]) res += s[i];
    }
    return res;
}
int main()
{
	freopen("B-small-attempt2.in" , "r" , stdin);
	freopen("B-small-attempt2.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int n;
        char s[110][105];
        scanf("%d" , &n);
        for (int i = 0; i < n; i ++)
        {
            scanf("%s" , s[i]);
        }
        int a[10];
        int res = 0;
        int ok = 1;
        for (int i = 0; i < n; i ++)
        {
            if (check((string)s[i]) == 0) {ok = 0; break;}
        }
        if (ok == 1)
        {
            string str[110];
            for (int i = 0; i < n; i ++) str[i] = zip(s[i]);
            for (int i = 0; i < n; i ++) a[i] = i;
            do
            {
                string ss = "";
                for (int i = 0; i < n; i ++)
                {
                    ss += str[a[i]];
                }
                if (check(ss) == 1)
                {
                    res ++;
                    if (res >= NUM) res %= NUM;
                }
            }while (next_permutation( a, a + n ));
        }
        printf("%d\n" , res);

    }
    return 0;
}