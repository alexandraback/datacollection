#include <bits/stdc++.h>

using namespace std;

char txt[10][10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX",
    "SEVEN", "EIGHT", "NINE"};

int so[10] = {0,2,6,4,1,7,8,5,3,9};
char dh[] = "ZWXUOSGFTE";

int cnt[300];
int ans[20];
char s[2005];

int main() {
    int ct;
    scanf("%d", &ct);
    for (int nt = 1; nt <= ct; nt++) {
        scanf("%s", s);
        for (int i = 0; i < 26; i++) cnt[i+'A'] = 0;

        for (int i = 0; s[i] != 0; i++)
            cnt[s[i]]++;

        printf("Case #%d: ", nt);
        for (int i = 0; dh[i] != 0; i++) {
            int tmp = cnt[dh[i]];
            ans[so[i]] = tmp;
            for (int j = 0; txt[so[i]][j] != 0; j++)
                cnt[txt[so[i]][j]] -= tmp;
        }
        for (int i = 0; i < 10; i++)
            while (ans[i]--) printf("%d",i);
        printf("\n");
    }
    return 0;
}
