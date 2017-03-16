#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
using namespace std;
#define length(x) (int)x.size()
const double pi=acos(-1);

void xuli()
{
    double C, F, X, res, sum, tang;
    int i;
    cin>>C>>F>>X;
    res = X/2;
    sum = 0;  tang = 2;
    while (1)
    {
        sum = sum + (C / tang);
        tang = tang + F;
        if (sum >= res) break;
        if (sum + (X / tang) < res) res = sum + (X/tang);
    }
    printf("%.9f\n", res);
}

int main()
{
     freopen("input.inp","r",stdin);
     freopen("output.out","w",stdout);
     int test, sotest;
     cin>>sotest;
     for(test=1; test<=sotest; test++)
     {
         cout<<"Case #"<<test<<": ";
         xuli();
     }
     return 0;
}
