#include <cstdio>

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Outfit {
    int iJ;
    int iP;
    int iS;
};

using Outfits = vector<Outfit>;

int main() {
    int nT;
    scanf("%d", &nT);
    for (int t = 0; t < nT; ++t) {
        int j, p, s, k;
        scanf("%d%d%d%d", &j, &p, &s, &k);

        Outfits outfits;
        for (int iJ = 0; iJ < j; ++iJ) {
            for (int iP = 0; iP < p; ++iP) {
                for (int iS = 0; iS < s; ++iS) {
                    Outfit o;
                    o.iJ = iJ;
                    o.iP = iP;
                    o.iS = iS;
                    outfits.push_back(o);
                }
            }
        }

        using Counts = vector<vector<int>>;
        vector<int> dummy_(s);
        Counts dummy(s, dummy_);
        Counts c1;
        Counts c2;
        Counts c3;
        int maxK = 0;
        Outfits bestOutfits;
        for (int i = 0; i < 70000; ++i) {
            random_shuffle(outfits.begin(), outfits.end());
            c1 = dummy;
            c2 = dummy;
            c3 = dummy;
            int nk = 0;
            for (int iK = 0; iK < outfits.size(); ++iK) {
                const Outfit& o = outfits[iK];
                if (c1[o.iJ][o.iP] < k && c2[o.iJ][o.iS] < k && c3[o.iP][o.iS] < k) {
                    ++c1[o.iJ][o.iP];
                    ++c2[o.iJ][o.iS];
                    ++c3[o.iP][o.iS];
                    ++nk;
                }
            }
            fprintf(stderr, "%d %d %d\n", t, nk, maxK);
            if (nk > maxK) {
                maxK = nk;
                bestOutfits = outfits;
            }
        }

        printf("Case #%d: %d\n", t + 1, maxK);
        c1 = dummy;
        c2 = dummy;
        c3 = dummy;
        for (int iK = 0; iK < bestOutfits.size(); ++iK) {
            const Outfit& o = bestOutfits[iK];
            if (c1[o.iJ][o.iP] < k && c2[o.iJ][o.iS] < k && c3[o.iP][o.iS] < k) {
                ++c1[o.iJ][o.iP];
                ++c2[o.iJ][o.iS];
                ++c3[o.iP][o.iS];
                printf("%d %d %d\n", o.iJ + 1, o.iP + 1, o.iS + 1);
            }
        }
    }

    return 0;
}
