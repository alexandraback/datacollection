# include <iostream>
# include <cstdio>
# define rep(x, n) for (int x = 0; x < n; ++x )
using namespace std;

int s[103][103];

int t, n, m;


bool check(int i, int j)
{
            int lmax = 0;
            int rmax = 0;
            rep(p, n)
                if ( s[p][j] > lmax )
                    lmax = s[p][j];
            rep(p, m)
                if ( s[i][p] > rmax )
                    rmax = s[i][p];
            if ( lmax > s[i][j] && rmax > s[i][j] ) return false;
            return true;
}

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.txt", "w", stdout);
    cin >> t;
    int c = 0;
    while ( t-- )
    {
        cin >> n >> m;
        rep(i, n)rep(j, m)
        {
            cin >> s[i][j];
        }
        bool ok = true;
        rep(i, n)rep(j, m)
            if ( !check(i, j) )
            {
                ok = false;
                break;
            }

            if ( ok ) printf("Case #%d: YES\n", ++c);
            else printf("Case #%d: NO\n", ++c);

    }
    fclose(stdout);
    return 0;
}
