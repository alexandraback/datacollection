#include <vector>
#include <utility>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <list>
#include <bitset>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef pair<int, int> pint;
typedef map<int, int> mint;
typedef set<int> sint;

#define TWO(k)  (1<<k)
#define TWOL(k) (((LL)(1)<<(k)))
#define MP make_pair
#define MIN(a,b) ( (a)<(b)?(a):(b) )
#define MAX(a,b) ( (a)>(b)?(a):(b) )
#define LS(x) 	 ((x)<<1)
#define RS(x) 	 (((x)<<1)+1)

const double PI = acos(-1.0);
const double EPS = 1e-9;
const int oo = 210000000;

int A, B;

int get_m( int x)
{
    int x1 = x;
    int r = 1;
    while( x1 > 0)
    {
        x1 /= 10;
        r *= 10;
    }
    return r;
}

int get_c( int x, int k, int r)
{
    int x1 = x % k;
    int x2 = x / k;
    return( x1 * ( r / k) + x2);
}

int get_num( int x)
{
    int r = get_m( x);
    int ans = 0;
    set<int> s1;
    s1.clear();
    for( int r1 = 1; r1 < r; r1 *= 10)
    {
        int tmp = get_c( x, r1, r);
        if( tmp < x && tmp >= A && get_m( tmp) == r && s1.find( tmp) == s1.end()) 
        { 
             s1.insert( tmp); 
             ans++;
        }
    }
    return ans;
}

int main()
{
    //freopen("C-large.in","r",stdin);freopen("out.txt","w",stdout);
    int t, test = 0;
    scanf("%d", &t);
    while(t--)
    {
        printf("Case #%d: ", ++test);
        scanf("%d %d", &A, &B);
        LL ans = 0;
        for( int i = A; i <= B; i++)
        {
            ans += (LL)get_num(i);
        }
        cout<<ans<<endl;
    }
    return(0);
}

