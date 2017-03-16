#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>

using namespace std;

long long power(int b, int e) {
    long long ans = 1;
    while (e > 0) {
        ans *= b;
        e--;
    }
    return ans;
}

int main()
{
    ifstream fin("D-small-attempt0.in");
    ofstream fout("d-small.out");

    int T;
    fin >> T;

    for (int i=1; i<=T; i++) {
        int K,C,S;
        fin >> K >> C >> S;

        if (S < ceil(float(K)/float(C))) {
            fout << "Case #" << i << ": IMPOSSIBLE\n";
            continue;
        }

        //1,2,3,4,...
        bool done = false;
        fout << "Case #" << i << ":";
        int counter = 0;
        while (counter < K && !done) {
            long long idx = 0;
            for (int i=0; i<C; i++) {
                idx += ((long long)counter) * power(K, C-i-1);
                if (counter < K-1) counter++;
                else done = true;
            }

            fout << " " << idx + 1;
        }
        fout << "\n";
    }

    return 0;
}
