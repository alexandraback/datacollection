#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin("C.in");
    ofstream fout("C.out");
    int T;
    fin >> T;
    for (int testnum = 1; testnum <= T; testnum++)
    {
        int N, M, K;
        fin >> N >> M >> K;
        if (N > M)
        {
            int temp = N; N = M; M = temp;
        }
        int ans = K;
        if (N == 3)
        {
            if (K >= 2)
                ans -= ((K - 2)/3);
        }
        else if (N == 4)
        {
            if (K >= 4)
                ans -= ((K - 4)/2);
        }
        fout << "Case #" << testnum << ": " << ans << endl;
    }
}