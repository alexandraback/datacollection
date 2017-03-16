
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <string>

using namespace std;

int N;
int a[1000], b[1000];
int done[1000];

string solve() {
    for (int i = 0; i < N; i++)
        done[i] = 0;

    int stars = 0;
    int moves = 0;
    while (stars < 2 * N) {
        bool completed = false;
        for (int i = 0; i < N; i++)
            if (done[i] < 2 && stars >= b[i]) {
                stars += 2 - done[i];
                moves++;
                done[i] = 2;
                completed = true;
            }
        if (completed)
            continue;

        int best = -1;
        int j = -1;
        for (int i = 0; i < N; i++)
            if (done[i] == 0 && stars >= a[i]) {
                if (b[i] > best) {
                    best = b[i];
                    j = i;
                }
            }
        if (j == -1)
            return "Too Bad";

        stars++;
        moves++;
        done[j] = 1;
    }

    ostringstream out;
    out << moves;
    return out.str();
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        for (int j = 0; j < N; j++)
            scanf("%d%d", &a[j], &b[j]);

        printf("Case #%d: %s\n", i + 1, solve().c_str());
    }
}
