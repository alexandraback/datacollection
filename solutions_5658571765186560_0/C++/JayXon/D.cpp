#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdint>
#include <vector>

using namespace std;


string solve_case(ifstream &fin)
{
    int x, r, c;
    string s;
    fin >> x >> r >> c;

    if ((r * c) % x != 0)
        return "RICHARD";
    if (x <= 2)
        return "GABRIEL";
    if (r > c)
        swap(r, c);
    if (r == 1)
        return "RICHARD";
    if (c <= x - 1)
        return "RICHARD";
    if (x == 3)
        return "GABRIEL";
    if (r == 2)
        return "RICHARD";
    if (x == 4)
        return "GABRIEL";
    // now x >= 5, r >= 3, c >= x
    if (x == 5) {
        if (r == 3 && c == 5)
            return "RICHARD";
        return "GABRIEL";
    }

    if (x == 6) {
        if (r == 3)
            return "RICHARD";
        return "GABRIEL";
    }

    if (x >= 7)
        return "RICHARD";
    return "GABRIEL";
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
        fout << solve_case(fin) << endl;
    }

    return 0;
}