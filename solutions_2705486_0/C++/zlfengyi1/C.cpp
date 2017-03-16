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
#include <string.h>
#include <fstream>

using namespace std;

const double pi = acos(-1.0);
const double eps = 1E-7;
const int inf = int(1e9)+7;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define sqr(x) ((x)*(x))
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ME(a) memset((a), 0, sizeof((a)))
#define MM(a, b) memcpy((a), (b), sizeof((a)))
#define FOR(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define REP(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

const int WORD_NUM = 521196;
const int MAXN = 1125078 + 5;

int trie[MAXN][26];
int dp[2][MAXN][5];
int isEnd[MAXN];
int tot;

void insert(string s) {
    int x = 0;
    FOR(i,s.size()) {
        int ch = s[i] - 'a';
        if (trie[x][ch] == -1) {
            trie[x][ch] = tot++;
        }
        x = trie[x][ch];
        if (i == s.size()-1) isEnd[x] = 1;
    }
}
void init() {
    memset(trie, -1, sizeof(trie));
    ME(isEnd);
    tot = 1;
    
    ifstream sin("dic.txt");
    string s;
    int num = 0;
    while(sin>>s) {
        insert(s);
        num++;
    }
    insert(s);
  //  cout<<tot<<endl;
}
int hzz() {
    string s;
    cin>>s;
    int cur = 0, next;
    memset(dp, -1, sizeof(dp));
    dp[cur][0][0] = 0;
    for (int rp = 0; rp < s.size(); rp++) {
        int next = cur^1;
        int ch = s[rp] - 'a';
        memset(dp[next], -1, sizeof(dp[next]));
        FOR(i,tot) FOR(j,5) if (dp[cur][i][j] != -1) {
            int value = dp[cur][i][j];
            if (j == 0) {
                FOR(ch2,26) if (ch2 != ch && trie[i][ch2] != -1) {
                    int i2 = trie[i][ch2];
                    if (dp[next][i2][4] == -1 || value+1 < dp[next][i2][4]) {
                        dp[next][i2][4] = value+1;
                    }
                    
                    if (isEnd[i2]) {
                        i2 = 0;
                        if (dp[next][i2][4] == -1 || value+1 < dp[next][i2][4]) {
                            dp[next][i2][4] = value+1;
                        }
                    }
                }
            }
            
            
            int j2 = max(0, j-1);
            
            int i2 = trie[i][ch];
            if (dp[next][i2][j2] == -1 || value < dp[next][i2][j2]) {
                dp[next][i2][j2] = value;
            }
            
            if (isEnd[i2]) {
                i2 = 0;
                if (dp[next][i2][j2] == -1 || value < dp[next][i2][j2]) {
                    dp[next][i2][j2] = value;
                }
            }
        }
        
        cur = next;
    }
    int ans = inf;
    FOR(j,5) if (dp[cur][0][j] != -1)
        ans = min(ans, dp[cur][0][j]);
    return ans;
}
int main()
{
    init();
    int caseNum;
    scanf("%d", &caseNum);
    for (int ca = 1; ca <= caseNum; ca++)
    {
        int ans = hzz();
        
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
