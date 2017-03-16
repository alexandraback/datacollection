#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef long long LL;
int t, k, l, s;
string key, str;
map<int, int> mm;
int sum, num;
int maxsum;
void DFS(string tmp) {
    if(tmp.size() == s) {
        int cnt = 0;
        for(int i = 0; i <= s - l; i++) {
            bool isok = true;
            for(int j = 0; j < l; j++) {
                if(tmp[i + j] != str[j]) {
                    isok = false; break;
                }
            }
            if(isok) cnt++;
        }
        //mm[cnt]++;
        sum += cnt; num++; maxsum = max(maxsum, cnt);
        //cout << "**" << endl;
        return ;
    }
    for(int i = 0; i < k; i++) {
        string ooo = tmp;
        ooo += key[i];
        DFS(ooo);
    }
}
int main() {
    freopen("Bin.in", "r", stdin);
    freopen("Bout.out", "w", stdout);
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++) {
        mm.clear();
        scanf("%d%d%d", &k, &l, &s);
        double ans;
        sum = 0, num = 0, maxsum = -1;
        cin >> key;
        cin >> str;
        DFS("");
        //cout << sum << endl;
        ans = (double)(maxsum) - (double)(sum) / (double)(num);
        printf("Case #%d: %.7lf\n", cas, ans);
    }
    return 0;
}


