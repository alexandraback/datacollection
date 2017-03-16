#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void solve(istream &in, ostream &out, int caseNum) {
    int smax;
    in >> smax;
    string line;
    in >> line;

    int standing = 0;
    int needAdditional = 0;
    for (int shyness = 0; shyness <= smax; shyness++) {
        int count = line[shyness] - '0';
        while (standing < shyness) {
            standing++;
            needAdditional++;
        }
        standing += count;
    }

    out << "Case #" << caseNum << ": " << needAdditional << endl;
}


int main(int argc, char **args) {
    if (argc != 3) {
        cout << "Usage: StandingOvation file.in file.out" << endl;
        return 0;
    }
    ifstream fin(args[1]);
    ofstream fout(args[2]);

    int t;
    fin >> t;
    for (int i = 0; i < t; i++)
        solve(fin, fout, i + 1);

    fout.close();
    fin.close();
}