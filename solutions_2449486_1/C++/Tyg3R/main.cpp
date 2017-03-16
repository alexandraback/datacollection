/* 
 * File:   main.cpp
 * Author: tyg3r
 *
 * Created on 13. duben 2013, 1:58
 */

#include <cstdlib>
#include <stdio.h>

#define MAX 107

using namespace std;

int T, N, M;
int lawn[MAX][MAX];
int row[MAX], col[MAX];

bool valid() {
    for(int i = 0; i < MAX; i++) row[i] = col[i] = 0;
    for(int n = 0; n < N; n++) for(int m = 0; m < M; m++) {
        if(lawn[n][m] > row[n]) row[n] = lawn[n][m];
        if(lawn[n][m] > col[m]) col[m] = lawn[n][m];
    }
    for(int n = 0; n < N; n++) for(int m = 0; m < M; m++) {
        if(lawn[n][m] != row[n] && lawn[n][m] != col[m]) return false;
    }
    return true;
}

int main(int argc, char** argv) {
    
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        scanf("%d %d", &N, &M);
        for(int n = 0; n < N; n++) for(int m = 0; m < M; m++) scanf("%d", &lawn[n][m]);
        if(valid()) printf("Case #%d: YES\n", t);
        else printf("Case #%d: NO\n", t);
    }
    
    return 0;
}

