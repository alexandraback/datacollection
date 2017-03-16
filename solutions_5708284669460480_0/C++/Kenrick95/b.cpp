#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
//#include <bits/stdc++.h>
#define INF 1000000007
#define INFLL 9223372036854775807LL

typedef long long int64;
typedef unsigned long long qword;
using namespace std;

/**
 * @problem 
 * @url    
 * @status  
 */

int T, t;
int k, l, s;
char pos[128], target[128];
int max_count = 0;

double f(int d, char ca[]) {
    // printf("%d %s\n", d, ca);
    if (d == s) {
        // printf("%d %s\n", d, ca);
        // count substring!
        bool cur_has = true;
        int has_count = 0;
        for (int i = 0; i < s; i++) {
            cur_has = true;
            for (int j = 0; j < l; j++) {
                if (ca[i + j] != target[j]) {
                    cur_has = false;
                    break;
                }
            }
            if (cur_has) {
                has_count++;
            }
        }
        if (has_count > 0) {
            max_count = max(max_count, has_count);
            // printf("%d %s: %d\n", d, ca, has_count);
            return has_count * 1.;
        } else {
            return 0.0;
        }
    }

    double ret = 0.0;
    char temp[128];
    strcpy(temp, ca);
    temp[d + 1] = '\0';
    for (int i = 0; i < k; i++) {
        temp[d] = pos[i];
        ret += (double) f(d + 1, temp) / ((double) k);
    }
    return ret;
}

int main(){
    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d %d", &k, &l, &s);
        scanf("%s", pos);
        scanf("%s", target);
        char empty[] = "";
        max_count = 0;
        double ans = f(0, empty);

        printf("Case #%d: %.7lf\n", t, (double) (max_count * 1.) - ans);
    }
    return 0;
}
