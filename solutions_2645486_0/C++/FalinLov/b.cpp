#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<fstream>

using namespace std;

int tot;
int e, r, n;
int f[25][10];
int a[25];

int min(int x, int y) {
    if (x < y)
        return x;
    else
        return y;
}

int main() {
    
    FILE* fi = fopen("B-small-attempt1.in", "r");
    FILE* fo = fopen("output.txt", "w");
    
    fscanf(fi, "%d", &tot);
    int cnt = 0;
    while (tot > 0) {
        cnt++;
        
        //memset(f, sizeof(f), 0);
        
        
        fscanf(fi, "%d%d%d", &e, &r, &n);
        for (int i = 0; i < n + 5; i++)
            for (int j = 0; j < e + 5; j++)
                f[i][j] = 0;
        
        
        for (int i = 0; i < n; i++)
            fscanf(fi, "%d", &a[i]);
        
        for (int i = n - 1; i >=0; i--) {
            for (int j = 0; j <= e; j++) {
                for (int k = 0; k <= j; k++)
                    if (a[i] * (j - k) + f[i + 1][min(e, k + r)] > f[i][j])
                        f[i][j] = a[i] * (j - k) + f[i + 1][min(e, k + r)];    
            }
        }
        
        
        fprintf(fo, "Case #%d: %d\n", cnt, f[0][e]); 
        tot--;
    }
    
    
    fclose(fi);
    fclose(fo);
    return 0;
}
