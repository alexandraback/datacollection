/* 
 * File:   main.cpp
 * Author: tyg3r
 *
 * Created on 13. duben 2013, 22:51
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

bool opened[20];
int openningKey[20];
int chestKeysC[20];
int chestKeys[20][40];
int sorted[20];
int keys[47];
bool visited[1 << 20];
int endHash;
int N;

void open(int cnt, int hash) {
    if(hash == endHash) throw 1;
    if(cnt >= N) return;
    if(visited[hash]) return;
    visited[hash] = true;
    for(int chest = 0, chestH = 1; chest < 20; chest++, chestH <<= 1) {
        if(opened[chest]) continue;
        if(keys[openningKey[chest]] == 0) continue;
        
        opened[chest] = true;
        keys[openningKey[chest]]--;
        for(int i = 0; i < chestKeysC[chest]; i++) keys[chestKeys[chest][i]]++;
        sorted[cnt] = chest;
        
        // rec
        open(cnt+1, hash | chestH);
        
        keys[openningKey[chest]]++;
        for(int i = 0; i < chestKeysC[chest]; i++) keys[chestKeys[chest][i]]--;
        opened[chest] = false;
    }
}

int main(int argc, char** argv) {
    
    int T, K, k;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++) {
        for(int i = 0; i < 20; i++) opened[i] = false;
        for(int i = 1; i <= 40; i++) keys[i] = 0;
        for(int i = (1 << 20) - 1; i >= 0; i--) visited[i] = false;
        scanf("%d %d", &K, &N);
        while(K--) {
            scanf("%d", &k);
            keys[k]++;
        }
        for(int n = 0; n < N; n++) {
            scanf("%d", &openningKey[n]);
            scanf("%d", &chestKeysC[n]);
            for(int k = 0; k < chestKeysC[n]; k++) scanf("%d", &chestKeys[n][k]);
        }
        endHash = (1 << N) - 1;
        bool possible = false;
        try {
            open(0, 0);
        } catch(int e) {
            possible = true;
        }
        printf("Case #%d:", t);
        if(possible) {
            for(int i = 0; i < N; i++) printf(" %d", sorted[i]+1);
        } else {
            printf(" IMPOSSIBLE");
        }
        printf("\n");
    }
    
    return 0;
}

