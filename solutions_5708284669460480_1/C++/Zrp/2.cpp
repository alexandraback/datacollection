#include <iostream>
#include <cstring>
#include <map>
using namespace std;

char a[120], b[120];

int nex[120];
int edge[120][26];
double f[120][120], g[120][120];

double work(int n, int m, int s) {
        scanf("%s", a);
        scanf("%s", b);

        map<char, int> st;
        for (int i = 0; i < n; ++i) {
                if (st.count(a[i]))
                        ++st[a[i]];
                else
                        st[a[i]] = 1;
        }

        for (int i = 0; i < m; ++i)
        {
                if (!st.count(b[i]))
                        return 0;
        }

        int mkmp = m;
        memset(nex, 0, sizeof(nex));

        for (int i = 1; i < m; ++i) {
                bool ok = true;
                int j;
                for (j = 0; j + i < m; ++j)
                        if (b[j] != b[j+i])
                        {
                                ok = false;
                                break;
                        }
                if (ok) {
                        if (mkmp == m) mkmp = i;

                }
                
                for (int t = 1; t <= j; ++t)
                if (nex[i+t] < t) {
                        nex[i+t] = t;
                }
        }

        for (int i = 0; i <= m; ++i) cerr << nex[i] <<",";cerr<<endl;

        memset(edge, 0, sizeof(edge));
        for (int i = 0; i <= m; ++i)
                for (char c = 'A'; c <= 'Z'; ++c) {
                        if (b[i] == c)
                                edge[i][c-'A'] = i + 1;
                        else
                                edge[i][c-'A'] = edge[nex[i]][c-'A'];
                }

        int maxb = (s - (m-mkmp))/mkmp;

        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        g[0][0] = 1;
        
        double ans = 0;

        for (int i = 0; i < s; ++i) {

                for (int j = 0; j <= m; ++j)
                {
                        for (int c = 0; c < 26; ++c)
                        {
                                int jj = edge[j][c];
                                double p = st['A'+c] / (double) n;
                                g[i+1][jj] += p * g[i][j];
                        }

                }

        }

        
        for (int i = 0; i <= s; ++i) {
                ans += g[i][m];
        }
        
        cerr << maxb << " - " << ans << endl;

        return maxb - ans;
}

int main()
{
        int d;
        scanf("%d", &d);
        for (int i = 1; i <= d; ++i) {
                int n, m, s;
                scanf("%d%d%d", &n, &m, &s);
                printf("Case #%d: %lf\n", i, work(n, m, s));
        }
}
