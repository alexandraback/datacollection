#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin ("minesweeper master.in");
    ofstream fout ("minesweeper master.out");

    int t;
    fin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int r, c, m;
        fin>>r>>c>>m;

        char grid[51][51];

        int f=r*c-m;

        if(m==0)
        {
            fout<<"Case #"<<tc<<":\n";
            fout<<'c';
            for(int i=2;i<=c;i++)fout<<'.';
            fout<<'\n';
            for(int i=2;i<=r;i++)
            {
                for(int j=1;j<=c;j++)
                {
                    fout<<'.';
                }
                fout<<'\n';
            }

            continue;
        }

        if(f==1)
        {
            fout<<"Case #"<<tc<<":\n";
            fout<<'c';
            for(int i=2;i<=c;i++)fout<<'*';
            fout<<'\n';
            for(int i=2;i<=r;i++)
            {
                for(int j=1;j<=c;j++)
                {
                    fout<<'*';
                }
                fout<<'\n';
            }

            continue;
        }

        if(r==1)
        {
            fout<<"Case #"<<tc<<":\n";

            fout<<'c';
            f--;
            for(int i=1;i<=f;i++)fout<<'.';
            for(int i=1;i<=m;i++)fout<<'*';
            fout<<'\n';

            continue;
        }
        if(c==1)
        {
            fout<<"Case #"<<tc<<":\n";

            fout<<"c\n";
            f--;
            for(int i=1;i<=f;i++)fout<<".\n";
            for(int i=1;i<=m;i++)fout<<"*\n";

            continue;
        }

        if(f<4||f==5||f==7||((r==2||c==2)&&m%2==1))
        {
            fout<<"Case #"<<tc<<":\nImpossible\n";
            continue;
        }

        int rectsz=(r-2)*(c-2);

        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                grid[i][j]='.';
            }
        }
        grid[1][1]='c';

        if(rectsz>=m)
        {
            for(int i=c;i>2&&m>0;i--)
            {
                for(int j=r;j>2&&m>0;j--)
                {
                    grid[j][i]='*';
                    m--;
                }
            }

            fout<<"Case #"<<tc<<":\n";

            for(int i=1;i<=r;i++)
            {
                for(int j=1;j<=c;j++)
                {
                    fout<<grid[i][j];
                }
                fout<<'\n';
            }

            continue;
        }
        else
        {
            for(int i=3;i<=r;i++)
            {
                for(int j=3;j<=c;j++)
                {
                    grid[i][j]='*';
                }
            }

            m-=rectsz;

            if(m%2==1)
            {
                grid[3][3]='.';
                m++;
            }

            m/=2;

            for(int i=0;i<c-3&&m>0;i++)
            {
                m--;
                grid[1][c-i]='*';
                grid[2][c-i]='*';
            }
            for(int i=0;i<r-3&&m>0;i++)
            {
                m--;
                grid[r-i][1]='*';
                grid[r-i][2]='*';
            }

            if(m>0&&c>2){m--; grid[1][3]='*'; grid[2][3]='*';}
            if(m>0&&r>2){m--; grid[3][1]='*'; grid[3][2]='*';}



            fout<<"Case #"<<tc<<":\n";

            for(int i=1;i<=r;i++)
            {
                for(int j=1;j<=c;j++)
                {
                    fout<<grid[i][j];
                }
                fout<<'\n';
            }

        }

    }

return 0;
}
