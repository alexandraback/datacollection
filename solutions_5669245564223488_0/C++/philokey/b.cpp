#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
const int MAXN = 30005;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
const int MOD = 1000000007;
int n;
bool vis[305] ;
char str[105];
char train[105][2];
bool flag;
void change(char str[],int m) {
    int len = strlen(str);
    if (len == 1) {
        if (vis[str[0]]) {flag = 0;}
        vis[str[0]] = 1;
        train[m][0] = train[m][1] = str[0];
        return;
    }
    char chs = str[0], cht = str[n-1];
    int s = 0,t = n-1;
    for (s = 0; s+1 < len; ++s) {
        if (str[s+1] != chs) {
            break;
        }
    }
    for (t = n-1; t-1 >= 0; --t) {
        if (str[t-1] != cht) {
            break;
        }
    }
    vis[str[s]] = 1;
    vis[str[t]] = 1;
    train[m][0] = chs;
    train[m][1] = cht;
    for (int i = s+1; i < t; ++i) {
        if (vis[str[i]]) flag = 0;
    }
}
long long get(int n) {
    if (n == 0) {
        return 0;
    }
    long long ret = 1;
    for (int i = 1; i <= n; ++i) {
        ret = (ret*i)%MOD;
    }
    return ret;
}

int main() {
    freopen("/home/philokey/code/codejam/in.txt","r",stdin);
    int cas;
    scanf("%d",&cas);
    for (int ca = 1; ca <= cas; ++ca) {
        flag = 1;
        scanf("%d",&n);
        for (int i = 0; i < n; ++i) {
            scanf("%s",str);
            change(str,i);
        }

        printf("Case #%d: ",ca);
        if (flag == 0) {
            printf("0\n");
            continue;
        }
        int num[35] = {0};
        int poss[35] = {0},post[35] = {0};

        for (int i = 0; i < n; ++i) {
            if (train[i][0] == train[i][1]) {
                num[train[i][0]-'a']++;
            } else {
                poss[train[i][0]-'a']++;
                post[train[i][1]-'a']++;
            }
        }
        int s,t;
        s = t = -1;
        for (int i = 0; i < 26; ++i) {
            if ((poss[i] == 1 && post[i] == 1)||(poss[i] == 0 && post[i] == 0));
            else if (poss[i]+post[i] == 1){
                if (poss[i] == 1) {
                    if (s == 1) {
                        flag = 0;
                        break;
                    } else {
                        s = 1;
                    }
                } else {
                    if (t == 1) {
                        flag = 0;
                        break;
                    } else {
                        t = 1;
                    }
                }
            } else {
                flag = 0;
                break;
            }
        }
        if (flag == 0) {
            printf("0\n");
            continue;
        }
        long long ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += get(num[i]);
        }
        printf("%lld\n",ans);
    }


    return 0;
}
