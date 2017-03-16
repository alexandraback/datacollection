#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;
const int inf2 = 1000300;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t,x,r,c,w;
    cin >> t; // number of testcases
    for (int i = 1; i <= t; i++)
    {
        int result = 0;

        cin >> r >> c >> w;
        result = c / w * r;
        result += w-1;
        if (c % w)
            ++result;
        printf("Case #%d: %d\n",i, result);
    }
    return 0;
}
