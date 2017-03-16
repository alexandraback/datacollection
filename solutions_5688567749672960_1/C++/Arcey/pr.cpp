#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    ofstream g("gol.txt");
    long long ant = 11;
    for (int i = 2; i <= 14; i++) {
        long long nr = ant;
        if (i % 2 == 1)
            nr += 9 * (long long) pow(10, i  / 2);
        long long aux = 0;
        for (int j = 0; j < i / 2; j++)
            aux = 10 * aux + 9;
        nr += 2 * aux + 1;
        g << i + 1 << " " << nr << endl;
        cout << i + 1 << " " << nr << endl;
        ant = nr;
    }
    return 0;
}
