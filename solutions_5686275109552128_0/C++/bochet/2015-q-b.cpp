#include <cstdio>
#include <cmath>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int c[], int m){
    if(c[m] == 0)
        return dfs(c, m-1);
    if(m <= 3)
        return m;
    
    int t = m;
    for(int d1 = 1; d1 <= m/2; d1++){
        int d2 = m - d1;
        c[d1] += c[m];
        c[d2] += c[m];
        t = min(t, c[m]+dfs(c, m-1));
        c[d1] -= c[m];
        c[d2] -= c[m];
    }
    return t;
}

int main()
{
//    FILE* fid_in = stdin;
//    FILE* fid_out = stdout;
    FILE* fid_in = fopen("/Users/bochen/Downloads/textfile.in", "r+");
    FILE* fid_out = fopen("/Users/bochen/Downloads/textfile.out", "w+");

    int t;
    fscanf(fid_in, "%d", &t);
    for(int cid = 1; cid <= t; cid++){
        int d, p, c[1001]={0};
        fscanf(fid_in, "%d", &d);
//        fprintf(fid_out, "%d\n", d);
        for(int i = 0; i < d; i++){
            fscanf(fid_in, "%d", &p);
//            fprintf(fid_out, "%d ", p);
            c[p]++;
        }
//        fprintf(fid_out, "\n");
        fprintf(fid_out, "Case #%d: %d\n", cid, dfs(c, 1000));
    }
    fclose(fid_in);
    fclose(fid_out);
    return 0;
}
