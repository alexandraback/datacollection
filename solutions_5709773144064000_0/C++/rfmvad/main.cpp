#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void func(ifstream& in, ofstream& out)
{
    double C, F, X, t = 0, v = 2;

    in >> C >> F >> X;

    while (C / v + X / (v + F) < X / v)
    {
        t += C / v;
        v += F;
    }

    out << t + X / v << endl;
}

int main()
{
    ifstream in;
    in.open("B-small-attempt0.in");

    ofstream out;
    out.open("code_jam_out");
    out << fixed << showpoint << setprecision(7);

    int T;
    in >> T;

    for (int t = 1; t <= T; t++)
    {
        //cout << "Case #" << t << endl;
        out << "Case #" << t << ": ";
        func(in, out);
    }

    in.close();
    out.close();

    return 0;
}
