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

int n, p, s;
int a[110];

bool sur( int x)
{
     if( x == 0)
     {
         if( p == 0) return 1;
         else return 0;
     }
     if( ( x - 2) % 3 == 0 && ( x - 2) / 3 + 2 >= p) return 1;
     if( ( x + 2) % 3 == 0 && ( x + 2) / 3 >= p) return 1;
     if( ( x ) % 3 == 0 && ( x ) / 3 + 1 >= p) return 1;
     return 0;
}

bool nsur( int x)
{
     if( x == 0)
     {
         if( p == 0) return 1;
         else return 0;
     }
     if( ( x - 1) % 3 == 0 && ( x - 1) / 3 + 1 >= p) return 1;
     if( ( x + 1) % 3 == 0 && ( x + 1) / 3 >= p) return 1;
     if( ( x ) % 3 == 0 && ( x ) / 3 >= p) return 1;
     return 0;
}
     
int main()
{
    //freopen("B-small-attempt0.in","r",stdin);freopen("out.txt","w",stdout);
    int t, test = 0;
    scanf("%d", &t);
    while(t--)
    {
        printf("Case #%d: ", ++test);
        scanf("%d %d %d", &n, &s, &p);
        for( int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort( a, a+n);
        int ans = 0;
        int cur = s;
        bool flag[110] = {0};
        bool flag1[110] = {0};
        for( int i = 0; i < n; i++)
        {
            if( nsur( a[i])) flag[i] = 1;
            if( sur( a[i])) flag1[i] = 1;
        }
        for( int i = n-1; i >= 0; i--)
        {
            if( flag[i] && flag1[i]) ans++;
            if( flag1[i] && !flag[i] && cur > 0) { ans++; cur--; }
        }
        cout<<ans<<endl;
    }
    return(0);
}

