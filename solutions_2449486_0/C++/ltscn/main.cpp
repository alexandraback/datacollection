#include <iostream>
#include <fstream>

using namespace std;

int a[101][101];
int T;
int n,m;
int linemax[101];
int cmax[101];

int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    fin >> T;
    for (int i = 0 ;i < T; ++i)
    {
        fin >> n >> m;
        for (int j = 0 ; j < n ; ++j)
        {
            int line_max = 0;
            for (int k = 0; k < m; ++k)
            {
                fin >> a[j][k];
                if (a[j][k] > line_max)
                    line_max = a[j][k];
            }
            linemax[j] = line_max;
        }
        for (int j = 0; j < m; ++j)
        {
            int c_max = 0;
            for (int k = 0; k < n; ++k)
            {
                if (a[k][j]>c_max)
                    c_max = a[k][j];
            }
            cmax[j] = c_max;
        }
        int flag = 0;
        for (int j = 0;j < n; ++j)
        {
            for (int k = 0 ; k < m; ++k)
                if (a[j][k]<linemax[j] && a[j][k]<cmax[k])
                {
                    fout << "Case #" << i + 1 <<": NO" << endl;
                    flag = 1;
                    break;
                }
            if (flag)
                break;
        }
        if (!flag)
            fout << "Case #" << i + 1 <<": YES" << endl;

    }
    fin.close();
    fout.close();
    return 0;
}
