#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("test.in");
ofstream fout("test.out");

int a[1010], n;

void solve(int test)
{
    fin >> n;

    int maxv = 0;

    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i];
        maxv = max(maxv, a[i]);
    }

    int answer = 1010;

    for (int i = maxv; i >= 1; --i)
    {
        int moves = 0;

        for (int j = 1; j <= n; ++j)
        {
            moves += (a[j]-1)/i;
        }

        answer = min(answer, i + moves);
    }

    fout << "Case #" << test << ": " << answer << "\n";
}

int main()
{
    int test;
    fin >> test;

    for (int k = 1; k <= test; ++k)
    {
        solve(k);
    }
}
