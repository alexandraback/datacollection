#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <string.h>

#define SZ(c) c.size()
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define SORT(a) sort(a.begin(),a.end())
#define tests int test; scanf("%d",&test); while(test--)
#define dbg(n) cout<<#n<<" = "<<n<<endl;

using namespace std;

int strToInt(string str) {int ans; stringstream s; s<<str; s>>ans; return ans;}
string intToStr(int n) {string str; stringstream s; s<<n; s>>str; return str;}
int MAX(int a,int b) {if(a >b) return a; return b;}
int MIN(int a,int b) {if(a <b) return a; return b;}
int ABS(int a) {if(a >0) return a; return -a;}

long long int GCD(long long int x, long long int y)
{
    if(!y)
        return x;
    if(x < y)
        return GCD(y,x);
    return GCD(y, x%y);
}

long long int solve(double value)
{
    long long int ans = 0;
    double amit = 1.0;
    while(amit > value)
    {
        amit /= 2;
        ans++;
    }
    return ans;
}

bool valid(long long int x, long long int y, long long int gcd)
{
    y= y/gcd;
    //cout<<y <<" "<<(y & (y-1))<<endl;
    if((y & (y-1)) == 0)
        return true;
    return false;
}

int main()
{
    freopen("A-large.txt", "r", stdin);
    freopen("writeGCDLarge.txt", "w", stdout);
    int test;
    scanf("%d\n",&test);
    long long int x,y;
    for(int running=1; running <= test; running++)
    {
        scanf("%lld/%lld",&x,&y);
        double value = (x*1.0)/(y*1.0);
        long long int gcd = GCD(x,y);
       // cout<<gcd<<endl;
        if (valid(x,y, gcd))
        {
            long long int ans = solve(value);
            printf("Case #%d: %d\n", running, ans);
        }
        else
        {
            printf("Case #%d: impossible\n", running);
        }

    }
    return 0;
}

