#include <fstream>

using namespace std;

unsigned long long solve(unsigned long long);

int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int t;
    fin >> t;
    for (int i = 0; i < t; i++)
    {
        unsigned long long n;
        fin >> n;
        fout << "Case #" << (i + 1) << ": " << solve(n) << endl;
    }

    fin.close();
    fout.close();
    return 0;
}

unsigned long long reverse_num(unsigned long long n)
{
    unsigned long long res = 0;
    while (n > 0)
    {
        res = 10 * res + n % 10;
        n /= 10;
    }

    return res;
}

unsigned long long solve(unsigned long long n)
{
    unsigned long long *f = new unsigned long long[n + 1];
    f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        unsigned long long r = reverse_num(i);
        if (r < i && i % 10 != 0)
            f[i] = min(f[i - 1], f[r]) + 1;
        else
            f[i] = f[i - 1] + 1;
    }

    unsigned long long res = f[n];
    delete f;
    return res;
}
