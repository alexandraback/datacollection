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
#include <map>


std::istream *input;
std::ostream *output;

typedef long long int int64;
typedef std::map <int64, int64> Map;

int64 inverse(int64 n) {
    int64 res = 0;
    while(n) {
        res = 10 * res + n % 10;
        n /= 10;
    }
    return res;
}

Map map;

int64 count(int64 n, int64 max) {
    if (n == max) return 1;
    if (map.count(n))
        return map[n];
    int64 inv = inverse(n);
    int64 resA = 1 + count(n+1, max);
    if ((inv <= n+1) || (inv > max)) {
        map[n] = resA;
        return resA;
    }
    int64 resB = 1 + count(inv, max);
    if (resA > resB) resA = resB;
    map[n] = resA;
    return resA;
}

int64 count(int64 n) {
    int64 nOrig = n;
    if (map.count(n)) return map[n];
    int64 res = 0;
    while(n > 1) {
        ++res;
        if (!(n%10)) --n;
        else {
            int64 inv = inverse(n);
            if (inv >= n-1) --n;
            else {
                int64 r1 = count(inv);
                int64 r2 = count(n-1);
                if (r1 > r2) r1 = r2;
                map[nOrig] = res + r1;
                return res + r1;
            }
        }
    }
    map[nOrig] = res;
    return res;
}

void solveCase() {
    int64 N; *input >> N;
    *output << 1 + count(N) << '\n';
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

    //*output << "TEST:" << inverse(1230) << '\n';

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
