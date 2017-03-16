enum Contest { CodeChef, CodeJam };
enum IOBinding { File, StandartStream };

Contest contest = CodeJam;

IOBinding inputBinding = File;
//IOBinding inputBinding = StandartStream;

IOBinding outputBinding = File;
//IOBinding outputBinding = StandartStream;

#include <string>
#include <fstream>
#include <istream>
#include <ostream>
#include <iostream>

#include <vector>
#include <algorithm>

std::istream *input;
std::ostream *output;

typedef std::vector <int> IVec;

bool *mask;
int C, D, V;
IVec den;

void search(int pos, int sum) {
    if (sum > V) return;
    if (pos == D) {
        mask[sum] = true;
        return;
    }
    search(pos + 1, sum);
    sum += den[pos];
    search(pos + 1, sum);
}

void solveCase() {
    *input >> C >> D >> V;
    if (C != 1) {
        *output << "SKIP \n";
        return;
    }

    den.resize(D);
    mask = new bool [V+1];
    memset(mask, 0, (V+1) * sizeof(bool));
    for(int d = 0; d < D; ++d)
        *input >> den[d];

    bool b = true;
    int res = 0;
    while(b) {
        b = false;
        search(0, 0);
        for(int i = 0; i <= V; ++i) {
            if (!mask[i]) {
                b = true;
                den.push_back(i);
                ++res; ++D;
                break;
            }
        }
    }

    /*
    std::sort(den.begin(), den.end());
    *output << "DENOM: \n";
    for(int i = 0; i < den.size(); ++i) {
        *output << den[i] << ' ';
    }
    *output << '\n';
    * */

    *output << res << '\n';
    delete[] mask;
}

int main(int argc, char *argv[])
{
    std::ios_base::sync_with_stdio(false);

    if (inputBinding == File)
        input = new std::ifstream("input.txt");
    else input = &std::cin;

    if (outputBinding == File)
        output = new std::ofstream("output.txt");
    else output = &std::cout;

    int T; *input >> T;
    for(int t = 1; t <= T; ++t) {
        if (contest == CodeJam)
            *output << "Case #" << t << ": ";
        solveCase();
    }

    if (inputBinding == File) delete input;
    if (outputBinding == File) delete output;

    return 0;
}
