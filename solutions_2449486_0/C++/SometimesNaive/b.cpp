#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

int a[110][110];
int colmax[110];
int rowmax[110];

int main()
{
    string file;
    cin>>file;
    FILE* fp_in = fopen(file.c_str(), "r");
    FILE* fp_out = fopen("b_out.txt", "w");
    
    int T, n, m;
    fscanf(fp_in, "%d", &T);
    for (int cas = 1; cas <= T; cas++){
        fscanf(fp_in, "%d%d", &n, &m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                fscanf(fp_in, "%d", &a[i][j]);
            }
        }
        
        memset(colmax, 0, sizeof(colmax));
        memset(rowmax, 0, sizeof(rowmax));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (rowmax[i] < a[i][j]) 
                    rowmax[i] = a[i][j];
                if (colmax[j] < a[i][j])
                    colmax[j] = a[i][j];
            }
        }
        
        bool flag = true;
        for (int i = 0; i < n && flag; i++){
            for (int j = 0; j < m && flag; j++){
                flag = (a[i][j] == colmax[j] || a[i][j] == rowmax[i]);
            }
        }
        fprintf(fp_out, "Case #%d: %s\n", cas, flag ? "YES" : "NO");
    }
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}