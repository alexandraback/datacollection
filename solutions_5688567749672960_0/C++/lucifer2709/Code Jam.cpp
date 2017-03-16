// LUCIFER <3 SLS <3

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

long long int rev(long long int n)
{
    long long int x = 0;
    while (n) {
        x = x * 10 + n % 10;
        n /= 10;
    }
    return x;
}

long long int a[1000111];

int main()
{
    freopen("in.in", "r", stdin);
    freopen("out1.txt", "w", stdout);
    long long int t, n, cnt, r, u = 0, i;
    a[1] = 1;
    for (i = 2; i <= 1000000; i++) {
        r = rev(i);
        if (i % 10 != 0 && r < i)
            a[i] = min(a[r], a[i-1])+1;
        else
            a[i] = a[i-1]+1;
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << "Case #" << ++u << ": " << a[n] << endl;
    }
    return 0;
}
