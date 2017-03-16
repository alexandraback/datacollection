#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>

#include <thread>
#include <chrono>

#include <memory>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>

using namespace std;

int main() {
    freopen("/Users/lujcmss/Downloads/D-small-attempt0.in.txt", "r", stdin);
    freopen("/Users/lujcmss/Downloads/D-out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    
    for (int kase = 0; kase < T; kase++) {
        int x, r, c;
        cin >> x >> r >> c;
        
        // make sure r <= c
        if (r > c) {
            int t = r;
            r = c;
            c = t;
        }
        
        printf("Case #%d: ", kase+1);
        if (x == 1) {
            printf("GABRIEL\n");
            continue;
        }
        
        if (x == 2) {
            if (r * c % 2) {
                printf("RICHARD\n");
            } else {
                printf("GABRIEL\n");
            }
            continue;
        }
        
        if (x == 3) {
            if (r == 1) {
                printf("RICHARD\n");
            } else if (r * c % 3){
                printf("RICHARD\n");
            } else {
                printf("GABRIEL\n");
            }
            continue;
        }
        
        if (x == 4) {
            if (r == 1 || r == 2) {
                printf("RICHARD\n");
            } else if ((r % 4) && (c % 4)){
                printf("RICHARD\n");
            } else {
                printf("GABRIEL\n");
            }
            continue;
        }
        
        if (x == 5) {
            if (r == 1 || r == 2) {
                printf("RICHARD\n");
            } else if (r == 3){
                if (c % 10) {
                    printf("RICHARD\n");
                } else {
                    printf("GABRIEL\n");
                }
            } else if (r * c % 5){
                printf("RICHARD\n");
            } else {
                printf("GABRIEL\n");
            }
            continue;
        }
        
        if (x == 6) {
            if (r == 1 || r == 2 || r == 3) {
                printf("RICHARD\n");
            } else if ((r % 6) && (c % 6)) {
                printf("RICHARD\n");
            } else {
                printf("GABRIEL\n");
            }
            continue;
        }
        
        if (x >= 7) {
            printf("RICHARD\n");
        }
    }
    
    return 0;
}