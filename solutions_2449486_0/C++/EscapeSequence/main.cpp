#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string fn = "in.txt";
    ifstream in(fn.c_str());
    ofstream out("out.txt");

    int n;

    in >> n;

    for(int i = 0; i < n; i++) {

        int N, M; in >> N >> M;

        cout << N << " " << M << endl;

        int h[N][M];

        for(int j = 0; j < N; j++) for(int k = 0; k < M; k++)
            in >> h[j][k];

        int xMax[N];
        for(int j = 0; j < N; j++) {
            xMax[j] = 0;
            for(int k = 0; k < M; k++)
                if(h[j][k] > xMax[j]) xMax[j] = h[j][k];

        }
        int yMax[M];
        for(int j = 0; j < M; j++) {
            yMax[j] = 0;
            for(int k = 0; k < N; k++)
                if(h[k][j] > yMax[j]) yMax[j] = h[k][j];

        }

        bool can = true;
        for(int j = 0; (j < N) && can; j++)
            for(int k = 0; (k < M) && can; k++) {
                int min = xMax[j];
                if(min > yMax[k]) min = yMax[k];

                if(h[j][k] != min) can = false;
            }

        cout << "    " << can << endl;

        out << "Case #" << (i+1) << ": " << (can ? "YES" : "NO") << endl;
    }

    return 0;
}
