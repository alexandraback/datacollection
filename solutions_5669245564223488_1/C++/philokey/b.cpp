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
        vis[str[0]] = 1;
        train[m][0] = train[m][1] = str[0];
        return;
    }
    char chs = str[0], cht = str[len-1];
    vis[chs] = 1;
    vis[cht] = 1;
    if (chs == cht) {
        flag = 0;
    }
    train[m][0] = chs;
    train[m][1] = cht;
    int s = 0,t = len-1;
    for (int i = s+1; i < t; ++i) {
        if (vis[str[i]]) flag = 0;
    }
}
long long get(int n) {
    if (n == 0) {
        return 1;
    }
    long long ret = 1;
    for (int i = 1; i <= n; ++i) {
        ret = (ret*i)%MOD;
    }
    return ret;
}

int main() {
    freopen("/home/philokey/code/codejam/B-large.in","r",stdin);
    freopen("/home/philokey/code/codejam/out.txt","w",stdout);
    int cas;
    char tmp[105];
    scanf("%d",&cas);
    for (int ca = 1; ca <= cas; ++ca) {
        flag = 1;
        scanf("%d",&n);
        printf("Case #%d: ",ca);

        memset(vis,0,sizeof(vis));
        for (int i = 0; i < n; ++i) {
            scanf("%s",tmp);
            int p = 0;
            for (int j = 0; tmp[j]; ++j) {
                if (tmp[j]!= tmp[j+1]) {
                    str[p++] = tmp[j];
                }
            }
            str[p] = '\0';
            change(str,i);
        }


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
        s = t = 0;
        for (int i = 0; i < 26; ++i) {
            if ((poss[i] == 1 && post[i] == 1)||(poss[i] == 0 && post[i] == 0));
            else if (poss[i]+post[i] == 1){
                if (poss[i] == 1) {
                    ++s;
                } else {
                    ++t;
                }
            } else {
                flag = 0;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if ((train[i][0] == train[j][1]&&train[j][0] == train[i][1]) || (train[i][1] == train[j][0]&&train[j][1] == train[i][0]))
                {
                    if (train[i][0] != train[i][1])
                        flag = 0;
                }

            }
        }
        if (flag == 0 || s!=t) {
            printf("0\n");
            continue;
        }
        for (int i = 0; i < 26; ++i) {
            if ((poss[i]+post[i]) == 0 && num[i]) { ++s;}
        }
        long long ans = get(s);
        for (int i = 0; i < 26; ++i) {
            ans = (ans*get(num[i]))%MOD;
        }
        printf("%lld\n",ans);
    }


    return 0;
}

