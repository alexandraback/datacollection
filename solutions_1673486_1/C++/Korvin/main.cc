#include <vector> // headers {{{
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <time.h>

using namespace std; // }}}

double result(int a, int b, vector<double>& v)
{
    //ofstream fcout("log.out", ios::app);

    //fcout << 0 << ": " << v[0] << endl;
    for (int i = 1; i < v.size(); ++i) {
        v[i]*= v[i - 1];
        //fcout << i << ": " << v[i] << endl;
    }

    double s3 = b + 2;
    //fcout << "s3: " << s3 << endl;
    double s1 = a + b + 1;
    //fcout << "s1: " << s1 << endl;
    for (int i = 0; i < a; ++i) {
        double cur = v[a - i - 1] * (b - a + 1 + 2 * i) + (1 - v[a - i - 1]) * (b - a + 1 + 2 * i + b + 1);
        //fcout << "cur " << i << " " << cur << endl;
        s1 = min(s1, cur);
    }
    //fcout << endl;

    return 1. * min(s1, s3);
}

int main()
{
    //time_t start, end;
    //time(&start);

    ifstream fcin("test.in");
    ofstream fcout("test.out");
    fcout.precision(6);
    fcout.setf(ios::fixed,ios::floatfield);

    int T;
    fcin >> T;

    for (int i = 0; i < T; ++i) {
        int A, B;
        fcin >> A >> B;
        vector<double> V;
        for (int j = 0; j < A; ++j) {
            double cur;
            fcin >> cur;
            V.push_back(cur);
        }
        fcout << "Case #" << i + 1 << ": " << result(A, B, V) << endl;
    }

    //time(&end);
    //cout << difftime(end, start) << endl;

    return 0;
}
