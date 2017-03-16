#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <set>
#include <algorithm>

using namespace std;

int deceitful(const set<double> &_nW, const set<double> &_kW) {
    set<double> nW(_nW);
    set<double> kW(_kW);

    int points = 0;
    for (double elem : nW) {
        if (elem < *kW.begin()) {
            set<double>::iterator kit = kW.end();
            --kit;
            kW.erase(kit);
        } else {
            ++points;
            kW.erase(kW.begin());
        }
    }

    return points;
}

int war(set<double> &_nW, set<double> &_kW) {
    set<double> nW(_nW);
    set<double> kW(_kW);

    int points = 0;
    for (double elem : nW) {
        set<double>::iterator kit = kW.lower_bound(elem);
        if (kit == kW.end()) {
            ++points;
            kW.erase(kW.begin());
        } else {
            kW.erase(kit);
        }
    }

    return points;
}

void solve(int caseN) {
    int nBlocks;
    scanf("%d", &nBlocks);

    set<double> nW, kW;

    for (int i = 0; i < nBlocks; ++i) {
        double w;
        scanf("%lf", &w);
        nW.insert(w);
    }
    for (int i = 0; i < nBlocks; ++i) {
        double w;
        scanf("%lf", &w);
        kW.insert(w);
    }

    printf("Case #%d: %d %d\n", caseN, deceitful(nW, kW), war(nW, kW));
}

int main(void)
{
    int nC;

    scanf("%d", &nC);
    for (int cC = 1; cC <= nC; ++cC) {
        solve(cC);
    }
    return 0;
}
