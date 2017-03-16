#include <iostream>
#include <set>
#include <algorithm>
#define ll long long
using namespace std;

set<int> found;

int main()
{
    int t, T, A, B;
    int i, k;
    int cfront, cend, pwr;
    int num, digits, ind;
    int pws[9], dg[12];
    ll ans = 0;
    pws[0] = 1;
    for(i = 1; i < 8; ++i) pws[i] = pws[i - 1] * 10;
    cin >> T;
    for(t = 1; t <= T; ++t)
    {
        cout << "Case #" << t << ": ";
        cin >> A >> B;
        ans = 0;
        for(i = A; i < B; ++i)
        {
            found.clear();
            k = i;
            digits = 0;
            while(k)
            {
                dg[digits++] = k % 10;
                k /= 10;
            }
            cfront = i; cend = 0;
            pwr = 10; ind = 0;
            while(true)
            {
                cfront = i / pwr;
                cend = i % pwr;
                if(!cfront) break;
                //cout << ind << ' ' << dg[ind] << '\n';
                if(!dg[ind++])
                {
                    pwr *= 10;
                    --digits;
                    continue;
                }
                num = cend * pws[--digits] + cfront;
                //cout << i << ' ' << cfront << ' ' << cend << ' ' << num << '\n';
                if(num > i && num <= B && found.find(num) == found.end())
                {
                    ++ans;
                    //cout << i << ' ' << cfront << ' ' << cend << ' ' << num << '\n';
                    found.insert(num);
                }
                pwr *= 10;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
