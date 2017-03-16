#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
int r, c, w;
int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int numCase = 1; numCase <= t; numCase++)
    {
        scanf("%d%d%d", &r, &c, &w);
        int temp = c / w;
        temp *= r;
        temp += (w - 1);
        if(c % w) temp++;
        printf("Case #%d: %d\n", numCase, temp);
    }
    return 0;
}
