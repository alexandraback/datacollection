#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

#define maxn 11
#define maxl 1000010

int t, n, m;
int jp[maxn][maxn], js[maxn][maxn], ps[maxn][maxn];
int e[maxl], p[maxl], s[maxl];
int conf[maxl], csol[maxl];
int sol;
int vv[3];

void back(int nod, int tot)
{
    if(nod==n)
    {
        if(tot>=sol)
        {
            sol=tot;
            for(int i=0; i<n; ++i)
                csol[i]=conf[i];
        }
        return;
    }

    int a=e[nod], b=p[nod], c=s[nod];

    conf[nod]=0;
    back(nod+1, tot);

    if(jp[a][b]<m && js[a][c]<m && ps[b][c]<m)
    {
        ++jp[a][b];
        ++js[a][c];
        ++ps[b][c];

        conf[nod]=1;
        back(nod+1, tot+1);

        --jp[a][b];
        --js[a][c];
        --ps[b][c];
    }
}

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("data.out", "w", stdout);

    scanf("%d", &t);
    for(int test=1; test<=t; ++test)
    {
        int a, b, c;
        scanf("%d%d%d%d", &a, &b, &c, &m);

        n=0;
        for(int i=1; i<=a; ++i)
            for(int j=1; j<=b; ++j)
                for(int k=1; k<=c; ++k)
                {
                    e[n]=i;
                    p[n]=j;
                    s[n]=k;
                    ++n;
                }

        memset(jp, 0, sizeof(jp));
        memset(js, 0, sizeof(js));
        memset(ps, 0, sizeof(ps));
        memset(csol, 0, sizeof(csol));

        sol=0;

        if(n<=28)
            back(0, 0);
        else
        {
            int ok=1;

            while(ok)
            {
                int spoz=0;
                pair<int, pair<int, int> > smin=make_pair(m+1, make_pair(m+1, m+1));
                for(int i=0; i<n; ++i)
                {
                    vv[0] = jp[e[i]][p[i]];
                    vv[1] = js[e[i]][s[i]];
                    vv[2] = ps[p[i]][s[i]];

                    sort(vv, vv+3);
                    pair<int, pair<int, int> > cmax = make_pair(vv[2], make_pair(vv[1], vv[0]));

                    if(cmax<smin && csol[i]==0)
                    {
                        smin=cmax;
                        spoz=i;
                    }
                }

                if(smin.first>=m)
                    break;

                ++sol;
                csol[spoz]=1;

                ++jp[e[spoz]][p[spoz]];
                ++js[e[spoz]][s[spoz]];
                ++ps[p[spoz]][s[spoz]];
            }
        }

        printf("Case #%d: %d\n", test, sol);

        for(int i=0; i<n; ++i)
        {
            if(csol[i]==1)
                printf("%d %d %d\n", e[i], p[i], s[i]);
        }
    }

    return 0;
}
