#include <fstream>

using namespace std;

ifstream fin ("test.in");
ofstream fout("test.out");

char s[1010];

void solve(int test)
{
    int maxv = 0, have = 0, need = 0;

    fin >> maxv >> s;

    for (int i = 0; i <= maxv; ++i)
    {
        int x = s[i] - '0';

        if (i > have)
        {
            need += i - have;
            have += (i - have) + x;
        }
        else
        {
            have += x;
        }
    }

    fout << "Case #" << test << ": " << need << "\n";
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
