#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ifstream fin("B-large.in");
    ofstream fout("out.txt");
    int t;
    fin >> t;
    for (int glob = 0; glob < t; glob++) {
        long long n, m;
        fin >> n >> m;
        fout << "Case #" << glob + 1 << ": ";
        if (m > pow(2, n - 2))
            fout << "IMPOSSIBLE" << endl;
        else {
            fout << "POSSIBLE" << endl;
            vector<int> first_line(n);
            long long temp = m - 1;
            for (int i = n - 2; i > 0; i--) {
                first_line[i] = temp % 2;
                temp /= 2;
            }
            first_line[0] = 0;
            first_line.back() = 1;
            for (int i = 0; i < n; i++)
                fout << first_line[i];
            fout << endl;
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < n; j++){
                    if (j <= i)
                        fout << 0;
                    else
                        fout << 1;
                }
                fout << endl;
            }
        }
    }
    return 0;
}
