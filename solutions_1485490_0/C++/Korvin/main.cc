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

long long result(vector<long long> a, vector<long long> A, vector<long long> b, vector<long long> B, int i, int j)
{
    //ofstream fcout("log.out", ios::app);

    if (i == a.size() || j == b.size())
        return 0;

    if (A[i] != B[j])
        return max(result(a, A, b, B, i + 1, j), result(a, A, b, B, i, j + 1));

    if (a[i] == b[j])
        return a[i] + result(a, A, b, B, i + 1, j + 1);


    if (a[i] < b[j]) {
        b[j]-= a[i];
        return a[i] + result(a, A, b, B, i + 1, j);
    }

    if (a[i] > b[j]) {
        a[i]-= b[j];
        return b[j] + result(a, A, b, B, i, j + 1);
    }
}

int main()
{
    //time_t start, end;
    //time(&start);

    ifstream fcin("test.in");
    ofstream fcout("test.out");
    //fcout.precision(6);
    //fcout.setf(ios::fixed,ios::floatfield);

    int T;
    fcin >> T;

    for (int i = 0; i < T; ++i) {
        int N, M;
        fcin >> N >> M;
        vector<long long> a, A, b, B;
        for (int j = 0; j < N; ++j) {
            long long cur1, cur2;
            fcin >> cur1 >> cur2;
            a.push_back(cur1);
            A.push_back(cur2);
        }
        for (int j = 0; j < M; ++j) {
            long long cur1, cur2;
            fcin >> cur1 >> cur2;
            b.push_back(cur1);
            B.push_back(cur2);
        }
        //cout << a.size() << " " << A.size() << endl;
        fcout << "Case #" << i + 1 << ": " << result(a, A, b, B, 0, 0) << endl;
    }

    //time(&end);
    //cout << difftime(end, start) << endl;

    return 0;
}
