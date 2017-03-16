#include <fstream>
using namespace std;

int n;
int num;
int lawn[102][102] = { 0 };
int lawn2[102][102] = { 0 };

int max_r(int i, int c)
{
    int tmp = 0;
    for (int j = 0; j < c; j++)
    {
        if (lawn[i][j] > tmp)
            tmp = lawn[i][j];
    }
    return tmp;
}

int max_c(int r, int i)
{
    int tmp = 0;
    for (int j = 0; j < r; j++)
    {
        if (lawn[j][i] > tmp)
            tmp = lawn[j][i];
    }
    return tmp;
}

void sol(ifstream& fin, ofstream& fout)
{
    int r, c;
    fin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            lawn2[i][j] = 100;
            fin >> lawn[i][j];
        }
    
    for (int i = 0; i < r; i++)
    {
        int r_max = max_r(i, c);
        for (int j = 0; j < c; j++)
            if (lawn2[i][j] > r_max)
                lawn2[i][j] = r_max;
    }
    for (int i = 0; i < c; i++)
    {
        int c_max = max_c(r, i);
        for (int j = 0; j < r; j++)
            if(lawn2[j][i] > c_max)
                lawn2[j][i] = c_max;
    }
    
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (lawn2[i][j] != lawn[i][j])
            {
                num++;
                fout << "Case #" << num << ": " << "NO" << endl;
                return;
            }

    num++;
    fout << "Case #" << num << ": " << "YES" << endl;
}
    

int main()
{
    num = 0;
    ifstream fin("B-large.in");
    ofstream fout("output.txt");
    fin >> n;

    for (int i = 0; i < n; i++)
        sol(fin, fout);

    return 0;
}

