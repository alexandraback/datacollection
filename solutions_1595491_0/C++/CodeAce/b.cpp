#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int tc;

int main() {

    ifstream fin("b0.in");
    ofstream fout("b.out");

    fin >> tc;

    int n, s, p;

    for (int t=0; t<tc; t++) {

        fin >> n >> s >> p;

        int x;
        int c = 0;
        for (int i=0; i<n; i++) {
            fin >> x;
            if (x/3 >= p || (x%3 > 0 && x/3 >= p-1) )
                c++;
            else
                if (s > 0 && x > 0)
                    if ((x%3 == 2 && x/3 >= p-2) ||
                     (x%3 == 0 && x/3 >= p-1) ) {
                         c++;
                         s--;
                     }
        }

        fout << "Case #" << t+1 << ": " << c << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
