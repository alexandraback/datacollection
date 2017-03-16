#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;

double solve(int n, int px, int py)
{
    int s = abs(px) + py;
    long long a = 0;
    for(int i=0; i<=s; i+=2)
        a += 2 * i + 1;

    if(a <= n)
        return 1.0;
    if(px == 0)
        return 0.0;

    a -= 2 * s + 1;
    a = n - a;
    if(a <= 0)
        return 0.0;
    if(a > s + py)
        return 1.0;

    double ret = 1.0;
    double tmp = 1.0;
    for(int i=0; i<=py; ++i){
        ret -= tmp * pow(0.5, a);
        tmp *= a - i;
        tmp /= i + 1;
    }

    return abs(ret);
}

int main()
{
    int t;
    cin >> t;

    for(int tc=1; tc<=t; ++tc){
        int n, px, py;
        cin >> n >> px >> py;

        printf("Case #%d: %.10f\n", tc, solve(n, px, py));
    }

    return 0;
}