#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int T, N, J; scanf("%d %d %d", &T, &N, &J);
    printf("Case #1:\n");
    vector<int> a(N);
    a[0] = a[N - 1] = 1;
    int cnt = 1;
    while(cnt <= J){
        for(int i = 1; i < N-1; i += 2) for(int j = 2; j < N; j += 2)
        for(int ii = i + 2; ii < N-1; ii += 2) for(int jj = j + 2; jj < N; jj += 2) {
            a[i] = a[j] = a[ii] = a[jj] = 1;
            for(int u = 0; u < N; u++) printf("%d", a[u]);
            for(int b = 3; b <= 11; b++) printf(" %d", b);
            printf("\n");
            a[i] = a[j] = a[ii] = a[jj] = 0;
            if(cnt == J) return 0;
            cnt++;
        }
    }
    return 0;
}

