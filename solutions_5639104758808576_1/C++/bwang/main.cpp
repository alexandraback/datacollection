#include <iostream>
#include <fstream>
#include <string>

using namespace std;

long long int T;
long long int SM;
string aStr;

#define FOR(i, a, b) for(long long int i = a; i < b; i++)

int main()
{
    ifstream fin("A-large.in");
    fin >> T;
    ofstream fout("outputL.txt");
    FOR(i, 0, T) {
        fin >> SM;
        fin >> aStr;
        long long int buffer = 0;
        long long int noF = 0;
        FOR(j, 0, SM + 1) {
            long long int SJ = aStr[j] - '0';
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
