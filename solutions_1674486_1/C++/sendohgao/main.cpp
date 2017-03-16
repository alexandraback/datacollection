#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("A-large.in");
    ofstream fout("output.txt");

    int t;
    fin >> t;
    for (int i = 0; i != t; ++i) {
        int n;
        fin >> n;
        int link[n][11];
        for (int j = 0; j != n; ++j) {
            fin >> link[j][0];
            for (int k = 1; k <= link[j][0]; ++k) {
                fin >> link[j][k];
            }
        }

        int mask[n];
        for (int j = 0; j != n; ++j) {
            mask[j] = 0;
        }

        bool found = false;
        for (int j = 0; j != n; ++j) {
            mask[j] = j + 1;

            bool visited[n];
            for (int k = 0; k != n; ++k) {
                visited[k] = false;
            }

            while (true) {
                bool flag = false;
                for (int k = 0; k != n; ++k) {
                    if (mask[k] == j + 1 && !visited[k]) {
                        visited[k] = true;
                        for (int q = 1; q <= link[k][0]; ++q) {
                            if (mask[link[k][q] - 1] == j + 1) {
                                found = true;
                                break;
                            }
                            else {
                                mask[link[k][q] - 1] = j + 1;
                                flag = true;
                            }
                        }
                        if (found) break;
                    }
                }
                if (found) break;
                if (!flag) break;
            }

            if (found) break;
        }


        fout << "Case #" << (i + 1) << ": " << (found ? "Yes" : "No") << endl;
    }

    fin.close();
    fout.close();
}
