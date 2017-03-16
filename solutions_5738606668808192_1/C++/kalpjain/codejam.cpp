#include <bits/stdc++.h>
using namespace std;
bool comp(int a,int b)
{
    return (a>b);
}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int mod[9] = {3, 2, 5, 2, 7, 2, 3, 2, 11}, n, j;
int po[32][9];
int p(int a, int n)
{
    po[0][a - 2] = 1;
    for(int i = 1; i <= n; ++i)
        po[i][a - 2] = (po[i - 1][a - 2] * a) % mod[a - 2];
    return po[n][a - 2];
}
void sol(string s, int a[])
{
    if(j == 0)
        return;
    if(s.size() == n - 1)
    {
        int i;
        for(i = 0; i < 9; ++i)
        {
            if(a[i] % mod[i])
                break;
        }
        if(i == 9)
        {
            j--;
            //cout << j << " ";
            reverse(s.begin(), s.end());
            cout << "1" << s << " ";
            for(i = 0; i < 9; ++i)
                cout << mod[i] << " ";
            cout << "\n";
        }
        return;
    }
    int b[9];
    for(int i = 0; i < 9 ;++i)
        b[i] = (a[i] + po[s.size()][i]) % mod[i];
    sol(s + '1', b);
    sol(s + '0', a);
}
int main(void) {
    freopen("in.txt", "rt", stdin);
    freopen("test.txt", "wt", stdout);
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc)
    {
        cin >> n >> j;
        cout << "Case #" << tc << ":\n";
        int init[9], i;
        for(i = 2; i <= 10; ++i)
        {
            init[i - 2] = (1 + p(i, n - 1)) % mod[i - 2];
            //cout << init[i - 2] << " ";
        }
        sol("1", init);
    }
    return 0;
}
