#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <map>
#include <cassert>
#include <queue>
using namespace std;
#define ll long long
#define maxn 105000

char c[10], j[10];

void dfs(char c[10], int val, int cur, int len, vector<int> &v)
{
    if (cur == len) {
        v.push_back(val);
        return;
    }
    if (isdigit(c[cur])){
        val = val * 10 + c[cur] - '0';
        dfs(c, val, cur + 1, len, v);
    }
    else {
        for (int i = 0; i < 10; ++i) {
            dfs(c, val * 10 + i, cur + 1, len, v);
        }
    }
}

void print(int val, int d)
{
    char buf[10];
    sprintf(buf, "%d", val);
    int z = d - strlen(buf);
    for (int i = 0; i<z; ++i){
        printf("0");
    }
    printf("%s", buf);
}

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int T; cin >> T; int ca = 0;
    while (T--){
        scanf("%s", c);
        scanf("%s", j);
        int n = strlen(c);
        vector<int> lv;
        vector<int> rv;
        dfs(c, 0, 0, n, lv);
        dfs(j, 0, 0, n, rv);
        int la, ra;
        int ans = 1e9;
        //cout << lv.size() << " " << rv.size() << endl;
        for (int x = 0; x<lv.size(); ++x) {
            for (int y = 0; y < rv.size(); ++y) {
                if (abs(lv[x] - rv[y]) < ans) {
                    la = lv[x];
                    ra = rv[y];
                    ans = min(ans, abs(lv[x] - rv[y]));
                }
                else if (abs(lv[x] - rv[y]) == ans) {
                    if (lv[x] < la) {
                        la = lv[x];
                        ra = rv[y];
                        ans = min(ans, abs(lv[x] - rv[y]));
                    }
                    else if (lv[x] == la) {
                        if (rv[y] < ra) {
                            la = lv[x];
                            ra = rv[y];
                            ans = min(ans, abs(lv[x] - rv[y]));
                        }
                    }
                }
            }
        }
        printf("Case #%d: ", ++ca);
        print(la, n);
        printf(" ");
        print(ra, n);
        puts("");
    }
    return 0;
}



