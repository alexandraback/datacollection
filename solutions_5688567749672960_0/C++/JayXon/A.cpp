#include <bits/stdc++.h>

using namespace std;

int64_t reverse_int(int64_t x)
{
    int64_t r = 0;
    while (x)
    {
        r = r * 10 + x % 10;
        x /= 10;
    }
    return r;
}

int64_t l(int64_t x)
{
    int64_t r = 0;
    while (x)
    {
        r++;
        x /= 10;
    }
    return r;
}

int64_t c(int64_t n)
{
    int64_t ln = l(n), rn = reverse_int(n);
    int64_t r = 0, lt = 1, rt = 1;
    for (int i = 0; i < ln / 2; i++)
    {
        lt *= 10;
    }
    for (int i = 0; i < ln - ln / 2; i++)
    {
        rt *= 10;
    }
    if (rn % lt > 1)
    {
        r += rn % lt;
    }
    r += n % rt;
    return r;
}

void solve_case(ifstream &fin, ofstream &fout)
{
    int64_t n, r = 10;
    fin >> n;
    if (n <= 20)
    {
        fout << n << endl;
        return;
    }
    if (n % 10 == 0)
    {
        n--;
        r++;
    }
    for (int64_t i = 100; i <= n; i *= 10)
    {
        r += c(i - 1) + 1;
    }
    r += c(n);

    fout << r << endl;
}


int main(int argc, char const *argv[])
{
    if (argc != 2)
        return 1;
    char name[256];
    strcpy(name, argv[1]);

    ifstream fin(name);
    name[strlen(name)-2] = 0;
    strcat(name, "out");
    ofstream fout(name);

    if (!fin.is_open() || !fout.is_open())
        return 1;

    int t, t1 = 0;

    fin >> t;

    while (t1++ < t) {
        cerr << "Solving case " << t1 << endl;
        fout << "Case #" << t1 << ": ";
        solve_case(fin, fout);
    }

    return 0;
}