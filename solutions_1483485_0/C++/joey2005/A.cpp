#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <complex>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;

const string a[] = {
    "ejp mysljylc kd kxveddknmc re jsicpdrysi",
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
    "de kr kd eoya kw aej tysr re ujdr lkgc jv"
};

const string b[] = {
    "our language is impossible to understand",
    "there are twenty six factorial possibilities",
    "so it is okay if you want to just give up"
};

map<char, char> mp;
char rep[300];
bool vis[300];
char buf[128];

void main2() {
    gets(buf);
    for (int i = 0; buf[i]; ++i) {
        if (buf[i] != ' ') {
            buf[i] = rep[buf[i]];
        }
    }
    puts(buf);
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.out", "w", stdout);
    mp['a'] = 'y';
    mp['o'] = 'e';
    mp['z'] = 'q';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            if (b[i][j] == ' ') continue;
            if (mp.count(b[i][j]) && mp[b[i][j]] != a[i][j]) {
                cout << "!" << b[i][j] << " " << a[i][j] << " " << mp[b[i][j]] << endl;
            } else {
                mp[b[i][j]] = a[i][j];
                vis[a[i][j]] = true;
            }
        }
    }
    for (char i = 'a'; i <= 'z'; ++i) {
        if (!vis[i]) {
            mp['q'] = i;
        }
    }
    for (char i = 'a'; i <= 'z'; ++i) {
        rep[mp[i]] = i;
    }

    int testCnt;
    scanf("%d", &testCnt);
    gets(buf);
    for (int caseId = 1; caseId <= testCnt; ++caseId) {
        printf("Case #%d: ", caseId);
        main2();
    }
}

