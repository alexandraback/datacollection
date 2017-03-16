#include <iostream>
#include <fstream>

using namespace std;

int Solve(int R, int C, int W)
{
    int ret = R * (C / W);
    int st, hit, dr;
    st = 1;
    hit = W;
    dr = hit + C % W;
    int dr2 = dr - W;
    if (dr2 != 0)
        ++ ret;
    ret = ret + W - 1;
    return ret;
}

int main()
{
    ifstream f ("input.txt");
    ofstream g ("output.txt");
    int nr_tests;
    f >> nr_tests;
    for (int test = 1; test <= nr_tests; ++ test)
    {
        int R, C, W;
        f >> R >> C >> W;
        g << "Case #" << test << ": " << Solve(R, C, W) << "\n";
    }
    f.close();
    g.close();
    return 0;
}
