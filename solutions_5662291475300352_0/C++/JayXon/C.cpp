#include <bits/stdc++.h>

using namespace std;


void solve_case(ifstream &fin, ofstream &fout)
{
    int n, r = 0;
    fin >> n;
    int d1, d2, h, m1, m2;
    if (n == 2)
    {
        fin >> d1 >> h >> m1;
        fin >> d2 >> h >> m2;
        double t1 = (360 - d1) / 360.0 * m1;
        double t2 = (360 - d2) / 360.0 * m2;
        if (t1 > t2)
        {
            swap(m1, m2);
            swap(d1, d2);
            swap(t1, t2);
        }
        double d = (t2 - t1) * 360 / m1;
        cerr << d << endl;
        if (d >= 360)
            r++;
    }
    else
    {
        fin >> d1 >> h >> m1;
    }
    fout << r << endl;
}


int main(int argc, char const *argv[])
{
    if (argc != 2)
        return 1;
    char name[256];
    strcpy(name, argv[1]);

    ifstream fin(name);
    name[strlen(name) - 2] = 0;
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