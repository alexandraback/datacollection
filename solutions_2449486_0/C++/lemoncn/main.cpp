#include <fstream>
#include <cstring>
using namespace std;
int a[101][101];
int max_row[101];
int max_col[101];
int main(void)
{
    ifstream fin("input.in");
    ofstream fout("output.out");
    int T;
    fin >> T;
    for(int caseno = 1; caseno <= T; caseno++)
    {
        fout << "Case #" << caseno << ": ";
        int n, m;
        fin >> n >> m;
        memset(max_row, 0, sizeof(int) * 101);
        memset(max_col, 0, sizeof(int) * 101);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                fin >> a[i][j];
                max_row[i] = max(max_row[i], a[i][j]);
                max_col[j] = max(max_col[j], a[i][j]);
            }
        bool flag = true;
        for(int i = 0; i < n && flag; i++)
            for(int j = 0; j < m; j++)
            {
                if(a[i][j] < max_row[i] && a[i][j] < max_col[j])
                {
                    flag = false;
                    break;
                }
            }
        if(flag)
            fout << "YES" << endl;
        else
            fout << "NO" << endl;
    }
    return 0;
}
