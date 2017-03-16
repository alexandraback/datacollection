#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back

int main()
{
    freopen("inputa.txt", "r", stdin);
    freopen("outputa.txt", "w", stdout);
    int T, n, m, w, ans, ret;
    cin >> T;
    for (int t=1; t<=T; ++t)
    {
        cin >> n >> m >> w;
        ans = m/w;
        ret = (n-1)*ans;
        if (ans*w == m)
            --ret;
        ret += (ans+w);
        printf("Case #%d: %d\n", t, ret);
    }


    return 0;
}
