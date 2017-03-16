#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <unordered_set>

using namespace std;

int T;
unsigned long long N, M;

int main()
{
    ifstream fin("B-large.in");
    ofstream fout("B-large.out");
    fin >> T;
    for (int i = 0; i < T; ++ i)
    {
        fin >> N >> M;

        fout << "Case #" << i + 1 << ": ";
        if (M > 1 << (N - 2))
        {
            fout << "IMPOSSIBLE" << endl;
        }
        else
        {
            fout << "POSSIBLE" << endl;
            if (M == 1 << (N - 2))
            {
                for (int p = 0; p < N; ++ p)
                {
                    for (int q = 0; q < N; ++ q)
                    {
                        if (p < q) fout << 1;
                        else fout << 0;
                    }
                    fout << endl;
                }
            }
            else
            {
                bool x[51][51] = {};
                for (int p = 1; p < N; ++ p)
                {
                    for (int q = p + 1; q < N; ++ q)
                    {
                        x[p][q] = 1;
                    }
                }
                int j = 0;
                while (M > 0)
                {
                    if (M % 2 == 1)
                    {
                        x[0][N - j - 2] = 1;
                    }
                    M = M >> 1;
                    j ++;
                }
                for (int p = 0; p < N; ++ p)
                {
                    for (int q = 0; q < N; ++ q)
                    {
                        if (x[p][q]) fout << 1;
                        else fout << 0;
                    }
                    fout << endl;
                }
            }
        }
    }
    return 0;
}
