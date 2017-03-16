#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int counters[1000];
int res[10];

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    
    int tn = 0;
    
    scanf("%d\n", &tn);
    
    for (int t = 1; t <= tn; t++) {
        for (int i = 'A'; i <= 'Z'; i++) {
            counters[i] = 0;
        }
        
        for (int i = 0; i <= 10; i++) {
            res[i] = 0;
        }
        
        char c;
        
        while ((c = getchar()) != '\n') {
            counters[c]++;
        }
        
        res[0] = counters['Z'];
        res[8] = counters['G'];
        res[6] = counters['X'];
        res[4] = counters['U'];
        res[2] = counters['W'];
        res[3] = counters['H'] - res[8];
        res[1] = counters['O'] - res[0] - res[2] - res[4];
        res[7] = counters['S'] - res[6];
        res[5] = counters['V'] - res[7];
        res[9] = counters['I'] - res[8] - res[6] - res[5];
        
        printf("Case #%d: ", t);
               
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < res[i]; j++) {
                printf("%d", i);
            }
        }
        
        
        printf("\n");
    }
    
    return 0;
}