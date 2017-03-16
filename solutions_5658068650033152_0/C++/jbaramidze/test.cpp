#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stack>
#include <string.h>
#include <climits>
#include <limits>
using namespace std;

#define FOR(i, a, b) for(int i=a; i<b; i++)
#define FORE(i, a, b) for(int i=a; i<=b; i++)
#define ll long long
#define mp make_pair
#define mtriple(a, b, c) make_pair(a, make_pair(b, c))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define tripleii pair<int, pair<int ,int> >
#define triplell pair<long long, pair<long long ,long long> >
#define PI 3.14159265359
#define mod 1000000007
#define ceil(a, b) ((a)/(b) + ((a)%(b)!=0))
#define square(a) ((a)*(a))
#define debug3(names, a, b, c) cout << names << a << ", " << b << ", " << c << endl;
#define debug2(names, a, b) cout << names << a << ", " << b << endl;
#define debug1(names, a) cout << names << a << endl;

#define maxN 100000+6

int m, n, k, T;


int f(int a, int b)         // m < n
{							// a < b
    
    if (a > b) swap(a, b);


    if (a + 2 > m) return k;
    if (b + 2 > n) return k;
    if (2 * a + 2 * b + a * b < k) return k;
    if(2 * a + 2 * b + a * b > k) return 2 * (a + b) - 1;
    return 2 * (a + b);

}

int main()
{

    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    cin >> T;
    FOR(awt, 0, T)
    {
        cin >> m >> n >> k;
        if (m > n) swap(m, n);
        
        int r = INT_MAX;
        
            FORE(i, 0, k) 
            FORE(j, 0, k) r = min(r, f(i, j));
        
            printf("Case #%d: %d\n", awt + 1, r);

    }

    return 0;
}