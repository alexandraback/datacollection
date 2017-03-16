#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <string.h>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <ctime>

#define sqr(a) ((a)*(a))
#define ABS(A) ((a)>0 ? (a) : -(a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))
#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef long double ld;

using namespace std;

int main()
{
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    ll t, r, c, w, i, ii, j, n, m, a[22][22], kol, mx, ch;
    cin>> t;
    for(ii = 0; ii < t; ii++)
    {
        cin>>r>>c>>w;
        memset(a, 0, sizeof(a));
        ch = 0;
        for(i = 1; i <= c; i+= w)
            a[1][i] = 1, ch++;
        for(i = 2; i <= r; i++)
            for(j = 1; j <= c; j++)
                if(a[i - 1][j + 1] == 1)
        {
            a[i][j] = 1;
            ch++;
            for(j = j + w; j <= c; j+= w)
                a[i][j] = 1, ch++;
        }
        cout<<"Case #"<<ii + 1<<": "<<ch + w - 1<<endl;

    }
    return 0;
}
