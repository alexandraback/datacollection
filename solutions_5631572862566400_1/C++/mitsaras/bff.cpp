#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

int main(){
    int T;
    int bff[1001];

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        int best = 0;
        for (int i = 1; i <= N; i++) { scanf("%d", bff + i); }

        int in_cycle[1001];
        int visited[1001];
        for (int i = 1; i <= N; i++) { in_cycle[i] = 0; }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) { visited[j] = 0; }
            int j = i;
            while (!visited[j]) {
                visited[j] = 1;
                j = bff[j];
            }
            int k = j;
            int l = 0;
            do {
                in_cycle[k] = 1;
                l++;
                k = bff[k];
            } while (k != j);
            //printf("cycle starting at %d, length: %d\n", j, l);
            if (l > best) best = l;
        }

        int in_deg[1001];
        for (int i = 1; i <= N; i++) { in_deg[i] = 0; }
        for (int i = 1; i <= N; i++) {
            in_deg[bff[i]]++;
        }

        int lp[1001];
        for (int i = 1; i <= N; i++) {
            lp[i] = 0;
        }
        for (int i = 1; i <= N; i++) {
            if (in_deg[i] == 0) {
                int j = i;
                int curr = 1;
                while (!in_cycle[j]) {
                    if (lp[bff[j]] < curr) {
                        lp[bff[j]] = curr;
                        j = bff[j];
                        curr++;
                    } else {
                        break;
                    }
                }
            }
        }
        //for (int i = 1; i <= N; i++) { printf("-%d-", lp[i]); }
        int sum = 0;
        for (int i = 1; i <= N; i++) {
            if (bff[bff[i]] == i)
                sum += lp[i] + 1;
        }
        if (sum > best) best = sum;
        printf("Case #%d: %d\n", t, best);
    }
    return 0;
}
