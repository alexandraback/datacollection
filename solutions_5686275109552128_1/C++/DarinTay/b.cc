
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        int D;
        cin>>D;
        vector<int> P;
        for (int i=0;i<D;++i) {
            int p;
            cin>>p;
            P.push_back(p);
        }

        int best = 1<<30;
        for (int mp=1;mp<=1000;++mp) {
            int moves = 0;
            for (int i=0;i<P.size();++i) {
                moves += (P[i] - 1) / mp; 
            }
            best = std::min(best, moves + mp);
        }

        printf("Case #%d: %d\n", t, best);
    }
}
