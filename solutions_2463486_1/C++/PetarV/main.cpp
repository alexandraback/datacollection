/*
 Petar 'PetarV' Velickovic
 Task: Fair and Square
 */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
using namespace std;
typedef long long lld;

int t;
lld a, b;
vector<lld> fairnsqr;

bool checkPalin(lld x)
{
    int dig[55];
    int digSize = 0;
    while (x > 0)
    {
        dig[digSize++] = x%10;
        x /= 10;
    }
    for (int i=0;i<digSize;i++)
    {
        if (dig[i] != dig[digSize-i-1]) return false;
    }
    return true;
}

int main()
{
    freopen("/Users/PetarV/C-large-1.in.txt","r",stdin);
    freopen("/Users/PetarV/C-large-1-out.txt","w",stdout);
    cin >> t;
    for (lld i=1LL;i<=10000000LL;i++)
    {
        if (checkPalin(i) && checkPalin(i*i)) fairnsqr.push_back(i*i);
    }
    for (int f=1;f<=t;f++)
    {
        cin >> a >> b;
        int sol = (int)(upper_bound(fairnsqr.begin(), fairnsqr.end(), b) - lower_bound(fairnsqr.begin(), fairnsqr.end(), a));
        printf("Case #%d: %d\n",f,sol);
    }
    return 0;
}