#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>

using namespace std;

const string str1[] = {
    "ejp mysljylc kd kxveddknmc re jsicpdrysi",
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
    "de kr kd eoya kw aej tysr re ujdr lkgc jv"
};

const string str2[] = {
    "our language is impossible to understand",
    "there are twenty six factorial possibilities",
    "so it is okay if you want to just give up"
};

char real[26];
char used[26];

int main() {
    int tests; scanf("%d\n", &tests);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < str1[i].size(); ++j)
            real[str1[i][j] - 'a'] = str2[i][j];
    real['q' - 'a'] = 'z';
    real['z' - 'a'] = 'q';
    for (int testId = 1; testId <= tests; ++testId) {
        string str;
        getline(cin, str);
        printf("Case #%d: ", testId);
        for (int i = 0; i < str.size(); ++i)
           printf("%c", real[str[i] - 'a']);
        printf("\n");
    }
    return 0;
}
