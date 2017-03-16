#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int T;
int SM;
string aStr;

#define FOR(i, a, b) for(int i = a; i < b; i++)

int main()
{
    ifstream fin("A-small-attempt0.in");
    fin >> T;
    ofstream fout("output.txt");
    FOR(i, 0, T) {
        fin >> SM;
        fin >> aStr;
        int buffer = 0;
        int noF = 0;
        FOR(j, 0, SM + 1) {
            int SJ = aStr[j] - '0';
            buffer += SJ;
            buffer -= 1;
            if (buffer < 0) {
                noF++;
                buffer++;
            }
        }
        fout << "Case #" << i + 1 << ": " << noF << endl;
    }
    return 0;
}
