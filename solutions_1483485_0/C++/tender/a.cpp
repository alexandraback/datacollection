/*
 * Author: tender
 * Created Time:  2012/4/14 12:40:23
 * File Name: a.cpp
 */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <set>

using namespace std;
const double pi = acos(-1.0);
int hash[300];
char t1[3][102] = {
    "ejp mysljylc kd kxveddknmc re jsicpdrysi",
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
    "de kr kd eoya kw aej tysr re ujdr lkgc jv"
};
char t2[3][102] = {
    "our language is impossible to understand",
    "there are twenty six factorial possibilities",
    "so it is okay if you want to just give up"
};
void init() {
    memset(hash, -1, sizeof(hash));
    for (int i = 0; i < 3; i++)
        for (int j = 0; t1[i][j]; j++) {
            if (t1[i][j] == ' ') continue;
            //if (hash[t1[i][j]] != -1 && hash[t1[i][j]] != t2[i][j]) {
                //printf("i = %d j = %d\n", i, j);
                //while(1);
            //}
            hash[t1[i][j]] = t2[i][j];
        }
    hash['y'] = 'a'; hash['e'] = 'o'; hash['q'] = 'z'; hash['z'] = 'q';
    //bool vis[26];
    //memset(vis, false, sizeof(vis));
    //for (int i = 0; i < 26; i++)
        //if (hash['a' + i] == -1) printf("%c\n", 'a' + i);
        //else vis[hash['a' + i] - 'a'] = true;
    //for (int i = 0; i < 26; i++)
        //if (vis[i] == false) printf("%c\n", 'a' + i);
}
int main() {
    init();
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int cas;
    char str[105];
    scanf("%d", &cas);
    gets(str);
    for (int ii = 1; ii <= cas; ii++) {
        printf("Case #%d: ", ii);
        gets(str);
        for (int j = 0; str[j]; j++)
            if (str[j] == ' ') printf(" ");
            else
                printf("%c", hash[str[j]]);
        printf("\n");
    }
    return 0;
}
