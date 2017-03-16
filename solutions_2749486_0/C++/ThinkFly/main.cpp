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
string count(int det, char neg, char pos, int start)
{
    if (det == 0)
        return string("");
    if (det < 0)
    {
        return string("")+neg+pos+ count(det+1, neg, pos, start+2);
    }
    return string("")+pos+neg+ count(det-1, neg, pos, start+2);
}
string solve_one()
{
    int x,y;
    scanf("%d %d", &x, &y);
    string a = count(-x, 'W', 'E', 1);
    string b = count(-y, 'S', 'N', 1+a.length());
    return a+b;
}
int main(int argc, char**argv)
{
    freopen("D:\\3.in", "r+", stdin);
    freopen("D:\\out.txt", "w+", stdout);
    int T;
    scanf("%d", &T);
    for (int i=1; i<=T; i++)
    {
        printf("Case #%d: %s\n", i, solve_one().c_str());
    }
    return 0;
}