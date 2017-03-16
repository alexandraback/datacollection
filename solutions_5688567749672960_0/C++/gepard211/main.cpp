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

#define sqr(a) ((a)*(a))
#define ABS(A) ((a)>0 ? (a) : -(a))
#define MIN(a,b) ((a)>(b) ? (b) : (a))
#define MAX(a,b) ((a)<(b) ? (b) : (a))
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef long double ld;

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n, i, t, j;
    map<ll, ll> ms;
    pair<ll, ll> pr;
    queue<pair<ll, ll> > q;
    cin>> t;

    q.push(mp(1, 1));

    ms[1]=1;

    while(q.size())
    {
        pr = q.front();
        q.pop();
        ll a, b;
        a = pr.first;
        b = pr.second;
        if(a < 1000000)
        if(ms[a + 1] == 0 || ms[a + 1] > b + 1)
        {
            a++;
            b++;
            ms[a] = b;
            q.push(mp(a, b));
            b--;
            a--;
        }
        ll x = 0;
        while(a > 0)
        {
            x *= 10;
            x += (a % 10);
            a/= 10;
        }
        if(x < 1000000)
        if(ms[x] == 0 || ms[x] > b + 1)
        {
            b++;
            ms[x] = b;
            q.push(mp(x, b));
        }
    }
    for(i = 1; i <= t; i++)
    {
        cin>>n;
        cout<<"Case #"<<i<<": "<<ms[n]<<endl;
    }


    return 0;
}
