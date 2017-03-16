/*
ID: CUGB-wwj
PROG:
LANG: C++
*/
#include <iostream>
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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#define INF 1LL<<60
#define MAXN 1005
#define MAXM 1005
#define L(x) x<<1
#define R(x) x<<1|1
#define eps 1e-4
using namespace std;
int t[111];
int main()
{
    freopen("D:/C-small-attempt0.in","r",stdin);
    freopen("D:/C-small-attempt0.out","w",stdout);
    int T, A, B;
    int cas = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &A, &B);
        printf("Case #%d: ", ++cas);
        int ans = 0;
        for(int i = A; i <= B; i++)
        {
            map<string, int>mp;
            mp.clear();
            char s[11];
            sprintf(s, "%d", i);
            int len = strlen(s);
            string ax = s;
            for(int j = 1; j < len; j++)
            {
                string t = s;
                string tt = s;
                t = t.substr(0, j);
                t = tt.substr(j) + t;
                if(mp[t]) continue;
                mp[t] = 1;
                int tn;
                sscanf(t.c_str(), "%d", &tn);
                int w = 0;
                int tx = tn;
                while(tx) { tx /= 10; w++;}
                if(tn >= i || w < len || tn < A) continue;
                else {   ans++;}
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
