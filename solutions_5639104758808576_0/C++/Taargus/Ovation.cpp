#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {
    ifstream fin("A-small.in");
    ofstream fout("A-small.out");

    int maxshy;
    int cases;
    string audience;
    fin >> cases;

    for(int i = 0; i < cases; i++) {
        fin >> maxshy;
        fin >> audience;
        int total = 0;
        int added = 0;

        for(int j = 0; j <= maxshy; j++) {
            int value = audience[j] - 48;
            if(total < j) {
                added += j - total;
                total += j - total;
            }

            total += value;
        }

        fout << "Case #" << i + 1 << ": " << added << "\n";
    }
}
