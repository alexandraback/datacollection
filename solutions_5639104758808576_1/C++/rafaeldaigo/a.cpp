#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<sstream>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int t, test;
    scanf("%d", &test);
    for (t = 0; t < test; t++)
    {
        int n;
        char count[1100];
        int resp = 0;
        int total = 0;
        scanf("%d %s", &n, count);
        for (int i = 0; i <= n; i++)
        {
            int num = count[i] - '0';
            if (total < i) {
                resp += i - total;
                total = i;
            }
            total += num;
        }
        printf("Case #%d: %d\n", t+1, resp);
    }
    return 0;
}
