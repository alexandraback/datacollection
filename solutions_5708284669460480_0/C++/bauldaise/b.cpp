#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

void cans(int test, double ans)
{
    cout << setprecision(8) << "Case #" << test << ": " << ans << endl;
}

int cntfind(string s, string l)
{
    int res = 0;
    int pos = s.find(l);
    while (pos!= string::npos)
    {
        res++;
        pos = s.find(l, pos + 1);
    }
    return res;
}

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);

    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        int K, L, S;
        string a = "_____________";
        string s = "_____________";
        string l;
        int maxfound = 0;
        int ans[10] = {0};
        cin >> K >> L >> S;
        for (int i = 0; i < K; i++)
            cin >> a[i];
        cin >> l;
        int cnt = 1;
        for (int i = 0; i < S; i++) cnt *= K;
        for (int i = 0; i < cnt; i++)
        {
            int n = i;
            for (int j = 0; j < S; j++)
            {
                s[j] = a[n % K]; n/=K;
            }
            int found = cntfind(s,l);
            ans[found]++;
            maxfound = max(found, maxfound);
        }
        double res = (double) maxfound;
        for (int i = 1; i <= maxfound; i++)
        {
            res -= (double) i * ((double) ans[i] / (double) cnt);
        }
        cans(tt, res);
    }

}
