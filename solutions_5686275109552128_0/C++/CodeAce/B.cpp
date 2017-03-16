#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

int D;
int P[1000005];

int solution()
{
    int m = P[0];
    for (int i=0; i<D; i++)
        if (P[i] > m)
            m = P[i];

    int minutes = 0;

    while (m > 0) {
        int c = 0;
        for (int i=0; i<D; i++)
            if (P[i] > (m+1)/2)
                c++;

        if (c > 0 && c + (m+1)/2 < m) {
            for (int i=0; i<D; i++)
                if (P[i] > (m+1)/2) {
                    P[D] = P[i] / 2;
                    P[i] = P[i] - P[D];
                    D++;
                    minutes++;
                }
        }
        else {
            for (int i=0; i<D; i++)
                if (P[i] > 0)
                    P[i]--;
            minutes++;
        }

        m = P[0];
        for (int i=0; i<D; i++)
            if (P[i] > m)
                m = P[i];


    }

    return minutes;
}

int main()
{
    ifstream fin("B-small-attempt3.in");
    ofstream fout("B-small-attempt3.out");

    int TC;
    fin >> TC;

    for (int T=1; T<=TC; T++) {
        fin >> D;
        for (int i=0; i<D; i++)
            fin >> P[i];

        int res = solution();
        fout << "Case #" << T << ": " << res << endl;
        cout << "Case #" << T << ": " << res << endl;
    }


    fin.close();
    fout.close();

    return 0;
}
