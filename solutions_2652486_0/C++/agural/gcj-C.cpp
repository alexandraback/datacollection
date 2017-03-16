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
FILE *fin  = fopen("inc.in",  "r");
FILE *fout = fopen("outc.out", "w");
/*
* Keep arrays small.  Smaller than 4,000,000 integers or 2,000,000 long longs/doubles
*/

int freq[8][6];

int main () {
	int T=1, R=100, N=3, M=5, K=7, v;
	fscanf(fin, "%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        fprintf(fout, "Case #1:\n");
        fscanf(fin, "%d %d %d %d", &R, &N, &M, &K);
        for(int r = 0; r < R; r++) {
            for(int i = 0; i < 8; i++)
                for(int j = 0; j < 6; j++)
                    freq[i][j] = 0;
            for(int k = 0; k < K; k++) {
                fscanf(fin, "%d", &v);
                int temp = v;
                while(temp % 2 == 0) {freq[k][2]++; temp /= 2;} temp = v;
                while(temp % 3 == 0) {freq[k][3]++; temp /= 3;} temp = v;
                while(temp % 4 == 0) {freq[k][4]++; temp /= 4;} temp = v;
                while(temp % 5 == 0) {freq[k][5]++; temp /= 5;} 
            }
            for(int j = 2; j < 6; j++) {
                int m1 = 0;
                for(int i = 0; i < 7; i++) m1 = max(m1, freq[i][j]);
                freq[7][j] = m1;
            }
            /*for(int i = 2; i <= M; i++)
                printf("%d ", freq[7][i]);
            printf("\n");*/
            int np = freq[7][3] + freq[7][5];
            for(int i = 0; i < freq[7][3]; i++) fprintf(fout, "3");
            for(int i = 0; i < freq[7][5]; i++) fprintf(fout, "5");

            if(np == 2) {
                if(freq[7][4] > 0) fprintf(fout, "4");
                else fprintf(fout, "2");
            }
            if(np == 1) {
                for(int i = 0; i < freq[7][4]; i++) fprintf(fout, "4");
                for(int i = 0; i < 3-np-freq[7][4]; i++) fprintf(fout, "2");
            }
            if(np == 0) {
                for(int i = 0; i < freq[7][4]; i++) fprintf(fout, "4");
                for(int i = 0; i < 3-freq[7][4]; i++) fprintf(fout, "2");
            }
            fprintf(fout, "\n");
        }
        
    }

	return 0;
}


