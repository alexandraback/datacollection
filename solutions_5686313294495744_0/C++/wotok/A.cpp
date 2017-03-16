#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;



/*
typedef long long ll;

int T;
int getAt(int num,int pos) {
    if(pos == 0) return num % 10;
    else if(pos == 1) {
        num /= 10;
        return num % 10;
    }
    else {
        num /= 100;
        return num % 10;
    }
}
char s1[5],s2[5];

bool ck(int num,char s[5],int len) {
    for (int i = 0;i < 3;i ++) {
        if(len - 1 - i >= 0 && s[len - 1 - i] == '?') continue;
        int cur = (len - 1 - i >= 0? s[len - 1 - i] - '0' : 0);
        if(getAt(num,i) != cur) {
            return false;
        }
    }
    return true;
}
int getlen(int x) {
    if(x <= 9) return 1;
    else if(x <= 99) return 2;
    else return 3;
}
void print(int x,int num) {
    int curlen = getlen(x);
    for (int i = 0;i < num - curlen;i ++) {
        printf("0");
    }
    printf("%d",x);
}
int main() {
    freopen("in.txt","r",stdin);
    scanf("%d",&T);
    int C = 1;
    while(T --) {
        scanf("%s%s",s1,s2);
        int len = strlen(s1);
        int ans1 = 0;
        int ans2 = 0x3f3f3f3f;
        for (int i = 0;i <= 999;i ++) {
            for (int j = 0;j <= 999;j ++) {
                if(i == 19 && j == 20) {
                    int z = 1;
                }
                if(ck(i,s1,len) && ck(j,s2,len)) {
                    if(abs(i - j) < abs(ans1 - ans2) || abs(i - j) == abs(ans1 - ans2) && i < ans1 ||
                       abs(i - j) == abs(ans1 - ans2) && i == ans1 && j < ans2) {
                            ans1 = i;
                            ans2 = j;
                       }
                }
            }
        }
        printf("Case #%d: ",C++);
        print(ans1,len);
        printf(" ");
        print(ans2,len);
        puts("");
    }
}

*/
/*
int T;
char s1[25],s2[25];
ll w[25];
int main() {
    freopen("in.txt","r",stdin);
    scanf("%d",&T);
    int C = 1;
    while(T --) {
        scanf("%s%s",s1,s2);
        ll sum1 = 0;
        ll sum2 = 0;
        int len = strlen(s1);
        for (int i = 0;i < len;i ++) {
            if(s1[i] != '?') {
                sum1 = sum1 * 10 + (s1[i] - '0');
            }
            else {
                sum1 = sum1 * 10;
            }
        }
        w[len - 1] = 1;
        for (int i = len - 2;i >= 0;i --) {
            w[i] = w[i + 1] * 10;
        }

        for (int i = 0;i < len;i ++) {
            if(s2[i] != '?') {
                sum2 = sum2 * 10 + (s2[i] - '0');
            }
            else {
                sum2 = sum2 * 10;
            }
        }
        bool sp = false;
        if(sum1 > sum2) {
            swap(sum1,sum2);
            swap(s1,s2);
            sp = true;
        }

        ll need = sum2 - sum1;
        for (int i = 0;i < len;i ++) {
            if(s1[i] == '?') {
                int num = min(9LL,need / w[i]);
                need -= min(9LL,need / w[i]) * w[i];
                s1[i] = num + '0';
            }
        }
        for (int  i = 0;i < len;i ++) {
            if(s2[i] == '?') s2[i] = '0';
        }
       // sum1 = sum2 - need;
        if(sp) swap(s1,s2);
        printf("Case #%d: %s %s\n",C++,s1,s2);
    }
}

*/















int T;
map<string,int> mp;
int c1[25],c2[25];
int cur1[25],cur2[25];
int len;
string pre[ 25],post[25];
int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin >> T;
    int C = 1;
    while(T --) {
        int n;
        mp.clear();
        len = 0;
        scanf("%d",&n);
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));

        for (int i = 0;i < n;i ++) {
            cin >> pre[i] >> post[i];
            if(mp.find(pre[i]) == mp.end()) {
                mp[pre[i]] = ++ len;
            }
            if(mp.find(post[i]) == mp.end()) {
                mp[post[i]] = ++ len;
            }
            c1[mp[pre[i]]] ++;
            c2[mp[post[i]]] ++;
        }
        int ans = 0;
        for (int i = 0;i < (1 << n);i ++) {
            memset(cur1,0,sizeof(cur1));
            memset(cur2,0,sizeof(cur2));
            int ones = 0;
            for (int j = 0;j < n;j ++) {
                if(i >> j & 1) {
                    cur1[mp[pre[j]]] ++;
                    cur2[mp[post[j]]] ++;
                    ones ++;
                }
            }

            bool ok = true;
            for (int i = 1;i <= len;i ++) {
                if(c1[i] >= 1 && cur1[i] == 0 || c2[i] >= 1 && cur2[i] == 0) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                ans = max(ans,n - ones);
            }
        }
        printf("Case #%d: %d\n",C ++,ans);
    }
}















