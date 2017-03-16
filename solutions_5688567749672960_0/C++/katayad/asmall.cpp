#include <iostream>
#include <fstream>

using namespace std;
int N = 1000001;
int dp[ 1000001];
int curN;

int rev(int n)
{

    int a = 0;
    while (n)
    {
        a *= 10;
        a += n % 10;
        n/=10;
    }
    return a;
}

int cnt(int n)
{
    int a = 0;
    while (n)
    {
        a++;
        n/=10;
    }
    return a;
}

int f(int n, int r, int lastN = curN)
{
    //cerr << n << endl;

    if (n < 0 || n > curN || n > lastN)
        return (1<<30);
    if (n <= 19)
        return n;
    if (dp[n] != -1)
        return dp[n];
    if (r == 0 && cnt(n) == cnt(rev(n)))
        dp[n] = min(f(n - 1, 0, n), f(rev(n), 1, n)) + 1;
    else
        dp[n] = f(n - 1, 0) + 1;
    return dp[n];
}

int main()
{
    //int f = 2300;
    //rev(f);
    //cout << f;
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("out1.txt", "w", stdout);
    int t;
    cin >> t;
    for (int j = 1; j <= t; ++j)
    {
        for (int i = 0; i < N; ++i) dp[i] = -1;
        int ans = 0, n;
        cin >> n;
        curN = n;
        cout << "Case #" << j << ": " << f(n, 0, n) << endl;
    }
}
