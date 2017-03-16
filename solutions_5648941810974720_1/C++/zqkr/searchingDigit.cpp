#pragma region Template
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <vector>
#include <list>
#include <utility>
#include <functional>
#include <algorithm>
#include <set>
#include <stack>
#include <cassert>
#include <cctype>
#include <cmath>
#include <deque>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define SZ(a)        ((int)a.size())
#define LENGTH(a)    ((int)a.length())
#define ALL(a)       a.begin(), a.end()
#define REP(i, n)    for(int i = 0; i < (n); i++)
#define INC(i, a, b) for(int i = (a); i <= (b); i++)
#define DEC(i, a, b) for(int i = (a); i >= (b); i--)
#define CLEAR(a, b)  memset(a, b, sizeof a)
#define X            first
#define Y            second
#define si(a)        scanf("%d", &a)
#define ss(a)        scanf("%s", a)
#define sll(a)       scanf("%lld", &a)

typedef long long int LL;

const double PI = acos(-1.0);
const double EPS = 1e-9;
const int    inf = 1000000000;
const LL     INF = ((LL)inf)*inf;
#pragma endregion

#define LIM 100000

char inp[LIM];
int cnt[26], ans[10];

char alpha[][10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char reQ[] = "ZXWGSUFHOI";
char reN[] = "0628745319";

int main(void) {
    int tcase; si(tcase);
    REP(_i, tcase) {
        ss(inp);
        int len = strlen(inp);
        CLEAR(cnt, 0);
        CLEAR(ans, 0);
        REP(i, len) {
            cnt[inp[i]-'A']++;
        }
        REP(i, 10) {
            int curr = cnt[reQ[i] - 'A'];
            if(curr == 0) continue;
            ans[reN[i] - '0'] = curr;
            int ll = strlen(alpha[reN[i] - '0']);
            REP(j, ll) cnt[alpha[reN[i] - '0'][j] - 'A'] -= curr;
        }

        printf("Case #%d: ", _i+1);
        REP(i, 10) {
            while(ans[i] > 0) {
                printf("%d", i);
                ans[i]--;
            }
        }
        printf("\n");
    }
}
