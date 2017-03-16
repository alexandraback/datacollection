/*
 *
 * Tag: Implementation
 * Time: O(n)
 * Space: O(n)
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 50;
const int M = 30110;
const long long MOD = 1000000007;
const double eps = 1e-10;
char s[M];
bool vis[M];
int phone[N], cnt[N], cntres[N];
string dict[]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

void finddigit(int op){
    memset(cnt, 0, sizeof(cnt));
    bool isfind = true;
    int res = 10;
    switch (op) {
        case 0:
            for (int i = 0; s[i]; ++ i) {
                if ((s[i] == 'Z' || s[i] == 'E' || s[i] == 'R' || s[i] == 'O') && !vis[i]) {
                    ++ cnt[(s[i] - 'A')];
                }
            }
            for (int i = 0; i < dict[op].size(); ++ i) {
           //     printf("%d, %c, %d\n",op, dict[op][i],cnt[dict[op][i] - 'A']);
                res = min(res, cnt[dict[op][i] - 'A']);
            }
            if (res) {
                phone[op] = res;
           //     printf("op = %d, res = %d\n",op,res);
                for (int i = 0; i < dict[op].size(); ++ i) {
                    cntres[dict[op][i] - 'A'] = res;
                }
                for (int i = 0; s[i]; ++ i) {
                    if ((s[i] == 'Z' || s[i] == 'E' || s[i] == 'R' || s[i] == 'O') && !vis[i] && cntres[s[i] - 'A']) {
               //         printf("i = %d\n",i);
                        vis[i] = 1;
                        -- cntres[s[i] - 'A'];
                    }
                }
            }
            break;
        
        case 1:
            for (int i = 0; s[i]; ++ i) {
                if ((s[i] == 'O' || s[i] == 'N' || s[i] == 'E') && !vis[i]) {
                    ++ cnt[(s[i] - 'A')];
                  //  puts(" -- ");
                }
            }
            for (int i = 0; i < dict[op].size(); ++ i) {
                res = min(res, cnt[dict[op][i] - 'A']);
            }
            if (res) {
                phone[op] = res;
                for (int i = 0; i < dict[op].size(); ++ i) {
               //     printf("%d, %c, %d\n",op, dict[op][i],cnt[dict[op][i] - 'A']);
                    cntres[dict[op][i] - 'A'] = res;
                }
                for (int i = 0; s[i]; ++ i) {
                    if ((s[i] == 'O' || s[i] == 'N' || s[i] == 'E') && !vis[i] && cntres[s[i] - 'A']) {
                        vis[i] = 1;
                        -- cntres[s[i] - 'A'];
                    }
                }
            }
            break;
            
        case 2:
            for (int i = 0; s[i]; ++ i) {
                if ((s[i] == 'T' || s[i] == 'W' || s[i] == 'O') && !vis[i]) {
                    ++ cnt[(s[i] - 'A')];
                }
            }
            for (int i = 0; i < dict[op].size(); ++ i) {
                res = min(res, cnt[dict[op][i] - 'A']);
            }
            if (res) {
                phone[op] = res;
                for (int i = 0; i < dict[op].size(); ++ i) {
                    cntres[dict[op][i] - 'A'] = res;
                }
                for (int i = 0; s[i]; ++ i) {
                    if ((s[i] == 'T' || s[i] == 'W' || s[i] == 'O') && !vis[i] && cntres[s[i] - 'A']) {
                        vis[i] = 1;
                        -- cntres[s[i] - 'A'];
                    }
                }
            }
            break;
        
        case 3:
            for (int i = 0; s[i]; ++ i) {
                if ((s[i] == 'T' || s[i] == 'H' || s[i] == 'R' || s[i] == 'E' || s[i] == 'E') && !vis[i]) {
                    ++ cnt[(s[i] - 'A')];
                }
            }
            for (int i = 0; i < dict[op].size(); ++ i) {
                res = min(res, cnt[dict[op][i] - 'A']);
            }
            if (res) {
                phone[op] = res;
                for (int i = 0; i < dict[op].size(); ++ i) {
                    cntres[dict[op][i] - 'A'] = res;
                }
                for (int i = 0; s[i]; ++ i) {
                    if ((s[i] == 'T' || s[i] == 'H' || s[i] == 'R' || s[i] == 'E' || s[i] == 'E') && !vis[i] && cntres[s[i] - 'A']) {
                        vis[i] = 1;
                        -- cntres[s[i] - 'A'];
                    }
                }
            }
            break;
        
        case 4:
            for (int i = 0; s[i]; ++ i) {
                if ((s[i] == 'F' || s[i] == 'O' || s[i] == 'U' || s[i] == 'R') && !vis[i]) {
                    ++ cnt[(s[i] - 'A')];
                }
            }
            for (int i = 0; i < dict[op].size(); ++ i) {
                res = min(res, cnt[dict[op][i] - 'A']);
            }
            if (res) {
                phone[op] = res;
                for (int i = 0; i < dict[op].size(); ++ i) {
                    cntres[dict[op][i] - 'A'] = res;
                }
                for (int i = 0; s[i]; ++ i) {
                    if ((s[i] == 'F' || s[i] == 'O' || s[i] == 'U' || s[i] == 'R') && !vis[i] && cntres[s[i] - 'A']) {
                        vis[i] = 1;
                        -- cntres[s[i] - 'A'];
                    }
                }
            }
            break;
           
        case 5:
            for (int i = 0; s[i]; ++ i) {
                if ((s[i] == 'F' || s[i] == 'I' || s[i] == 'V' || s[i] == 'E') && !vis[i]) {
                    ++ cnt[(s[i] - 'A')];
                }
            }
            for (int i = 0; i < dict[op].size(); ++ i) {
                res = min(res, cnt[dict[op][i] - 'A']);
            }
            if (res) {
                phone[op] = res;
                for (int i = 0; i < dict[op].size(); ++ i) {
                    cntres[dict[op][i] - 'A'] = res;
                }
                for (int i = 0; s[i]; ++ i) {
                    if ((s[i] == 'F' || s[i] == 'I' || s[i] == 'V' || s[i] == 'E') && !vis[i] && cntres[s[i] - 'A']) {
                        vis[i] = 1;
                        -- cntres[s[i] - 'A'];
                    }
                }
            }
            break;
        
        case 6:
            for (int i = 0; s[i]; ++ i) {
                if ((s[i] == 'S' || s[i] == 'I' || s[i] == 'X') && !vis[i]) {
                    ++ cnt[(s[i] - 'A')];
                }
            }
            for (int i = 0; i < dict[op].size(); ++ i) {
                res = min(res, cnt[dict[op][i] - 'A']);
            }
            if (res) {
                phone[op] = res;
                for (int i = 0; i < dict[op].size(); ++ i) {
                    cntres[dict[op][i] - 'A'] = res;
                }
                for (int i = 0; s[i]; ++ i) {
                    if ((s[i] == 'S' || s[i] == 'I' || s[i] == 'X') && !vis[i] && cntres[s[i] - 'A']) {
                        vis[i] = 1;
                        -- cntres[s[i] - 'A'];
                    }
                }
            }
            break;
        
        case 7:
            for (int i = 0; s[i]; ++ i) {
                if ((s[i] == 'S' || s[i] == 'E' || s[i] == 'V' || s[i] == 'E' || s[i] == 'N') && !vis[i]) {
                    ++ cnt[(s[i] - 'A')];
                }
            }
            for (int i = 0; i < dict[op].size(); ++ i) {
                res = min(res, cnt[dict[op][i] - 'A']);
            }
            if (res) {
                phone[op] = res;
                for (int i = 0; i < dict[op].size(); ++ i) {
                    cntres[dict[op][i] - 'A'] = res;
                }
                for (int i = 0; s[i]; ++ i) {
                    if ((s[i] == 'S' || s[i] == 'E' || s[i] == 'V' || s[i] == 'E' || s[i] == 'N')  && !vis[i] && cntres[s[i] - 'A']) {
                        vis[i] = 1;
                        -- cntres[s[i] - 'A'];
                    }
                }
            }
            break;
            
        case 8:
            for (int i = 0; s[i]; ++ i) {
                if ((s[i] == 'E' || s[i] == 'I' || s[i] == 'G' || s[i] == 'H' || s[i] == 'T') && !vis[i]) {
                    ++ cnt[(s[i] - 'A')];
                }
            }
            for (int i = 0; i < dict[op].size(); ++ i) {
                res = min(res, cnt[dict[op][i] - 'A']);
            }
            if (res) {
                phone[op] = res;
                for (int i = 0; i < dict[op].size(); ++ i) {
                    cntres[dict[op][i] - 'A'] = res;
                }
                for (int i = 0; s[i]; ++ i) {
                    if ((s[i] == 'E' || s[i] == 'I' || s[i] == 'G' || s[i] == 'H' || s[i] == 'T') && !vis[i] && cntres[s[i] - 'A']) {
                        vis[i] = 1;
                        -- cntres[s[i] - 'A'];
                    }
                }
            }
            break;
            
        case 9:
            for (int i = 0; s[i]; ++ i) {
                if ((s[i] == 'N' || s[i] == 'I' || s[i] == 'N' || s[i] == 'E') && !vis[i]) {
                    ++ cnt[(s[i] - 'A')];
                }
            }
            for (int i = 0; i < dict[op].size(); ++ i) {
                res = min(res, cnt[dict[op][i] - 'A']);
            }
            if (res) {
                phone[op] = res;
                for (int i = 0; i < dict[op].size(); ++ i) {
                    cntres[dict[op][i] - 'A'] = res;
                }
                for (int i = 0; s[i]; ++ i) {
                    if ((s[i] == 'N' || s[i] == 'I' || s[i] == 'N' || s[i] == 'E') && !vis[i] && cntres[s[i] - 'A']) {
                        vis[i] = 1;
                        -- cntres[s[i] - 'A'];
                    }
                }
            }
            break;
            
        default:
            break;
    }
}

int main() {
    freopen("/Users/ybc/Project/CCPP/ACM/A-large.in", "r", stdin);
    freopen("/Users/ybc/Project/CCPP/ACM/out.txt", "w", stdout);
    int T;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; ++ cas) {
        scanf("%s",s);
        memset(phone, 0, sizeof(phone));
        memset(vis, 0, sizeof(vis));
        finddigit(0);
        finddigit(2);
        finddigit(4);
        finddigit(8);
        finddigit(5);
        finddigit(6);
        finddigit(7);
        finddigit(9);
        finddigit(1);
        finddigit(3);
        printf("Case #%d: ", cas);
        for (int i = 0; i < 10; ++ i) {
            while (phone[i]) {
                printf("%d",i);
                -- phone[i];
            }
        }
        puts("");
    }
    return 0;
}
