#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>

#define OUT out
#define GETC ;

#ifndef OUT
#define OUT cout
#endif

#ifndef GETC
#define GETC getchar();
#endif

using namespace std;

int main()
{
    ifstream in("file.in");
    ofstream out("file.out");

    int cases=0;
    string line;

    in >> cases;
    getline(in, line);

    for(int nc=1; nc<= cases; ++nc)
    {
        OUT << "Case #" << nc << ": ";
        getline(in, line);
        stringstream ss;
        ss << line;

        long r, c, w, retval, minv;
        ss >> r >> c >> w;

        minv = c/w;
        minv = r * minv;
        if(c > w && c%w!=0)
            retval = minv + w;
        else
            retval = minv + w - 1;

        OUT << retval;
        if(nc != cases) OUT << endl;
    }
    in.close();
    out.close();

    GETC
    return 0;
}
