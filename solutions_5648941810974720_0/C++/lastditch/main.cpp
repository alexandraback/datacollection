 //#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <bitset>
#include <string>
#include <queue>
using namespace std;
#define rep(i,l,r) for(i = l; i <= r; i++)
#define red(i,l,r) for(i=(l);i>=(r);i--)
#define u_long unsigned long long
#define fff(i, u) for(i = head[u]; i != -1; i = nxt[i])
#define fin() freopen("in.txt", "r", stdin)
#define fout() freopen("out.txt", "w", stdout)
#define clr(vis, a) memset(vis, a, sizeof(vis))
#define LL long long
#define ls id << 1
#define rs id << 1 | 1
#define lson id << 1, l, mid
#define rson id << 1 | 1, mid + 1, r
#define mid ( (l + r) >> 1 )
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define eps 1e-4
#define pi acos(-1)
const int maxn = 1e5 + 10;
const int maxm = 3e4 + 10;
const int inf = 1e9;
const LL mod = 1e9+7;
int getint() {
    char c;
    while((c = getchar()) && !(c >= '0' && c <= '9') && c != '-');
    int ret = c - '0', sgn = 0;
    if(c == '-') sgn = 1, ret = 0;
    while((c = getchar()) && c >= '0' && c <= '9')
        ret = ret * 10 + c - '0';
    if(sgn) ret = -ret;
    return ret;
}
char s[2100];
int a[10], cnt[100];
char ss[20][20] =
{ "ZERO", "ONE", "TWO", "THREE", "FOUR",
"FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int main(){
    //for(int i = 0;  i < 10; i ++) cout << ss[i] << endl;
    fin();
    fout();
    int T = getint();
    for(int ka = 1; ka <= T; ka ++){
        scanf("%s", s);
        clr(a, 0);
        clr(cnt, 0);
        int len = strlen(s);
        for(int i = 0; i < len; i ++){
            int c = s[i] - 'A';
            cnt[c] ++;
        }
        a[0] = cnt[(int)('Z' - 'A')];
        for(int i = 0; i < 4; i ++){
            int c = ss[0][i] - 'A';
            cnt[c] -= a[0];
        }
        a[2] = cnt[(int)('W' - 'A')];
        for(int i = 0; i < 3; i ++){
            int c = ss[2][i] - 'A';
            cnt[c] -= a[2];
        }
        a[4] = cnt[(int)('U' - 'A')];
        for(int i = 0; i < 4; i ++){
            int c = ss[4][i] - 'A';
            cnt[c] -= a[4];
        }
        a[1] = cnt[(int)('O' - 'A')];
        for(int i = 0; i < 3; i ++){
            int c = ss[1][i] - 'A';
            cnt[c] -= a[1];
        }
        a[6] = cnt[(int)('X' - 'A')];
        for(int i = 0; i < 3; i ++){
            int c = ss[6][i] - 'A';
            cnt[c] -= a[6];
        }
        a[7] = cnt[(int)('S' - 'A')];
        for(int i = 0; i < 5; i ++){
            int c = ss[7][i] - 'A';
            cnt[c] -= a[7];
        }
        a[5] = cnt[(int)('V' - 'A')];
        for(int i = 0; i < 4; i ++){
            int c = ss[5][i] - 'A';
            cnt[c] -= a[5];
        }
        a[8] = cnt[(int)('G' - 'A')];
        for(int i = 0; i < 5; i ++){
            int c = ss[8][i] - 'A';
            cnt[c] -= a[8];
        }
        a[3] = cnt[(int)('T' - 'A')];
        for(int i = 0; i < 5; i ++){
            int c = ss[3][i] - 'A';
            cnt[c] -= a[3];
        }
        a[9] = cnt[(int)('I' - 'A')];
        printf("Case #%d: ", ka);
        for(int i = 0; i < 10; i ++){
            for(int j = 0; j < a[i]; j ++){
                cout << i;
            }
        }
        cout << endl;
    }
    return 0;
}












