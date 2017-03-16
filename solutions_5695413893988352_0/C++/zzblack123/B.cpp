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
const int inf = 0x3f3f3f3f ;
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
int ans;

int get(string s) {
    int res = 0;
    for (int i = 0; s[i]; i++) res = res * 10 + s[i] - '0';
    return res;
}

void dfs(int id) {
    if (id == 2 * s.size()) {
        int a = get(s), b = get(t);
//        cout << a << " " << b << " \n";
        if (abs(a-b) < ans) {
            ans = abs(a-b);
            anss = s;
            anst = t;
        }
        return ;
    }

    if (id < s.size() && s[id] == '?') {
        s[id] = '0';
        for (int i = 0; i < 10; i++) {
            dfs(id + 1);
            s[id]++;
        }
        s[id] = '?';
    } else if (id >= s.size() && t[id-s.size()] == '?') {
        id -= s.size();
        t[id] = '0';
        for (int i = 0; i < 10; i++) {
            dfs(id + 1);
            t[id]++;
        }
        t[id] = '?';
    } else dfs(id+1);

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
        dfs(0);

//        cout << "     " << s << " " << t << "\n";
//        ll dif = 0;
//        for (int i = s.size(); ~i; i--) {
//            dif *= 10;
//            if (s[i] != '?' && t[i] != '?') dif += s[i] - t[i];
//            else if (s[i] != '?') {
//                if(dif < 0) t[i] = '0';
//                else if (dif > 0) t[i] = '9';
//                else t[i] = s[i];
//                dif += s[i] - t[i];
//            } else if (t[i] != '?') {
//                if (dif > 0) s[i] = '0';
//                else if (dif < 0) s[i] = '9';
//                else s[i] = t[i];
//                dif += s[i] - t[i];
//            } else {
//                if (dif > 0) s[i] = '0', t[i] = '9';
//                else if (dif < 0) t[i] = '0', s[i] = '9';
//                else {
//                    if (abs(s[i + 1] - t[i + 1]) > 5) {
//                        if (s[i+1] < t[i+1]) s[i] = '1', t[i] = '0';
//                        else s[i] = '0', t[i] = '1';
//                    } else s[i] = t[i] = '0';
//                }
//                dif += s[i] - t[i];
//            }
//        }
        printf("Case #%d: ", cas++);
        cout << anss << " " << anst << "\n";
    }


	return 0;
}
