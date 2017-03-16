#include <vpc/vpc.h>

using namespace vp;


// -------------------------------------------------------------------------------------------------

class State {
    std::list<int> mopes;
    int cnt;
};

int solve(int msize, const std::vector<int>& mopes, int pos1, int pos2)
{
    while (pos1 != pos2 && msize > mopes[pos1])
    {
        msize += mopes[pos1++];
    }

    if (pos1 == pos2) return 0;

    int cnt2 = pos2-pos1;
    int cnt1 = 0;

    if (msize == 1) return cnt2;

    while(msize <= mopes[pos1])
    {
        cnt1 ++;
        msize += msize-1;
    }
    cnt1 += solve(msize, mopes, pos1, pos2);

    return std::min(cnt1, cnt2);
}

// -------------------------------------------------------------------------------------------------


int main(int argc, char** argv)
{
    vpassert(argc>1);
    std::ifstream f;
    std::ofstream fout;

    openr(f, argv[1]);
    openw(fout, "out.txt");

    int T;
    readln_vars(f, T);

    for (int i: nrange(0, T)) {
        int A, N;
        readln_vars(f, A, N);

        auto s = readln_parts(f);
        vpassertsz(s, N);

        std::vector<int> mopes;

        for (auto& ss: s) mopes.push_back(std::stoi(ss));
        vpassertsz(mopes, N);
        boost::sort(mopes);

        fout << "Case #" << i+1 << ": " << solve(A, mopes, 0, N) << "\n";
    }
}
