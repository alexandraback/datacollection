#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

struct Tribe {
    int d; // first day
    int n; // number of attack
    int w; // west of first att
    int e; // east of first att
    int s; // strenth of first att
    int dd; // delta day
    int dp; // delta position
    int ds; // delth strength
};

Tribe tribes[1001];

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d%d%d%d%d\n",
                    &tribes[i].d,
                    &tribes[i].n,
                    &tribes[i].w,
                    &tribes[i].e,
                    &tribes[i].s,
                    &tribes[i].dd,
                    &tribes[i].dp,
                    &tribes[i].ds
             );
        }
        map<int, int> wall;
        map<int, vector<pair<int, int> > > atts;
        for (int i = 0; i < n; ++i) {
            Tribe& tribe = tribes[i];
            for (int j = 0; j < tribe.n; ++j) {
               int d = tribe.d + j * tribe.dd;
               atts[d].push_back(make_pair(i, j));
            }
        }
        int res = 0;
        map<int, vector<pair<int, int> > >::iterator it_atts = atts.begin();
        while (it_atts != atts.end()) {
            int day = it_atts->first;
            vector<pair<int, int> >& att_tribes = it_atts->second;
            for (int i = 0; i < att_tribes.size(); ++i) {
                int tribe_idx = att_tribes[i].first;
                int kth = att_tribes[i].second;
                Tribe& tribe = tribes[tribe_idx];
                int e = tribe.e + tribe.dp * kth;
                int w = tribe.w + tribe.dp * kth;
                int s = tribe.s + tribe.ds * kth;
                bool succ = false;
                for (int p = w; p < e; ++p) {
                    if (wall[p] < s) {
                        succ = true;
                    }
                }
                if (succ) res += 1;
            }
            for (int i = 0; i < att_tribes.size(); ++i) {
                int tribe_idx = att_tribes[i].first;
                int kth = att_tribes[i].second;
                Tribe& tribe = tribes[tribe_idx];
                int e = tribe.e + tribe.dp * kth;
                int w = tribe.w + tribe.dp * kth;
                int s = tribe.s + tribe.ds * kth;
                bool succ = false;
                for (int p = w; p < e; ++p) 
                    if (wall[p] < s) 
                        wall[p] = s;
            }
            ++it_atts;
        }
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
