#include <iostream>

using namespace std;

#define MAX_N 1000000
#define ULL unsigned long long

ULL res[MAX_N];

int reverse(int n)
{
    int res = 0;

    while(n != 0)
    {
        res *= 10;
        res += (n%10);

        n /= 10;
    }

    return res;
}

int solve(int n)
{
    if(res[n] != -1)
        return res[n];
    else
    {
        if(reverse(n) < n && n%10 != 0)
            res[n] = min(solve(n-1), solve(reverse(n)))+1;
        else
            res[n] = solve(n-1)+1;
    }

    return res[n];
}

int main()
{
    int T;
    cin >> T;

    for(int i=1; i<=MAX_N; i++)
        res[i] = -1;
    res[1] = 1;

    for(int t=1; t<=T; t++)
    {
        int n;
        cin >> n;
        solve(n);

        cout << "Case #" << t << ": " << res[n] << "\n";
    }

    return 0;
}
