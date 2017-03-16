#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>
#include<cmath>
using namespace std;

#define LL long long int
#define PII pair<int,int>
#define PB push_back
#define MP make_pair
#define INF 1000000000
int cnt[500];
int main() {
    char a[4][4];
    int t, i, j,ct = 0;
    scanf("%d", &t);

    while(t--) {
        ct ++;
        printf("Case #%d: ",ct);
        for(i = 0; i < 4; i++) {
            for(j = 0; j < 4; j++)
                scanf(" %c", &a[i][j]);
        }

        for(i = 0; i < 4; i++) {
            cnt['O'] = cnt['T'] = cnt['X'] = 0;

            for(j = 0; j < 4; j++)
                cnt[a[i][j]]++;

            if(cnt['O'] + cnt['T'] == 4) {
                printf("O won\n");
                break;

            } else if(cnt['X'] + cnt['T'] == 4) {
                printf("X won\n");
                break;
            }
        }

        if(i != 4)continue;

        for(i = 0; i < 4; i++) {
            cnt['O'] = cnt['T'] = cnt['X'] = 0;

            for(j = 0; j < 4; j++)
                cnt[a[j][i]]++;

            if(cnt['O'] + cnt['T'] == 4) {
                printf("O won\n");
                break;

            } else if(cnt['X'] + cnt['T'] == 4) {
                printf("X won\n");
                break;
            }
        }

        if(i != 4)continue;

        cnt['O'] = cnt['T'] = cnt['X'] = 0;

        for(i = 0; i < 4; i++) {
            cnt[a[i][i]] ++;
        }

        if(cnt['O'] + cnt['T'] == 4) {
            printf("O won\n");
            continue;

        } else if(cnt['X'] + cnt['T'] == 4) {
            printf("X won\n");
            continue;
        }

        cnt['O'] = cnt['T'] = cnt['X'] = 0;

        for(i = 0; i < 4; i++) {
            cnt[a[i][3 - i]]++;
        }

        if(cnt['O'] + cnt['T'] == 4) {
            printf("O won\n");
            continue;

        } else if(cnt['X'] + cnt['T'] == 4) {
            printf("X won\n");
            continue;
        }

        for(i = 0; i < 4; i++) {
            for(j = 0; j < 4; j++) {
                if(a[i][j] == '.') {
                    printf("Game has not completed\n");
                    i = 100;
                    break;
                }
            }
        }

        if(i == 4) {
            printf("Draw\n");
        }
    }

    return 0;
}

