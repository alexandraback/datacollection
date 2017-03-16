#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

int solve(int R, int C, int W)
{
    if (W == 1) return R*C;

    if (R == 1) {
        return W + ceil(double(C)/W) - 1;
    }
}

int main()
{
    ifstream fin("A-small-attempt0.in");
    ofstream fout("outputA.txt");

    int T;
    //cin >> T;
    fin >> T;

    for (int i=1; i<=T; i++) {
        int R, C, W;
        //cin >> R >> C >> W;
        fin >> R >> C >> W;

        cout << "Case #" << i << ": " << solve(R,C,W) << "\n";
        fout << "Case #" << i << ": " << solve(R,C,W) << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}
