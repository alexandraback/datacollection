#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

int tc;

int calc(int x, int d, int y) {

    int m = x;

    for (int i=0; i<d; i++) {
        x = (x%y)*10 + (x/y);
        if (x > m)
            m = x;
    }

    return m;
}

int was[10000001];

int main() {

    ifstream fin("c0.in");
    ofstream fout("c.out");

    fin >> tc;

    int a, b;

    for (int t=0; t<tc; t++) {

        fin >> a >> b;

        int d = 1;
        int y = 1;
        while (y*10 <= b) {
            d++;
            y *= 10;
        }


        memset(was, 0, sizeof(was));

        for (int i=a; i<=b; i++) {
            int x = calc(i, d, y);
            was[x]++;
        }

        int sum = 0;
        for (int i=0; i<10000000; i++)
            sum += was[i] * (was[i]-1) / 2;

        fout << "Case #" << t+1 << ": " << sum << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
