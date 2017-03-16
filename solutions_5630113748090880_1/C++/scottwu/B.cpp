#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAXN = 2510;

ifstream fin ("A.in");
ofstream fout ("B.txt");

int N;
bool use[MAXN];
vector <int> res;

int main()
{
    int T; fin >> T;
    for (int test = 1; test <= T; test++)
    {
    fout << "Case #" << test << ": ";
    
    for (int i = 0; i < MAXN; i++)
        use[i] = false;
    
    fin >> N;
    for (int i = 0; i < (2 * N - 1) * N; i++)
    {
        int x;
        fin >> x;
        use[x] = !use[x];
    }
    
    res.clear();
    for (int i = 0; i < MAXN; i++)
        if (use[i])
            res.push_back (i);
    
    for (int i = 0; i < N; i++)
    {
        if (i) fout << " ";
        fout << res[i];
    }
    fout << "\n";
    
    }
    return 0;
}
