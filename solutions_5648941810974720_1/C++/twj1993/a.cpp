#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;


int a[30], ans[10];
char s[2005];


bool ok(string x) {
    int b[30] = {0};
    for(int i = 0; i < x.length(); i ++) b[x[i] - 'A'] ++;
    for(int i = 0; i < 26; i ++) {
        if(a[i] < b[i]) return 0;
    }
    for(int i = 0; i < 26; i ++) {
        a[i] -= b[i];
    }
    return 1;
}

int main() {
    freopen("A.txt", "r", stdin);
    freopen("A.out", "w", stdout);
    // 0, 2, 4, 6, 8; 5, 7, 9, 1, 3
    int T;
    scanf("%d", &T);
    
    for(int t = 1; t <= T; t ++) {
        scanf("%s", s);
        memset(a, 0, sizeof(a));
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < strlen(s); i ++) a[s[i] - 'A'] ++;
        while(ok("ZERO")) ans[0] ++;
        while(ok("TWO")) ans[2] ++;
        while(ok("FOUR")) ans[4] ++;
        while(ok("SIX")) ans[6] ++;
        while(ok("EIGHT")) ans[8] ++;
        while(ok("FIVE")) ans[5] ++;
        while(ok("SEVEN")) ans[7] ++;
        while(ok("NINE")) ans[9] ++;
        while(ok("ONE")) ans[1] ++;
        while(ok("THREE")) ans[3] ++;
        printf("Case #%d: ", t);
        for(int i = 0; i < 10; i ++) for(int j = 0; j < ans[i]; j ++) printf("%d", i);
        printf("\n");
    }
    return 0;
}