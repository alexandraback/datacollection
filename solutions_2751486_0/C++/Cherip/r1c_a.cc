#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

const int MAXLINE = 200;
char line[MAXLINE];
int n;
int canStart[MAXLINE];
int next[MAXLINE];
int len;
char word[] = {'a', 'e', 'i', 'o', 'u'};

int pre() {
    //printf("%d %d\n", len, n);
    for (int i = 0; i <= len - n; i++) {
        canStart[i] = 1;
        //printf("%d %c\n", j, line[j]);
        for (int j = i; j < n + i; j++) {
            for (int k = 0; k < 5; k++) {
                //printf("%d %c\n", j, line[j]);
                if (line[j] == word[k]) {
                    canStart[i] = 0;
                    break;
                }
            }
            if (canStart[i] == 0)
                break;
        }
    }

    for (int i = 0; i <= len - n; i++) {
        int find = i;
        //printf("?? %d\n", canStart[i]);
        while (canStart[find] == 0 && find < len) {
            find++;
        }
        next[i] = find;
    }

    int ret = 0;
    for (int i = 0; i <= len - n; i++) {
        int cur = len - next[i] - n + 1;
        //printf("?%d %d\n", cur, next[i]);
        if (cur > 0)
            ret += cur;
    }

    return ret;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("answer", "w", stdout);

    int t;
    scanf("%d", &t);
    for (int idx = 1; idx <= t; idx++) {
        printf("Case #%d: ", idx);

        scanf("%s %d", line, &n);
        len = strlen(line);
        printf("%d\n", pre());
    }
}
