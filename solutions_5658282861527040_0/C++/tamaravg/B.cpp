#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ifstream fin("B.in");
    ofstream fout("B.out");
    int T;
    fin >> T;
    for (int testnum = 1; testnum <= T; testnum++)
    {
        int A, B, K;
        long long total = 0;
        fin >> A >> B >> K;
        for (int i = 0; i < A; i++)
        {
            for (int j = 0; j < B; j++)
                if ((i & j) < K)
                    total++;
        }
        fout << "Case #" << testnum << ": " << total << endl;
    }
}