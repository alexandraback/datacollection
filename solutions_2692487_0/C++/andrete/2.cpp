#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;

int t;
LL a;
int n;
LL s[110];
int ans;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int i,j,k;
    int cns;
    int tem1,tem2;
    cin >> t;
    for(cns = 1; cns <= t; cns++)
    {
        ans = 10000000;
        cin >> a >> n;
        for(i = 0; i < n; i++)
            cin >> s[i];
        sort(s, s+n);
        tem1 = tem2 = 0;
        for(i = 0; i < n; i++)
        {
            if(s[i] < a)
            {
                a += s[i];
                continue;
            }
            tem2 = tem1+n-i;
            ans = min(ans, tem2);
            if(a == 1) break;
            while(s[i] >= a)
            {
                a += a-1;
                tem1++;
            }
            a += s[i];
        }
        if(a != 1) ans = min(ans, tem1);
        cout << "Case #" << cns << ": " << ans << endl;
    }
	return 0;
}
