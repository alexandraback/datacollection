#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
//#include <unordered_map>
//#define lson x<<1
//#define rson x<<1|1
//#define mid ((lt[x].l+lt[x].r)/2)
//#define ID(x, y) ((x)*m+(y))
//#define CHECK(x, y) ((x)>=0 && (x)<n && (y)>=0 && (y)<m)
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
void Open()
{
    #ifndef ONLINE_JUDGE
        freopen("A-large.in","r",stdin);
        freopen("A-large.out","w",stdout);
    #endif // ONLINE_JUDGE
}
char c[10][222] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int num[222];
int ans[2222];
int dfs(int idx, int st, int res)
{
    if(res == 0){
        return idx;
    }
    if(st > 0 && num['Z'] != 0) return -1;
    if(st > 8 && num['T'] != 0) return -1;
    if(st > 8 && num['G'] != 0) return -1;
    if(st > 8 && num['H'] != 0) return -1;
    if(st > 7 && num['V'] != 0) return -1;
    if(st > 7 && num['S'] != 0) return -1;
    if(st > 6 && num['X'] != 0) return -1;
    if(st > 5 && num['F'] != 0) return -1;
    if(st > 4 && num['O'] != 0) return -1;
    if(st > 4 && num['U'] != 0) return -1;
    if(st > 4 && num['R'] != 0) return -1;
    if(st > 2 && num['W'] != 0) return -1;
    for(int i = st; i < 10; i++)
    {
        int len = strlen(c[i]);
        if(res < len) continue;
        bool flag = true;
        for(int j = 0; j < len; j++) if(num[c[i][j]] == 0) flag = false;
        if(flag == false) continue;
        for(int j = 0; j < len; j++) num[c[i][j]]--;
        ans[idx] = i;
        int rnt = dfs(idx+1, i, res - len);
        if(rnt != -1) return rnt;
        for(int j = 0; j < len; j++) num[c[i][j]]++;
    }
    return -1;
}
char str[2222];
int main()
{
//    Open();
    int T;
    scanf("%d", &T);
    int cas = 1;
    while(T--)
    {
        memset(num, 0, sizeof(num));
//        if(cas == 87) {cas++;continue;}
        scanf("%s", str);
        int len = strlen(str);
        for(int i = 0; i < len; i++)
        {
            num[str[i]]++;
        }
        int idx = dfs(0, 0, len);
//        cerr<<cas<<endl;
        printf("Case #%d: ", cas++);
        for(int i = 0; i < idx; i++)
        {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
