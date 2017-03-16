#include<iostream>
#include<cmath>

using namespace std;

bool IsPalindrome(long long A)
{
    long long B, R;
    B = A;
    R = 0;
    while (B > 0)
    {
        R = R * 10 + B % 10;
        B /= 10;
    }
    return A == R;
}

void solve(int num)
{
    long long A, B;
    cin >> A >> B;
    long long a, b, i;
    long long ans = 0;
    a = sqrtl(A);
    b = sqrtl(B);
    for (i = a - 1; i <= b + 1; ++i)
    {
        if(IsPalindrome(i) && IsPalindrome(i * i) && A <= i * i && i * i <= B)
            ans += 1;
    }
    cout << "Case #" << num << ": " << ans << endl;
}

int main()
{
    int i, n;
    cin >> n;
    for (i = 1; i <= n; ++i)
        solve(i);
    return 0;
}

