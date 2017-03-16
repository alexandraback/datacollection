#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 0x3fffffff

int T;
int n;
char S[1000];

int main() {
    scanf("%d", &T);
    for (int Case=1; Case<=T; Case++) {
        int val = 0;

        scanf("%s", S);
        n = strlen(S);

        vector<int> segs;
        char prev = -1;
        for (int i=n-1; i>=0; i--) {
            if (S[i] != prev) {
                if (prev != -1) segs.push_back(prev);
            }
            prev = S[i];
        }
        segs.push_back(prev);

        int ans = 0;
        while (1) {
            if (segs.size() == 1 && segs[0] == '+') break;
            if (segs.empty()) break;

            segs.pop_back();
            ++ans;
        }

        printf("Case #%d: %d\n", Case, ans);
    }
}
