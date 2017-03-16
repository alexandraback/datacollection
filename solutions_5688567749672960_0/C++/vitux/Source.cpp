#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");


#define cin in
#define cout out


int rev(int x)
{
    if (x % 10 == 0)
        return x;
    int r = 0;
    while (x)
    {
        r *= 10;
        r += x % 10;
        x /= 10;
    }
    return r;
}


int main()
{
    vector<int> dp(1000001, 1234567890);
    dp[1] = 1;
    for (int i = 2; i < 1000001; ++i)
        dp[i] = min(dp[i - 1], dp[rev(i)]) + 1;
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        cout << "Case #" << i + 1 << ": " << dp[n] << endl;
    }
}