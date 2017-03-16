#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<fstream>

using namespace std;

int tot;
int r, n, m, k;
int a[25];
int res[25];
int c[25];
int best = 100000;
int flag[25];

void prod(int x, int p) {
    if (x == n) { //printf("%d\n", p);
        bool f = true;
        for (int i = 0; i < k; i++) {
            if (c[i] == p && flag[i] != 1 && f) {
                f = false;
                flag[i] = 1;
            }
            else if (c[i] == p) {
                flag[i] = -1;
            }
        }
        return;
    }
    
    prod(x + 1, p);
    prod(x + 1, p * a[x]);
}

int calc() {
    
    for (int i = 0; i < k; i++)
        flag[i] = 0;
        
    prod(0, 1);
    
    //for (int i = 0; i< k; i++)
        //printf("%d %d\n", flag[i], c[i]);
    
    int res = 0;

    for (int i = 0; i < k; i++)
        if (flag[i] == -1)
            res++;
        else if (flag[i] == 0)
            return -1;
            
    return res;
}

void dfs(int x) {
    
    if (x == n) { 
        int p = calc();
        //printf("%d\n", p);
        if (p >= 0 && p < best) {
            best = p;
            for (int i = 0; i < n; i++)
                res[i] = a[i];
        }
        return;
    }
    
    for (int i = 2; i <= m; i++) {
        a[x] = i;
        dfs(x + 1);
    } 
    
}

int main() {
    
    FILE* fi = fopen("C-small-1-attempt0.in", "r");
    FILE* fo = fopen("output.txt", "w");
    
    fscanf(fi, "%d", &tot);
    int cnt = 0;
    while (tot > 0) {
        cnt++;
        
        //memset(f, sizeof(f), 0);
        
        
        fscanf(fi, "%d%d%d%d", &r, &n, &m, &k);
        
        fprintf(fo, "Case #%d:\n", cnt);
        
        for (int i = 0; i < r; i++) {
            
            for (int j = 0; j < k; j++)
                fscanf(fi, "%d", &c[j]);
        
            best = 100000;
            dfs(0);
            
            for (int j = 0; j < n; j++) 
                fprintf(fo, "%d", res[j]);
            fprintf(fo, "\n");
        }
        tot--;
    }
    
    
    fclose(fi);
    fclose(fo);
    return 0;
}
