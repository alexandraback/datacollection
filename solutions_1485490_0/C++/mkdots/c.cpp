#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int n,m;
int b[8], t[128];
long long bc[8], tc[128];

long long go(int bind, int tind, long long bcount, long long tcount)
{
    long long best=0L;

    if (bind==n || tind==m)
        return 0L;

    if (b[bind] == t[tind])
    {
        best = min(bcount, tcount);
        bcount -= best;
        tcount -= best;
        if (!bcount && !tcount)
        {
            best = best + go(bind+1, tind+1, bc[bind+1], tc[tind+1]);
        }
        else if (bcount)
        {
            best = best + go(bind, tind+1, bcount, tc[tind+1]);
        }
        else
        {
            best = best + go(bind+1, tind, bc[bind+1], tcount);
        }
    }

    best = max(best, go(bind, tind+1, bcount, tc[tind+1]));
    best = max(best, go(bind+1, tind, bc[bind+1], tcount));

    return best;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T;
    cin >> T;
    for (int tcs=1; tcs<=T; tcs++)
    {
        cin >> n >> m;
        for (int i=0; i<n; i++)
        {
            cin >> bc[i] >> b[i];
        }
        for (int i=0; i<m; i++)
        {
            cin >> tc[i] >> t[i];
        }

        cout << "Case #" << tcs << ": " << go(0, 0, bc[0], tc[0]) << endl;
    }
    return 0;
}
