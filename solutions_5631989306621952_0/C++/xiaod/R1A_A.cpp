#include <queue>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

#define FIN freopen("A-small-attempt0.in", "r", stdin)
#define FOUT freopen("A-small-attempt0.out", "w", stdout)

const int N = 102;

char s[N];

void work(string &ss) {
    ss = string(1, s[0]);
    for(int i = 1; s[i] != '\0'; ++i) {
        if(s[i] >= ss[0]) {
            ss = string(1, s[i]) + ss;
        }
        else {
            ss = ss + string(1, s[i]);
        }
    }
}

int main() {
    FIN;
    FOUT;
    int T, ncase = 0;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        string ss;
        work(ss);
        printf("Case #%d: %s\n", ++ncase, ss.c_str());
    }
    return 0;
}
