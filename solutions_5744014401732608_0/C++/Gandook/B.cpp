#include <bits/stdc++.h>

#define SZ(x) ((int(x.size())))

typedef long long ll;

using namespace std;

const int maxn = 60;
int t, b, cnt;
ll m;
bool mark[maxn][maxn];

int main()
{
    ios::sync_with_stdio(0);
    ifstream in;
    ofstream out;
    in.open ("B-small-attempt0.in", ios::in);
    out.open ("B-small-attempt0.out", ios::out);
    in >> t;
    for (int i = 0; i < t; i++)
    {
        in >> b >> m;
        cnt = 0;
        out << "Case #" << i + 1 << ": ";
        if (m > (1ll << (b - 2)))
        {
            out << "IMPOSSIBLE" << endl;
            continue;
        }
        out << "POSSIBLE" << endl;
        memset (mark, 0, sizeof mark);
        for (int j = 1; j < b - 1; j++)
        {
            for (int k = j + 1; k < b; k++)
                mark[j][k] = 1;
        }
        mark[0][b - 1] = 1;
        m--;
        while (m > 0)
        {
            if (m & 1ll)
                mark[0][b - cnt - 2] = 1;
            cnt++;
            m >>= 1;
        }
        for (int j = 0; j < b; j++)
        {
            for (int k = 0; k < b; k++)
                out << mark[j][k];
            out << endl;
        }
    }
    in.close();
    out.close();
    return 0;
}
