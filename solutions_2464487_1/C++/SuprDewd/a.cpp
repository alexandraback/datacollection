#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
#include <cassert>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
const int INF = 2147483647;
const double pi = acos(-1.0);
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T x) { return x.size(); }

// assert or gtfo

long double solve(long double a, long double b, long double c)
{
    return (- b + sqrt(b*b - 4*a*c)) / (2 * a);
}

long double sum(long double r, long double n)
{
    return 2 * n*n + 2*n*r - n;
}

int main()
{
    int ts;
    scanf("%d\n", &ts);
    for (int t = 0; t < ts; t++)
    {
       long  double r, s;
        scanf("%lf %lf\n", &r, &s);

        long double cur = ceil(solve(2, 2*r - 1, -s));
        while (sum(r, cur) > s)
        {
            // printf("%lf\n", cur);
            cur = round(cur - 1.0);
        }

        printf("Case #%d: %0.lf\n", t+1, round(cur));
    }

    return 0;
}
