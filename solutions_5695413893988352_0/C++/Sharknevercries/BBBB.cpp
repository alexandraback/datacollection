#include <bits\stdc++.h>
using namespace std;

long long min_ans;
char ans_a[100], ans_b[100];
char a[100], b[100];
int n;

void updateAns(char pa[], char pb[]) {
    long long ta = atoll(pa);
    long long tb = atoll(pb);
    if (min_ans > abs(ta - tb)) {
        min_ans = abs(ta - tb);
        strcpy(ans_a, pa);
        strcpy(ans_b, pb);
    }
    else if (min_ans == abs(ta - tb)) {
        int ret1 = strcmp(ans_a, pa);
        int ret2 = strcmp(ans_b, pb);
        if (ret1 > 0 || ret1 == 0 && ret2 > 0) {
            strcpy(ans_a, pa);
            strcpy(ans_b, pb);
        }
    }
}

void DFS(bool isA) {
    int i;
    if (isA) {
        for (i = 0; i < n && a[i] != '?'; i++)
            ;
        if (i >= n)
            DFS(false);
        else {
            for (int j = 0; j < 10; j++) {
                a[i] = j + '0';
                DFS(true);
                a[i] = '?';
            }
        }
    }
    else {
        for (i = 0; i < n && b[i] != '?'; i++)
            ;
        if (i >= n)
            updateAns(a, b);
        else {
            for (int j = 0; j < 10; j++) {
                b[i] = j + '0';
                DFS(true);
                b[i] = '?';
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    freopen("B-small-attempt6.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, c = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%s %s", a, b);
        n = strlen(a);
        min_ans = 1e18;
        DFS(true);
        printf("Case #%d: %s %s\n", c++, ans_a, ans_b);
    }
    return 0;
}