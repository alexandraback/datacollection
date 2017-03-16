#include <iostream> 
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;


std::vector<size_t> M;
// std::vector<bool> visited;

size_t flip(size_t N) {
    size_t result = 0;
    while (N) {
        size_t d = N % 10;
        N /= 10;
        result *= 10;
        result += d;
    }
    return result;
}

size_t best(size_t N) {
    if (N == 1) return 1;

    size_t mem = M.at(N);
    if (mem > 0) return mem;

    // // Cycles are always bad.
    // if (visited.at(N)) return std::numeric_limits<size_t>::max();
    // visited[N] = true;

    size_t sub;
    size_t f = flip(N);
    size_t backtrack = N - 1;
    if ((flip(f) == N) && (f < N)) {
        size_t bf = best(f);
        size_t bnf = best(N - 1);
        if (bf < bnf) backtrack = f;
        sub = min(bf, bnf);
    }
    else sub = best(N - 1);
    size_t ans = max(1 + sub, sub); // prevent overflow
    // cout << N << ": " << backtrack << "\t" << ans << std::endl;
    M.at(N) = ans;
    return ans;
}

////////////////////////////////////////////////////////////////////////////////
/*! Program entry point
//  @param[in]  argc    Number of arguments
//  @param[in]  argv    Argument strings
//  @return     status  (0 on success)
*///////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
    size_t T;
    cin >> T;
    for (size_t t = 0; t < T; ++t) {
        M.assign(10000000, 0);
        // visited.assign(10000000, false);
        size_t N;
        cin >> N;
        cout << "Case #" << t + 1 << ": " << best(N) << endl;
    }

    return 0;
}
