#include <stdio.h>
#include <algorithm>
using namespace std;
char c[110];
int u[30] = {24, 7, 4, 18, 14, 2, 21, 23, 3, 20, 8, 6, 11, 1, 10, 17, 25, 19, 13, 22, 9, 15, 5, 12, 0, 16};
int main(){
    int T, ri = 1, i;
   // sort(u, u + 26);
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    gets(c);
    while (T--){
        gets(c);
        for (i = 0; c[i]; i++){
            if (c[i] >= 'a' && c[i] <= 'z'){
                c[i] = u[c[i] - 'a'] + 'a';
            }
        }
        printf("Case #%d: %s\n", ri++, c);
    }
    return 0;
}
