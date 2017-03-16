#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
const int INF = 2147483647;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T &x) { return x.size(); }

// assert or gtfo

#define MAXCOOKIES 5000

int main()
{
    int ts;
    scanf("%d\n", &ts);

    for (int t = 0; t < ts; t++)
    {
        double c, f, x;
        scanf("%lf %lf %lf\n", &c, &f, &x);

        double mn = INFINITY;
        for (int cookies = 0; cookies <= MAXCOOKIES; cookies++)
        {

            double t = 0.0, rate = 2.0;
            for (int i = 0; i < cookies; i++)
            {
                t += c / rate;
                rate += f;
            }

            t += x / rate;
            mn = min(mn, t);
        }

        printf("Case #%d: ", t+1);
        printf("%0.10lf", mn);
        printf("\n");
    }

    return 0;
}

