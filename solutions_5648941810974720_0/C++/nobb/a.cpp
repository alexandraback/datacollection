#include <iostream>
#include <fstream>
using namespace std;

int f[26];
int a[10];
int main()
{
    //ifstream infile("A-sample");
    ifstream infile("A-small-attempt2.in");
    ofstream outfile("A-output");
    int t;
    infile >> t;
    int ch;
    ch = infile.get();
    for (int ca = 1; ca <= t; ++ca)
    {
        outfile << "Case #" << ca << ": ";
        for (int i = 0; i < 26; ++i) f[i] = 0;
        while ((ch = infile.get()) != '\n')
        {
            //if (!(ch >= 'A' && ch <= 'Z')) break;
            f[ch - 'A'] += 1;
        }
        a[0] = f['Z' - 'A'];
        a[1] = f['O' - 'A'] - f['W' - 'A'] - f['U' - 'A'] - a[0];
        a[2] = f['W' - 'A'];
        a[3] = f['H' - 'A'] - f['G' - 'A'];
        a[4] = f['U' - 'A'];
        a[5] = f['V' - 'A'] - (f['S' - 'A'] - f['X' - 'A']);
        a[6] = f['X' - 'A'];
        a[7] = f['S' - 'A'] - a[6];
        a[8] = f['G' - 'A'];
        a[9] = f['I' - 'A'] - a[5] - a[6] - a[8];
        for (int di = 0; di < 10; ++di)
            for (int cnt = 1; cnt <= a[di]; ++cnt)
                outfile << di;
        outfile << endl;
    }

    infile.close();
    outfile.close();
    return 0;
}