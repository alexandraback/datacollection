#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

ifstream in;
ofstream out;

void Solve(int A, vector <int> B, int N, int T)
{
    int i = 0, k = 0;
    vector <int> K;
    bool q = 1;
    while (i < N && k < N)
    {
        if (A > B[i])
        {
            A += B[i];
            ++i;
            K.push_back(k);
            q = 0;
        }
        else
        {
            A += A - 1;
            ++k;
            q = 1;
        }
    }
    if (q == 1)
    {
        K.push_back(k);
    }
    int ost = N - i;
    i = K.size() - 1;
    cout << k << endl;
    int kmin = k;
    while (i > 0)
    {
        k -= K[i] - K[i - 1];
        if (q != 1)
        {
            ost += 1;
        }
        else
        {
            q = 0;
        }
        k += ost;
        ost = 0;
        if (k < kmin)
        {
            kmin = k;
        }
        --i;
    }
    out << "Case #" << T << ": " << kmin << endl;
    return;
}

int main()
{
    in.open("input.in");
    out.open("output.txt");
    int T, A, N;
    in >> T;
    for (int i = 0; i < T; ++i)
    {
        in >> A >> N;
        vector <int> B(N);
        for (int j = 0; j < N; ++j)
        {
            in >> B[j];
        }
        sort(B.begin(), B.end());
        Solve(A, B, N, i + 1);
    }
    return 0;
}
