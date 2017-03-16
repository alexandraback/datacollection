#include <stdio.h>
#include <string.h>
#include <algorithm>
char s[2048];
char d[10][16] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int order[10] = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
int alph[128];
int res[2048];
int resn = 0;
bool check_digit(int digit) {
    bool check = true;
    for(int j = 0; d[digit][j]; j++) {
        check &= alph[d[digit][j]] > 0;
    }
    if(!check)
        return false;
    
    for(int j = 0; d[digit][j]; j++) {
        alph[d[digit][j]]--;
    }
    res[resn++]= digit; 
    return true;
}

void solve(char *s) {
    memset(alph, 0, sizeof(alph));
    for(int i = 0; s[i]; i++)
        alph[s[i]]++;
    resn = 0;
    for(int i = 0; i < 10; i++) {
        while(check_digit(order[i])) {
        }
    }    
    std::sort(res, res+resn);
    for(int i =0; i < resn; i++)
        printf("%d", res[i]);
    
}
int main() {
    int T, n;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%s", s);
        printf("Case #%d: ", i);
        solve(s);
        printf("\n");
    }
    return 0;
}
    
