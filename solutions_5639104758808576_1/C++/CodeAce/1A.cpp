#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int tc, smax, res, sum;
string s;



int main()
{
    ifstream fin("A-large.in");
    ofstream fout("A-large.out");

    fin >> tc;

    for (int t=0; t<tc; t++) {
        fin >> smax >> s;

        res = 0;
        sum = 0;

        for (int i=0; i<=smax; i++) {
            sum += ((int)s.c_str()[i] - 48) - 1;

            if (sum < 0) {
                res = res - sum;
                sum = 0;
            }
        }

        fout << "Case #" << (t+1) << ": " << res << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
