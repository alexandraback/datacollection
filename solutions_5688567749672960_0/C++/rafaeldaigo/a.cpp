#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<sstream>
#include<iostream>
#include<algorithm>

using namespace std;

#define MAXN 1000000
int resp[1100000];
int queue[1100000];

int invert(int a)
{
    int resp = 0;
    while (a > 0)
    {
        int last = a % 10;
        a = a/10;
        resp = 10 * resp + last;
    }
    return resp;
}

int main()
{
    for (int i = 1; i <= MAXN; i++)
    {
        resp[i] = -1;
    }
    int pos = 0;
    int size = 1;
    queue[0] = 1;
    resp[1] = 1;
    while(pos < size)
    {
        int a = queue[pos];
        if (a < MAXN)
        {
            if (resp[a + 1] == -1)
            {
                resp[a + 1] = resp[a] + 1;
                queue[size++] = a + 1;
            }
            int inv = invert(a);
            if (resp[inv] == -1)
            {
                resp[inv] = resp[a] + 1;
                queue[size++] = inv;
            }
        }
        pos++;
    }
    int t, test;
    scanf("%d", &test);
    for (t = 0; t < test; t++)
    {
        int n;
        scanf("%d", &n);

        printf("Case #%d: %d\n", t+1, resp[n]);
    }
    return 0;
}
