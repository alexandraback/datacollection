# include <bits/stdc++.h>
using namespace std;
long long inv(long long x)
{
    long long cnt = 0;
    while (x)
    {
        cnt = cnt * 10 + (x%10);
        x /= 10;
    }
    return cnt;
}
long long dif(long long x)
{
    char c[88];
    int n = 0;
    long long y = x;
    while (x) c[++n] = x%10,x /= 10;
    reverse(c+1,c+1+n);
    int k = n/2;
    long long ans = 0;
    for (int i = 1;i <= k;++i) ans = ans * 10 + c[i];
    for (int i = k+1;i<n;++i) ans *= 10;
    ans *= 10;ans ++;
    return ans;
}
int last(long long x)
{
    while (x > 9) x /= 10;
    return x;
}
long long pow(long long x)
{
    long long ans = 1;
    while (x > 9) ans *= 10,x /= 10;
    return ans;
}
long long ans(long long x)
{
    long long ras = 0;
    while (x)
    {
        if (!(x % 10)) --x,++ras;
        else
        if (x < 10) ras += x,x = 0;
        else
        if (dif(x) < x) ras += x - dif(x) + 1,x = dif(x),x = inv(x);
        else ras += x - pow(x) + 1,x = pow(x),--x;
    }
    return ras;
}
int main(void)
{
    ifstream fi("a.in");
    ofstream fo("a.out");
    int t;
    long long n;
    fi>>t;
    for (int i = 1;i <= t;++i)
    {
        fi>>n;
        fo << "Case #" << i << ": " << ans(n) << '\n';
    }
    return 0;
}
