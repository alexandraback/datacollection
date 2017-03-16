/***************************************
      zzblack                         **
      2016-04-30                      **
      Orz                             **
****************************************/
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define ls id<<1,l,mid
#define rs id<<1|1,mid+1,r
#define OFF(x) memset(x,-1,sizeof x)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(x) memset(x,0x3f,sizeof x)
typedef long long ll ;
typedef pair<int,int> pii ;
const int maxn = 1e5 + 50 ;
const int maxm = 1e6 + 50;
const double eps = 1e-10;
const int max_index = 62;
const ll inf = 0x7f7f7f7f7f7f7f7f;
const int MOD = 1e9+7 ;

inline int read(){
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    int x = 0;
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

string s, t;
string anss, anst;
ll ans;

ll get(string s) {
    ll res = 0;
    for (int i = 0; s[i]; i++) res = res * 10 + s[i] - '0';
    return res;
}

void dfs(int id, ll dif) {
    if (id == s.size()) {
        ll a = get(s), b = get(t);
        ll tmp = abs(a-b);
        if(tmp < ans) {
            ans = tmp;
            anss = s;
            anst = t;
        }
        return ;
    }
    dif *= 10;
    if (s[id] != '?' && t[id] != '?') {
        dfs(id+1, dif + s[id] - t[id]);
    } else if (s[id] != '?') {
        if (dif > 0) {
            t[id] = '9';
            dfs(id+1, dif + s[id] - t[id]);
        }
        else if (dif < 0) {
            t[id] = '0';
            dfs(id+1, dif + s[id] - t[id]);
        }
        else {
            for (int d = -1; d <= 1; d++) {
                char c = s[id] + d;
                if (isdigit(c)) {
                    t[id] = c;
                    dfs(id+1, d);
                    t[id] = '?';
                }
            }
        }
    }else if (t[id] != '?') {
        if (dif > 0) {
            s[id] = '0';
            dfs(id+1, dif + s[id] - t[id]);
        }
        else if (dif < 0) {
            s[id] = '9';
            dfs(id+1, dif + s[id] - t[id]);
        }
        else {
            for (int d = -1; d <= 1; d++) {
                char c = t[id] + d;
                if (isdigit(c)) {
                    s[id] = c;
                    dfs(id+1, d);
                    s[id] = '?';
                }
            }
        }
    } else {
        if (dif > 0) {
            s[id] = '0';
            t[id]  ='9';
            dfs(id+1, dif + s[id] - t[id]);
        } else if (dif < 0){
            t[id] = '0';
            s[id] = '9';
            dfs(id+1, dif + s[id] - t[id]);
        } else {
            s[id] = '0', t[id] = '1';
            dfs(id+1, dif + s[id] - t[id]);
            s[id] = '0', t[id] = '0';
            dfs(id+1, dif + s[id] - t[id]);
            s[id] = '1', t[id] = '0';
            dfs(id+1, dif + s[id] - t[id]);
        }
    }

}

int main () {
#ifdef LOCAL
	freopen("C:\\Users\\zzblack\\Desktop\\case.in","r",stdin);
      freopen("C:\\Users\\zzblack\\Desktop\\case.out","w",stdout);
#endif
    int T = read(), cas = 1;
    while (T--) {
        cin >> s >> t;
        ans = inf;

        dfs(0, 0);


        printf("Case #%d: ", cas++);
        cout << anss << " " << anst << "\n";
    }


	return 0;
}
