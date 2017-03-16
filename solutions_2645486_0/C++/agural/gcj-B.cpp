/*
LANG: C++
ID: 2012agural
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <ctime>

using namespace std;
FILE *fin  = fopen("inb.in",  "r");
FILE *fout = fopen("outb.out", "w");
/*
* Keep arrays small.  Smaller than 4,000,000 integers or 2,000,000 long longs/doubles
*/

long long dp[10000005][2];

int main () {
	int T, E, R, N, v;
	fscanf(fin, "%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        fscanf(fin, "%d %d %d", &E, &R, &N);
        
        fscanf(fin, "%d", &v);
        for(int j = 0; j <= E; j++)
            dp[j][0] = v * (E - j);

        for(int i = 1; i < N; i++) {
            fscanf(fin, "%d", &v);
            long long m = 0;
            for(int k = E - R; k <= E; k++) m = max(m, dp[k][0]);
            dp[E][1] = m;

            for(int j = E - 1; j >= 0; j--) {
                int temp = max(0, j-R);
                dp[j][1] = max(dp[j+1][1] + v, dp[temp][0]);
            }
            /*for(int j = 0; j <= E; j++) {
                long long m = 0;
                for(int k = max(j, R); k <= E; k++) {
                    m = max(m, dp[k-2][0] + v * (k - j));
                }
                dp[j][1] = m;
            }*/
            for(int j = 0; j <= E; j++) {
                dp[j][0] = dp[j][1];
                //printf("%lld ", dp[j][0]);
            }
            //printf("\n\n");
        }
        long long m = 0;
        for(int i = 0; i <= E; i++) m = max(m, dp[i][0]);
        fprintf(fout, "Case #%d: %lld\n", tc, m);
    }

	return 0;
}


