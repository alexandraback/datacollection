#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <random>
#include <iostream>
#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif

using namespace std;
typedef pair<int, int> ii;
int nTest;
char s[3][22];

int n;
int flag;
char save[22];
char save2[22];
long long curr;
int dq(int i){
    if (i == n){
        long long n1 = 0;
        long long n2 = 0;
        for (int i = 0; i < n; i++){
            n1 = n1 * 10 + s[0][i] - '0';
            n2 = n2 * 10 + s[1][i] - '0';
        }
        // printf("%s %s %lld %lld\n", s[0], s[1], curr, abs(n1 - n2));
        if (curr > abs(n1 - n2)){
            curr = abs(n1 - n2);
            memcpy(save, s[0], sizeof(s[0]));
            memcpy(save2, s[1], sizeof(s[1]));
        } else if (curr == abs(n1 - n2)){
            if (strcmp(s[0], save) == 0 && strcmp(s[1], save2) < 0){
                memcpy(save, s[0], sizeof(s[0]));
                memcpy(save2, s[1], sizeof(s[1]));
            } else if (strcmp(s[0], save) < 0){
                memcpy(save, s[0], sizeof(s[0]));
                memcpy(save2, s[1], sizeof(s[1]));
            }
        }

        return 0;
    }
    
    char temp[22];
    char temp2[22];
    for (int i = 0; i < 22; i++) temp[i] = temp2[i] = '\0';
    if (flag == 0){
        
        if (s[0][i] == '?' && s[1][i] == '?') {
            memcpy(temp, s[0], sizeof(s[0]));
            memcpy(temp2, s[1], sizeof(s[1]));
            

            
            s[0][i] = '0';
            s[1][i] = '1';
            flag = -1;
            dq(i + 1);

            memcpy(s[0], temp, sizeof(temp));
            memcpy(s[1], temp2, sizeof(temp2));
            s[0][i] = '1';
            s[1][i] = '0';
            flag = 1;
            dq(i + 1);



            memcpy(s[0], temp, sizeof(temp));
            memcpy(s[1], temp2, sizeof(temp2));
            s[0][i] = s[1][i] = '0';
            flag = 0;
            dq(i + 1);

        } else if (s[0][i] == '?') {
            memcpy(temp, s[0], sizeof(s[0]));
            memcpy(temp2, s[1], sizeof(s[1]));

            s[0][i] = s[1][i];
            dq(i + 1);
            // if (s[1][0] == '3') printf("fuck\n");
            memcpy(s[0], temp, sizeof(temp));
            memcpy(s[1], temp2, sizeof(temp2));
            // printf("%s %s\n", s[0], s[1]);
            if (s[1][i] > '0') {

                s[0][i] = s[1][i] - 1;
                flag = -1;
                dq(i + 1);
            }

            memcpy(s[0], temp, sizeof(temp));
            memcpy(s[1], temp2, sizeof(temp2));

            if (s[1][i] < '9') {
                s[0][i] = s[1][i] + 1;
                flag = 1;
                dq(i + 1);
            }
        } else if (s[1][i] == '?') {
            memcpy(temp, s[0], sizeof(s[0]));
            memcpy(temp2, s[1], sizeof(s[1]));

            s[1][i] = s[0][i];
            dq(i + 1);

            memcpy(s[0], temp, sizeof(temp));
            memcpy(s[1], temp2, sizeof(temp2));

            if (s[0][i] > '0') {
                s[1][i] = s[0][i] - 1;
                flag = 1;
                dq(i + 1);
            }

            memcpy(s[0], temp, sizeof(temp));
            memcpy(s[1], temp2, sizeof(temp2));

            if (s[0][i] < '9') {
                s[1][i] = s[0][i] + 1;
                flag = -1;
                dq(i + 1);
            }
        } else if (s[0][i] < s[1][i]) flag = -1, dq(i + 1);
        else if (s[0][i] > s[1][i]) flag = 1, dq(i + 1);
        else flag = 0, dq(i + 1);
    } else if (flag == -1){
        if (s[0][i] == '?' && s[1][i] == '?') s[0][i] = '9', s[1][i] = '0';
        else if (s[0][i] == '?') s[0][i] = '9';
        else if (s[1][i] == '?') s[1][i] = '0';
        dq(i + 1);
    } else if (flag == 1){
        if (s[0][i] == '?' && s[1][i] == '?') s[0][i] = '0', s[1][i] = '9';
        else if (s[0][i] == '?') s[0][i] = '0';
        else if (s[1][i] == '?') s[1][i] = '9';
        dq(i + 1);
    }

    return 0;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &nTest);
    for (int test = 1; test <= nTest; test++){
        printf("Case #%d: ", test);
        
        scanf("%s %s\n", s[0], s[1]);

        n = strlen(s[0]);
        flag = 0;
        curr = 999999999999999999LL + 3;
        dq(0);
        printf("%s %s\n", save, save2);
    }
    

    return 0;
}