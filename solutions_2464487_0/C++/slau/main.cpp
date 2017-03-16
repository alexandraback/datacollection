#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int T;
long r, t;

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);

    cin >> T;
    for (int caseNum = 1; caseNum <=T; caseNum++)
    {
        cin >> r >> t;

        long long a = 2;
        long long b = 2*r - 1;
        long long c = -t;
        //cout << b*b-4*a*c << endl;
        long long ans = -b + sqrt(b*b-4*a*c);
        ans = ans/4;
        //cout << ans << endl;

        printf("Case #%d: %d\n", caseNum, ans);


    }
    return 0;
}
