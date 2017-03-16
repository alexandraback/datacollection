#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;
const int inf2 = 1000300;
using namespace std;

long long f(long long n)
{
    vector<int> v;
    long long t = n;
    while (n > 0)
    {
        v.pb(n%10);
        n /= 10;
    }
    long long ans = 0;
    for (int i = 0; i < v.size(); ++i)
        ans = 10*ans + v[i];
    return ans;
}
vector<int> dp(inf2+100, inf2);
int main (int argc, const char * argv[])
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t; // number of testcases
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;
    dp[6] = 6;
    dp[7] = 7;
    dp[8] = 8;
    dp[9] = 9;
    dp[10] = 10;
    for (int i = 11; i <= inf2-300; ++i)
    {
        if(f(i)!=i && dp[f(i)]!=-1 && i%10!=0)
			dp[i]=min(dp[i-1]+1, dp[f(i)]+1);
   		else
   			dp[i]=dp[i-1]+1;
    }
    for (int k = 0; k < t; ++k)
    {
        long long n;
        cin >> n;
        printf("Case #%d: %d\n", k + 1, dp[n]);
    }
    return 0;
}
