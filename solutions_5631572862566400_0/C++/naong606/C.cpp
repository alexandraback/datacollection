#include <cstdio>
#include <cstring>
using namespace std;

int t, n;
int bff[1001];
int ord[1001];
int maxDist[1001];
bool bffPair[1001];
int ans;

inline int max(int a, int b) {return a>b?a:b;}
int main(void) {
    FILE * input = fopen("input.txt", "r");
    FILE * output = fopen("output.txt", "w");
    fscanf(input, "%d", &t);
    
    for (int tIter = 1; tIter <= t; tIter++) {
        ans = 0;
        memset(bffPair, false, sizeof(bffPair));
        memset(maxDist, 0, sizeof(maxDist));
        
        fscanf(input, "%d", &n);
        for (int i = 1; i <= n; i++)
            fscanf(input, "%d", &bff[i]);
        
        for (int i = 1; i <= n; i++) {
            memset(ord, 0, sizeof(ord));
            int len = 1, j = i;
            while (ord[j] == 0) {
                ord[j] = len++;
                j = bff[j];
            }
            if (len - ord[j] == 2) {
                bffPair[j] = bffPair[bff[j]] = true;
                maxDist[j] = max(maxDist[j], len-2);
            }
            else if (len - ord[j] > 2)
                ans = max(ans, len-ord[j]);
        }
            
        int cand = 0;
        for (int i = 1; i <= n; i++)
            if (bffPair[i])
                cand += maxDist[i];
        ans = max(ans, cand);
        
        fprintf(output, "Case #%d: %d\n", tIter, ans);
    }
    fclose(input);
    fclose(output);
    return 0;
}