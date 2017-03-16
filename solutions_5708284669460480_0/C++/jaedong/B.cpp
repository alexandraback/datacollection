#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int K, L, S;
char keyboard[100], target[100];
char back[100];
int total, matches, most_matches, total_matches;

void solve(int id) {
    if (id == S) {
        total++;
        most_matches = max(most_matches, matches);
        total_matches += matches;
    } else {
        for (int i = 0; i < K; i++) {
            back[id] = keyboard[i];
            bool match = (back[id] == target[L - 1] and id >= (L - 1) and memcmp(&back[id + 1 - L], target, L) == 0);
            if (match)
                matches++;
            solve(id + 1);
            if (match)
                matches--;
        }
    }
}

int main() {
    int cases;
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
        scanf("%d%d%d", &K, &L, &S);
        scanf("%s%s", keyboard, target);
        total = matches = most_matches = total_matches = 0;
        solve(0);
        // printf("t=%d most=%d total=%d\n", total, most_matches, total_matches);
        double ans = most_matches - (double(total_matches) / double(total));
        printf("Case #%d: %.9lf\n", cs, ans);
    }
}
