#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <string.h>
#include <iomanip>

using namespace std;

double func(double d)
{
    //char  buf[256] = {'\0'};
    //char* p;

    //sprintf(buf, "%.*f", 8, d);
    //return strtod(buf, &p);
    return (d);
}

int main(int argc, const char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Error:%d\n", __LINE__);
        return -1;
    }

    ifstream fin(argv[1]);
    ofstream fout("out.txt");

    int T;
    fin >> T;
    for (int j = 0; j < T; j++)
    {
        double c, f, x;
        fin >> c >> f >> x;

        double ff = 2;
        double min = func(x / ff);
        double cc = func(c / ff);

        bool flag = true;

        for (int i = 0; ff <= x || flag == true; i++)
        {
            flag = false;
            ff += f;
            double tmp = cc + func(x / ff);
            if (tmp < min)
            {
                min = tmp;
                flag = true;
            }
            cc += func(c / ff);
        }

        fout << "Case #" << j+1 << ": " << fixed << setprecision(7) << min << endl;
    }

    return (0);
}
