#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int pan[1010], cnt[1010];
int main(){
    int t, T;
    int ans, maxp, maxp2, idx, freq, n;
    int i, j, k;
    FILE* fin = fopen("B-small-attempt0.in", "r");
    FILE* fout = fopen("B.out", "w");

    fscanf(fin, "%d", &T);
    for (t = 1; t <= T; t++){
        fscanf(fin, "%d", &n);
        maxp = 0;
        for (i = 0; i < n; i++){
            fscanf(fin, "%d", &pan[i]);
            maxp = max(maxp, pan[i]);
            cnt[i] = 1;
        }
        ans = maxp;
        while(true){
            maxp = 0;
            for (i = 0; i < n; i++){
                k = pan[i] / cnt[i];
                j = pan[i] - (cnt[i] - 1) * k;
                maxp = max(maxp, j);
            }
            freq = maxp2 = 0;
            for (i = 0; i < n; i++){
                k = pan[i] / cnt[i];
                j = pan[i] - (cnt[i] - 1) * k;
                if (maxp == j){
                    freq++;
                    cnt[i]++;
                    k = pan[i] / cnt[i];
                    j = pan[i] - (cnt[i] - 1) * k;
                }
                maxp2 = max(maxp2, j);
            }
//            printf("ans = %d, maxp2 = %d, freq = %d\n", ans, maxp2, freq);
            if (maxp >= maxp2 + freq)
                ans += maxp2 + freq - maxp;
            else break;
        }
        fprintf(fout, "Case #%d: %d\n", t, ans);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
/*
        while(true){
            freq = maxp = maxp2 = 0;
            for (i = 0; i < n; i++){
                k = pan[i] / cnt[i];
                j = pan[i] % cnt[i] > 0 ? 1 : 0;
                if (k > maxp){
                    maxp2 = maxp;
                    maxp = k;
                    idx = i;
                    freq = 1;
                }else if (k == maxp){
                    freq++;
                }else if (k > maxp2){
                    maxp2 = k;
                }
                if (j > 0){
                    k = pan[i] - (cnt[i] - j) * k;
                    if (k > maxp){
                        maxp2 = maxp;
                        maxp = k;
                        idx = i;
                        freq = 1;
                    }else if (k == maxp){
                        freq++;
                    }else if (k > maxp2){
                        maxp2 = k;
                    }
                }
            }
            k = pan[i] - cnt[i] * (pan[i] / (cnt[i] + 1));
            if (maxp >= )
        }
*/
