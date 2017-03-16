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

int counters[100][100];

int ss[100];
int ps[100];

int res[5000][3];
int res_n = 0;

int main() {
    freopen("C-small.in", "r", stdin);
    freopen("C-small.out", "w", stdout);
    
    int tn = 0;
    
    scanf("%d\n", &tn);
    
    for (int t = 1; t <= tn; t++) {
        int rn, p, s, k;
        
        scanf("%d%d%d%d", &rn, &p, &s, &k);
        
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < p; j++) {
                counters[i][j] = k;
            }
        }
        
        res_n = 0;
        
        for (int r = 0; r < rn; r++) {
            for (int i = 0; i < s; i++)
                ss[i] = k;
            
            for (int i = 0; i < p; i++)
                ps[i] = k;
             
            for (int i = 0; i < s; i++) {
                for (int j = 0; j < p; j++) {
                    if (ss[i] == 0)
                        break;
                    
                    if (ps[j] > 0 && counters[i][j] > 0) {
                        ss[i]--;
                        ps[j]--;
                        counters[i][j]--;
                        
                        res[res_n][0] = r + 1;
                        res[res_n][1] = j + 1;
                        res[res_n][2] = i + 1;
                        
                        res_n++;
                    }
                }
            }
        }
        
        printf("Case #%d: %d\n", t, res_n);
        
        for (int i = 0; i < res_n; i++) {
            printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
        }
    }
    
    return 0;
}