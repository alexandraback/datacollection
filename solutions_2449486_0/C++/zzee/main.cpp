#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("B-small-attempt2.in");
    ofstream fout("aa.out");

    int t=0;
    fin >> t;
    int n, m;
    int grass[200][200];

    for (int ww = 0; ww < t; ++ww) {
        fin >> n >> m;

        bool isOK = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                fin >> grass[i][j];
            }
        }

        for (int x = 1; x < 100; ++x) {
            for (int i = 0; i <= n; ++i) {
                grass[i][0] = 0;
            }
            for (int i = 0; i <= m; ++i) {
                grass[0][i] = 0;
            }
            bool canGo = false;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    if (grass[i][j] == x)
                        canGo = true;
                }
            }
            if (!canGo) {
                continue;
            }
            for (int i = 1; i <= n; ++i) {
                if (grass[i][1] == x) {
                    bool flag = true;
                    for (int j = 1; j <= m; ++j) {
                        if (grass[i][j]!=x) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        grass[i][0] = 1;
                    }
                }
            }

            for (int i = 1; i <= m; ++i) {
                if (grass[1][i] == x) {
                    bool flag = true;
                    for (int j = 1; j <= n; ++j) {
                        if (grass[j][i]!=x) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        grass[0][i] = 1;
                    }
                }
            }

            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    if (grass[i][j] == x && grass[i][0]!=1&&grass[0][j]!=1) {
                        isOK = false;
                        break;
                    }
                }
                if (!isOK)
                    break;
            }
            if (!isOK) {
                break;
            } else {
                for (int i = 1; i <= n; ++i) {
                    for (int j = 1; j <= m; ++j) {
                        if (grass[i][j] == x)
                            grass[i][j]++;
                    }
                }
            }

        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (grass[i][j] != 100) {
                    isOK = false;
                    break;
                }
            }
            if (!isOK)
                break;
        }

        if (isOK) {
            fout << "Case #" << ww+1 << ": YES" << endl;
        } else {
            fout << "Case #" << ww+1 << ": NO" << endl;
        }



    }
    return 0;
}
