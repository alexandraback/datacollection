#include <ctime>
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

int solve(int c[], int maxp){
    int min_t = 1001, dp[1001];
    for(int cap = 1; cap <= maxp; cap++){
        int split_t = 0;
        fill(dp, dp+1001, 1001);
        for(int i = 1; i <= cap; i++)
            dp[i] = 0;
        
        for(int i = cap+1; i <= maxp; i++){
            for(int l = 1; l <= i/2; l++)
                dp[i] = min(dp[i], dp[l]+dp[i-l]+1);
            split_t += dp[i]*c[i];
        }
        min_t = min(min_t, split_t+cap);
    }
    return min_t;
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
        int maxp = 0;
        for(int i = 0; i < d; i++){
            fscanf(fid_in, "%d", &p);
            maxp = max(p, maxp);
            c[p]++;
        }
        fprintf(fid_out, "Case #%d: %d\n", cid, solve(c, maxp));
    }
    fclose(fid_in);
    fclose(fid_out);
    return 0;
}
