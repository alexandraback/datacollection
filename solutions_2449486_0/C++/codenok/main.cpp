#include "codejam-dsl.hpp"

void run()
{
    int N = rdi(), M = rdi();
    VI rows(N, 0), cols(M, 0);
    map<int,vector<PII>,greater<int> > cells;
    FZ(r,N) FZ(c,M) {
        cells[ rdi() ].push_back(PII(r,c));
    }
    for (auto& piv : cells) {
        for (auto& pt : piv.second) {
            int r = pt.first, c = pt.second;
            if (!rows[r]) rows[r] = piv.first;
            if (!cols[c]) cols[c] = piv.first;
            if (rows[r] != piv.first && cols[c] != piv.first) {
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES";
}

