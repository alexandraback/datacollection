#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("A-large.in");
ofstream fout("A-large.out");

int T, N, M, t;
bool flag[1002][1002], bo;

int main() {
    fin >> T;
    for (int i = 1; i <= T; i++) {
        fin >> N;
        bo = false;
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
                flag[j][k] = false;
        for (int j = 1; j <= N; j++) {
            fin >> M;
            for (int k = 1; k <= M; k++) {
                fin >> t;
                flag[j][t] = true;
            }
        }
        for (int b = 1; b <= N; b++)
            for (int a = 1; a <= N; a++)
                for (int c = 1; c <= N; c++)
                if (a != b && a != c && b != c)
                    if (flag[a][b] && flag[b][c]) {
                        if (flag[a][c]) {
                            bo = true;
                            break;
                        }
                        flag[a][c] = true;
                    }
        //for (int a = 1; a <= N; a++){
            //for (int b = 1; b <= N; b++)
                //cout << flag[a][b] << ' ';
            //cout << endl;
        //}
        fout << "Case #" << i << ": ";
        if (bo) fout << "Yes" << endl;
        else
            fout << "No" << endl;
    }
    //system("pause");
    return 0;
}
