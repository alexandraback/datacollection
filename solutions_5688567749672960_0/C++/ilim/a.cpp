#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

long long revNum(long long i)
{
    long long res = 0LL;
    while(i)
    {
        res = res * 10 + i % 10;
        i /= 10;
    }
    return res;
}

int dp[1000001];
int f(int i)
{
    if(i == 1)
        return 1;
    int a = (dp[i-1] ? dp[i-1] : f(i-1)) + 1;
    int b = revNum(i);

    if(b >= i || revNum(b) != i || b <= 0)
        dp[i] = a;
    else
        dp[i] = min((dp[b] ? dp[b] : f(b)) + 1, a);
//    cout << "at i=" << i  << " with revNum=" << revNum(i) << " returning " << dp[i] << endl;
    return dp[i];
}

int main()
{
    int t;
    int res, n;

    for(int i=1; i <= 1000000; ++i)
        f(i);

    cin >> t;
    for(int i=1; i <= t; ++i)
    {
        cin >> n;
        
        cout << "Case #" << i << ": " << f(n) << endl;
    }

    return 0;
}
