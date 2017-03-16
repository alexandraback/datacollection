#include <bits/stdc++.h>
using namespace std;
int main()
{
   freopen("sample.out", "w", stdout);
    int T;
    cin >> T;
    string k, s, t;
    int K,L,S;
    int tt = 1;
    cout << T << endl;
    for (int _ = 1; _ <= 100; _ ++)
    {
        int maxx = 0, total = 0;
        cin >> K >> L >> S;
        t.clear();
        t.resize(S);
        cin >> k;
        cin >> s;
        tt = 1;
        for (int i = 1; i <= S; i ++)
            tt *= K;
        for (int i = 0; i < tt; i ++) {
            int l = S;
            int tr = i;
            while (l --) {
                t[l] = k[tr % K];
                tr /= K;
            }
            int ans = 0;
            for (int tr = 0; tr < S; tr ++) {
                string ttt = t.substr(tr, L);
                if (ttt == s)
                    ans ++;
            }
            maxx = max(ans, maxx);
            total += ans;
        }

        double x = 1.0 * total / tt;
        printf("Case #%d: %.10f\n",_,maxx - x);
        getchar();
    }
    return 0;
}
