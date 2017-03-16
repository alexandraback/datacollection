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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll t, c, d, v, i, j, ii, p, k, a[40], b[40], q[40], nw;
    cin>> t;
    for(ii = 0; ii < t; ii++)
    {
        cin>>c>>d>>v;
        nw = 0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(q,0,sizeof(q));
        for(i = 1; i <= d; i++)
        {
            cin>>k;
            if(k <= v) a[k] = 1;
        }
        for(i = 1; i <= v; i++)
        {
            if(a[i])
            {
                for(j = 1; j <= c; j++)
                    for(k = 0; k <= v; k++)
                        if(k == 0 || b[k])
                    {
                        if(k + j * i <= v) q[k + j * i] = 1;
                    }
                for(k = 0; k <= v; k++)
                    b[k] = q[k];
            }
        }

        p = 1;

        while(p <= v)
        {
            if(b[p])p++;
                else
            {
                a[p] = 1;
                for(j = 1; j <= c; j++)
                    for(k = 0; k <= v; k++)
                        if(k == 0 || b[k])
                    {
                        if(k + j * p <= v) q[k + j * p] = 1;
                    }
                for(k = 0; k <= v; k++)
                    b[k] = q[k];
                p++;
                nw++;
            }
        }

        cout<<"Case #"<<ii + 1<<": "<<nw<<endl;

    }
    return 0;
}
