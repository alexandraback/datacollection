#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <string.h>
#include <map>

using namespace std;

void resolver(int caso)
{
    int r, c, w, re, p;
    scanf("%d %d %d", &r, &c, &w);
    re = c/w*r+w-1;
    if(c%w>0)
        re++;
    printf("Case #%d: %d\n", caso, re);
}

int main()
{
    int t, i;
    scanf("%d", &t);
    for(i=1;i<=t;i++)
    {
        resolver(i);
    }
    return 0;
}
