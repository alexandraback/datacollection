#include <stdio.h>

#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
#include "assert.h"
#include <set>
#include <vector>
#include <xutility>
using namespace std;
char buffer[1000*1000+2];
bool isconsonants[256];
void init()
{
    for (int i=0; i<256; i++)
        isconsonants[i] = true;
    isconsonants['a'] = false;
    isconsonants['e'] = false;
    isconsonants['i'] = false;
    isconsonants['o'] = false;
    isconsonants['u'] = false;
}
long long int solve_one()
{
    int n;int length;
    scanf(" %s %d", buffer, &n);
    length = strlen(buffer);
    int count = 0;
    long long int total = 0, num = 0;
    for (int i=length-1; i>=0; i--)
    {
        if (isconsonants[buffer[i]])
            count ++;
        else count = 0;
        if (count >= n)
            num = length-i-n+1;
        total += num;
    }
    return total;
}
int main(int argc, char**argv)
{
    freopen("D:\\3.in", "r+", stdin);
    freopen("D:\\out.txt", "w+", stdout);
    int T;
    init();
    scanf("%d", &T);
    for (int i=1; i<=T; i++)
    {
        printf("Case #%d: %d\n", i, solve_one());
    }
    return 0;
}