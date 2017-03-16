#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
#include <functional>

#define stop exit(0)
#define nc -1
#define eps 1e-10
#define inf 1000000000
#define mod 1000000007
#define mp make_pair

#define fill(array,value) memset(array,value,sizeof(array))
#define f(i,beg,end) for(int i=beg; i<=end; i++)
#define F(i,beg,end) for(int i=beg; i>=end; i--)
#define Max(a,b) ( (a>b)?a:b )
#define Min(a,b) ( (a<b)?a:b )
#define pi 3.1415926535897932384626433832
#define iread(var) scanf("%d",&var)
#define dread(var) scanf("%f",&var)
#define lread(var) scanf("%lld",&var)
#define input(name) freopen(name,"r",stdin)
#define output(name) freopen(name,"w",stdout)
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef long long ll;

using namespace std;

int a, b, k;

void init()
{
    cin >> a >> b >> k;
}

void solve(int testIndex)
{
    int ans = 0;

    f(i,0,a-1)
        f(j,0,b-1)
            if (i!=j)
            {
                if ((i&j)<k)
                {
                    ans ++;
                }
            }

    ans += min(min(a,b),k);

    printf("Case #%d: %d\n",testIndex,ans);
}

int main()
{
	input("B-small-attempt0.in");
	output("B-small-attempt0.out");

	int numberOfTests = 1;
	cin >> numberOfTests;

	f(i,1,numberOfTests)
	{
		init();
		solve(i);
	}

	return 0;
}
