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

#define MAXCOOKIES 2000000

int main()
{
    int ts;
    scanf("%d\n", &ts);

    for (int t = 0; t < ts; t++)
    {
        long double c, f, x;
        cin >> c >> f >> x;

        long double mn = INFINITY;

        long double tm = 0.0, rate = 2.0;
        for (int i = 0; i <= MAXCOOKIES; i++)
        {
            mn = min(mn, tm + x / rate);
            tm += c / rate;
            rate += f;
        }

        // tm += x / rate;

        printf("Case #%d: ", t+1);
        cout << setprecision(10) << fixed << mn << endl;
    }

    return 0;
}

