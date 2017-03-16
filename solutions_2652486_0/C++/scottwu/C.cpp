#include <iostream>
#include <fstream>

using namespace std;
typedef long long ll;

ifstream fin ("blah.in");
ofstream fout ("blah.out");

int N, R, M, K;
int val[101];
int v[10][101];

int main()
{
    int T; fin >> T;
    fout << "Case #1:\n";
    fin >> R >> N >> M >> K;
    
    for (int test = 1; test <= R; test++)
    {
    
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 101; j++)
            v[i][j] = 0;
    
    int n2 = 0, n3 = 0, n5 = 0;
    int m2 = 1;
    for (int i = 0; i < K; i++)
    {
        fin >> val[i];
        
        while (val[i] % 2 == 0)
        {
            val[i] /= 2;
            v[2][i]++;
        }
        while (val[i] % 3 == 0)
        {
            val[i] /= 3;
            v[3][i]++;
        }
        while (val[i] % 5 == 0)
        {
            val[i] /= 5;
            v[5][i]++;
        }
        
        n2 += v[2][i];
        m2 = max (m2, v[2][i]);
        n3 += v[3][i];
        n5 += v[5][i];
    }
    
    int l3 = (n3 * 2 + 3) / 7;
    int l5 = (n5 * 2 + 3) / 7;
    int nleft = 3 - l3 - l5;
    
    if (nleft == 1)
    {
        fout << min (4, (1 << m2));
    }
    else if (nleft == 2)
    {
        fout << "24";
    }
    else if (nleft == 3)
    {
        fout << "224";
    }
    
    while (l3 + l5 > 3 && l5)
        l5--;
    while (l3 + l5 > 3 && l3)
        l3--;
    
    
    for (int i = 0; i < l3; i++)
        fout << "3";
    for (int i = 0; i < l5; i++)
        fout << "5";
    
    fout << "\n";
    }
    
    return 0;
}
