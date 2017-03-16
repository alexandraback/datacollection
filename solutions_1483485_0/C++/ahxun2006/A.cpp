#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;

char toChar[26];
string src[] = {
"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv"
};
string trg[] = {
"our language is impossible to understand",
"there are twenty six factorial possibilities",
"so it is okay if you want to just give up"
};

char str[128];

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.txt", "w", stdout);
    for (int i = 0; i < 3; ++i) {
        int n = (int)src[i].length();
        for (int j = 0; j < n; ++j)
            if (src[i][j] != ' ') {
                toChar[src[i][j] - 'a'] = trg[i][j];
            }
    }
    toChar['z' - 'a'] = 'q';
    toChar['q' - 'a'] = 'z';
    for (int i = 0; i < 26; ++i) {
        if (toChar[i] > 0)
            ;//cout <<(char)(i + 'a') << " " << toChar[i] << " " << endl;
    }
    int T;
    scanf("%d" ,&T);
    getchar();
    for (int caseId = 1; caseId <= T; ++caseId) {
        gets(str);
        int len = strlen(str);
       // cout << str << " " << len << endl;
        for (int i = 0; i < len; ++i)
            if (!isspace(str[i]))
               str[i] = toChar[str[i] - 'a'];
        printf("Case #%d: %s\n", caseId, str);
    }
    return 0;
}
