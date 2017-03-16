//#pragma comment(linker,"/STACK:102400000,102400000")
#include<stdio.h>
#include<iostream>
#include<string.h>
//#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#include<list>
//#include<ext/rope>
#define PB push_back
#define MP make_pair
#define PF push_front
#define lson k<<1
#define rson k<<1|1
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ldb;

const int N = 1005;
char str[N];
string s;

string dfs(int l, int r)
{
    if(l > r) return string();
    int id(r);
    for(int i = r - 1; i >= l; i--) if(str[i] > str[id]) id = i;
    return string(1, str[id]) + dfs(l, id - 1) + string(str, id + 1, r - id);
}

int main()
{
#ifdef PKWV
    freopen("in.in", "r", stdin);
#endif // PKWV
//    freopen("A-large.in","r",stdin);
//    freopen("A-large.out","w",stdout);
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        scanf("%s", str);
        s = string(str);
        printf("Case #%d: ", cas);
        int len = strlen(str);
        string res = dfs(0, len - 1);
        cout << res << endl;
    }
    return 0;
}

