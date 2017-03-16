#include <iostream>
#include <fstream>
#include <cstring>
#include <list>

using namespace std;

int solve(list<double> l1, list<double> l2)
{
    int r = 0;
    for (auto i = l2.begin(); i != l2.end(); ++i)
    {
        auto j = l1.begin();
        while (j != l1.end() && *j < *i)
        {
            j++;
        }
        if (j == l1.end())
        {
            break;
        }
        l1.erase(j);
        r++;
    }
    return r;
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    char name[256];
    strcpy(name, argv[1]);

    ifstream fin(name);
    name[strlen(name)-2] = 0;
    strcat(name, "out");
    ofstream fout(name);

    if (!fin.is_open() || !fout.is_open())
    {
        return 1;
    }

    int t, t1 = 0;

    fin >> t;

    while (t1++ < t)
    {
        int n;
        fin >> n;
        list<double> l1, l2;
        for (int i = 0; i < n; ++i)
        {
            double a;
            fin >> a;
            l1.push_back(a);
        }
        for (int i = 0; i < n; ++i)
        {
            double a;
            fin >> a;
            l2.push_back(a);
        }
        l1.sort();
        l2.sort();

        fout << "Case #" << t1 << ": ";
        fout << solve(l1, l2) << " " << n - solve(l2, l1) << endl;

    }

    return 0;
}