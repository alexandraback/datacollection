#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int main()
{
    string file_name("B-small-attempt0");
    ifstream fin((file_name + ".in").c_str());
    ofstream fout((file_name + ".out").c_str());

    if (!fin.is_open() || !fout.is_open())
    {
        return 1;
    }

    int t, t1 = 0;

    fin >> t;

    while (t1++ < t)
    {
        double c, f, x, sec = 0, cookies = 0, p = 2;
        fin >> c >> f >> x;

        while ((x-c)/p > x/(p+f))
        {
            sec += c/p;
            p += f;
        }
        sec += x/p;

        fout.precision(7);
        fout << "Case #" << t1 << ": " << fixed << sec << endl;


    }

    return 0;
}