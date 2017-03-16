#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("Lawnmower.in");
ofstream fout("Lawnmower.out");

int main()
{
    int t;
    int a[101][101];
    int hpan[2][101];
    int h[101];

    fin >> t;
    for (int k=0; k<t; k++)
    {
        int n,m;
        int ans=1;
        int hmax=0;
        int hmin=9999;
        fin >> n >> m;
        for (int i=0; i<100; i++)
            h[i] = 0;
        for (int i=0; i<n; i++)
            hpan[0][i] = 0;
        for (int i=0; i<m; i++)
            hpan[1][i] = 0;

        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                fin >>  a[i][j];
                h[a[i][j]] = 1;
                if (a[i][j] > hpan[0][i])
                    hpan[0][i] = a[i][j];

                if (a[i][j] > hpan[1][j])
                    hpan[1][j] = a[i][j];

                if (a[i][j]>hmax)
                    hmax = a[i][j];
                if (a[i][j]<hmin)
                    hmin = a[i][j];
            }
        }

        /*for (int i=0; i<n; i++)
            cout << hpan[0][i] << ' ';
        cout << endl;
        for (int i=0; i<m; i++)
            cout << hpan[1][i] << ' ';
        cout << endl;*/

        for (int hh=hmin; hh<=hmax&&ans; hh++)
        {
            if ( h[hh]&&ans )
            {
                for (int i=0; i<n&&ans; i++)
                    for (int j=0; j<m&&ans; j++)
                    {
                        if (a[i][j]==hh)
                        {
                            if ( hh<hpan[0][i]&&hh<hpan[1][j] )
                                ans=0;
                        }
                    }
            }
        }
        if ( ans )
            fout << "Case #" << k+1 << ": YES" << endl;
        else
            fout << "Case #" << k+1 << ": NO" << endl;
    }

    return 0;
}
