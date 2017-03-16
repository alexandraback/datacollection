#include <cstdio>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

const int MAXP = 1001;
const int MAXD = 1000;
int diners;
int pancakes[MAXD];

int solve() {
    vector<int> moves(MAXP, 0);
    int best = MAXP;
    for (int maxp = 1; maxp < MAXP; maxp++) {
        for (int i = 0; i < diners; i++) {
            moves[maxp] += pancakes[i] / maxp - 1;
            if (pancakes[i] % maxp)
                moves[maxp]++;
        }
        int turns = moves[maxp] + maxp;
        best = min(best, turns);
    }
    return best;
}

int main() {
    int cases;
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
        scanf("%d", &diners);
        for (int i = 0; i < diners; i++)
            scanf("%d", &pancakes[i]);
        printf("Case #%d: %d\n", cs, solve());
    }
}
