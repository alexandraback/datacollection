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
int main(void) {
    freopen("in.txt", "rt", stdin);
    freopen("test.txt", "wt", stdout);
    int t, n;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc)
    {
        cin >> n;
        long long int a, k;
        int i = 1, j;
        bool b[10] = {0};
        cout << "Case #" << tc << ": ";
        if(n == 0)
        {
            cout << "INSOMNIA\n";
            continue;
        }
        while(1)
        {
            a = 1LL * i * n;
            k = a;
            while(k)
            {
                b[k % 10] = 1;
                k /= 10;
            }
            for(j = 0; j < 10; ++j)
            {
                if(!b[j])
                    break;
            }
            if(j == 10)
                break;
            i++;
        }
        cout << a << "\n";
    }
    return 0;
}
