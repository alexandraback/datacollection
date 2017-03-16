#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long LL;

char s[1010];

int main(void) {
    //freopen("B-large.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    int casenum;
    int iCase = 0;
    cin >> casenum;
    while(casenum --) {
        iCase ++;
        cin >> s;
        int len = strlen(s);
        int ans = 0;
        bool flag = false;
        for(int i = len - 1;i >= 0;i --) {
            len = i;
            if(s[i] == '-') {
                flag = true;
                break;
            }
        }
        if(flag == true) ans ++;
        else {
            len = -1;
        }
        int mark = -1;
        for(int i = len;i >= 0;i --) {
            int now;
            if(s[i] == '-') {
                now = -1;
            } else {
                now = 1;
            }
            if(now != mark) {
                ans ++;
                mark *= (-1);
            }
        }
        printf("Case #%d: %d\n", iCase, ans);
    }

    return 0;
}
