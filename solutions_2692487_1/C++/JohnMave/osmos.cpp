#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using std::sort;

int cumulative[101];
int cumulateTo[101];
int particles[101];

int main(void) {
    FILE *fin, *fout;
    fin = fopen("osmos.in", "r");
    fout = fopen("osmos.out", "w+");
    int T, n;
    int i, j, k;
    int ans;
    fscanf(fin, "%d", &T);
    for(i = 1; i <= T; i++) {
        fscanf(fin, "%d%d", cumulative, &n);
        for(j = 1; j <= n; j++) {
            fscanf(fin, "%d", particles + j);
        }
        sort(particles + 1, particles + n + 1);
        cumulateTo[0] = 0;
        for(j = 1; particles[j] < cumulative[0] && j <= n; j++) {
            cumulative[0] += particles[j];
            cumulateTo[0]++;
        }
        for(j = 1; cumulateTo[j - 1] <= n && j <= n; j++) {
            cumulative[j] = cumulative[j - 1] + cumulative[j - 1] - 1;
            cumulateTo[j] = cumulateTo[j - 1];
            for(k = cumulateTo[j - 1] + 1; particles[k] < cumulative[j] && k <= n; k++) {
                cumulative[j] += particles[k];
                cumulateTo[j]++;
            }
        }
        ans = n;
        for(j = 0; j <= n; j++) {
            if(j + n - cumulateTo[j] < ans) {
                ans = j + n - cumulateTo[j];
            }
        }
        fprintf(fout, "Case #%d: %d\n", i, ans);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}