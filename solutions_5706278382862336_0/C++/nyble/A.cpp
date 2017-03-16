// Coder nyble
#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<string> vs;

#define fi          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define fr(i,n)     re(i,0,n)
#define tr(i,x)     for(__typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())
#define nl          printf("\n")

long gcd2(long a, long b) {
    long y, x;

    if (a > b) {
        x = a;
        y = b;
    } else {
        x = b;
        y = a;
    }

    while (x % y != 0) {
        long temp = x;
        x = y;
        y = temp % x;
    }

    return y;
}

long convert(long p, long q)
{
    long n = gcd2(p,q);
    long d=1;
    while(n!=1)
    {
        d*=n;
        p/=n;
        q/=n;
        n=gcd2(p,q);
    }
    return d;
}

bool checkPower(long n)
{
    bool ok = true;
    while(ok&&n>0)
    {
        if(n%2==0 || n==1)
        n=n/2;
        else
            ok=false;
    }
    return ok;
}

int main()
{
    int t;
    cin>>t;
    for(int z=1; z<=t; z++)
    {
        long p,q;
        int ans=0;
        scanf("%ld/%ld",&p,&q);

        long divisor = convert(p,q);

        p/=divisor;
        q/=divisor;

        if( checkPower(q) )
        {
            while((float)((float)p/q)<1.0)
            {
            p=p*2;
            ans++;
            }
            printf("Case #%d: %d\n",z,ans);
        }
        else
            printf("Case #%d: impossible\n",z);
    }
    return 0;
}
