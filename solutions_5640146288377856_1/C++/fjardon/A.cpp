#include "common.hpp"
using namespace std;

void codejam::solve_small(int testno, std::istream& in, std::ostream& out)
{
    int R, C, W;
    in >> R >> C >> W;

    int m = (R-1)*(C+W-1)/W + C/W;
    int nmove = W-1;
    if(C%W)
        nmove++;

    out << testcase(testno) << (m+nmove) << endl;
}

void codejam::solve_large(int testno, std::istream& in, std::ostream& out)
{
    solve_small(testno, in, out);
}

int main(int argc, char* argv[]) {
    codejam cj("A");
    return cj.run(argc, argv);
}
