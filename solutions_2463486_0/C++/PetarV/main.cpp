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
int a, b;
bool fairnsqr[5001];

bool checkPalin(int x)
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
    freopen("/Users/PetarV/C-small-attempt0.in.txt","r",stdin);
    freopen("/Users/PetarV/C-small-out.txt","w",stdout);
    cin >> t;
    for (int i=1;i<=40;i++)
    {
        if (checkPalin(i) && checkPalin(i*i)) fairnsqr[i*i] = true;
    }
    for (int f=1;f<=t;f++)
    {
        cin >> a >> b;
        int sol = 0;
        for (int i=a;i<=b;i++) if (fairnsqr[i]) sol++;
        printf("Case #%d: %d\n",f,sol);
    }
    return 0;
}