#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

ifstream f("test.in");
ofstream g("test.out");

int T,K,L,S;
char monkey[20],wanted[20],aux[20];
double nr,nrmax;
double total;
char sol[20];
double answer;

// k initial
// l are cuvantul cautat
// s are cuvantul format

void check()
{
    int crtnr = 0;

    for (int i = 1; i <= S-L+1; ++i)
    {
        bool ok = true;
        for (int j = i; j < i+L; ++j)
        {
            if (sol[j] != wanted[j-i])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            nr++;
            crtnr++;
        }
    }

    /*for (int i = 1; i <= S; ++i)
    {
        g << sol[i];
    }
    g << '\n';*/

    if (crtnr > nrmax)
        nrmax = crtnr;
}

void backt(int k)
{
    if (k > S)
    {
        check();
        return;
    }

    for (int i = 0; i < K; ++i)
    {
        sol[k] = monkey[i];
        backt(k+1);
    }
}

int main()
{
    f >> T;
    f.getline(aux,15);
    for (int t = 1; t <= T; ++t)
    {
        f >> K >> L >> S;
        f.getline(aux,15);
        f.getline(monkey,15);
        f.getline(wanted,15);
        /*for (int i = 0; i < K; ++i)
        {
            g << monkey[i];
        }*/
        nrmax = 0;
        nr = 0;
        total = 1;

        for (int i = 1; i <= S; ++i)
        {
            total *= K;
        }

        backt(1);
        answer = nrmax - nr/total;

        g << "Case #" << t << ": ";

        g << fixed << setprecision(7) << answer << '\n';
    }

    f.close();
    g.close();
    return 0;
}
