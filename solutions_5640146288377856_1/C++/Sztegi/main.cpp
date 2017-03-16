#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");

    int t;
    in >> t;

    for(int test = 0; test < t; ++test)
    {
        int r, c, w;
        in >> r >> c >> w;

        int y = r * (c/w); // first hit
        if(c%w) ++y; // miss
        y += w - 1; // kill the rest

        out << "Case #" << test + 1 << ": " << y << endl;
    }

    return 0;
}
