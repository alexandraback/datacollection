//#pragma comment(linker,"/STACK:102400000,102400000")
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
 
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r

typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;
typedef unsigned long long ULL;

inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; ch < '0' || ch > '9'; ch = getchar())    if (ch == '-')  positive = 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar())    x = x * 10 + ch - '0';
    return positive ? x : -x;
}

inline char RC (){
    char c = getchar ();
    while (c == ' '||c == '\n')     c = getchar ();
    return c;
}

inline LL gcd(LL a, LL b) {return b?gcd(b, a%b):a;}

inline LL lcm(LL a, LL b) {return a * b / gcd(a, b);}

inline LL Sub(LL x, LL y, LL mod){
    LL res = x - y;
    while(res < 0) res += mod; 
    return res;
}

inline LL Add(LL x, LL y, LL mod){
    LL res = x + y;
    while(res >= mod)  res -= mod;
    return res;
}

inline LL POW_MOD(LL x, LL y, LL mod){
    LL ret = 1;
    while(y > 0){
        if(y & 1)  ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}

/****************************define***************************************/

const int N = 1005 + 100;
const int M = 400000 + 100;
const LL INF = 9e18;
const int inf = 0x7fffffff;
const LL MOD = 1000000007;
const double PI = acos(-1.0);
const double G = 9.8;
const double eps = 1e-3;

string s, ss;
int l, x;

vector<string> v;

string mul(string a, string b){
    if(a == "1"){
        if(b == "1") return "1";
        if(b == "i") return "i";
        if(b == "j") return "j";
        if(b == "k") return "k";
    }
    else if(a == "i"){
        if(b == "1") return "i";
        if(b == "i") return "-1";
        if(b == "j") return "k";
        if(b == "k") return "-j";
    }
    else if(a == "j"){
        if(b == "1") return "j";
        if(b == "i") return "-k";
        if(b == "j") return "-1";
        if(b == "k") return "i";
    }
    else{
        if(b == "1") return "k";
        if(b == "i") return "j";
        if(b == "j") return "-i";
        if(b == "k") return "-1";
    }
}

string div(string a, string b){
    if(a == "1"){
        if(b == "1") return "1";
        if(b == "i") return "-i";
        if(b == "j") return "-j";
        if(b == "k") return "-k";
    }
    if(a == "i"){
        if(b == "1") return "i";
        if(b == "i") return "1";
        if(b == "j") return "k";
        if(b == "k") return "-j";
    }
    if(a == "j"){
        if(b == "1") return "j";
        if(b == "i") return "-k";
        if(b == "j") return "1";
        if(b == "k") return "i";
    }
    if(a == "k"){
        if(b == "1") return "k";
        if(b == "i") return "j";
        if(b == "j") return "-i";
        if(b == "k") return "1";
    }
}

string cal_div(string x, string y){
    bool flag = true;
    string a, b; a.clear(), b.clear();
    if(x[0] == '-'){
        a += x.substr(1);
        flag ^= true;
    }else a += x;
    if(y[0] == '-'){
        b += y.substr(1);
        flag ^= true;
    }else b += y;
    string res; res.clear(); res += div(a, b);
    if(res[0] == '-'){
        flag ^= true;
        if(flag) return res.substr(1);
        return res;
    }else{
        if(flag) return res;
        return "-" + res;
    }
}

void solve(){
    v.clear();
    string now = "1";
    for(int i = 0; i < ss.size(); ++ i){
        bool flag = true;
        string a, b; a.clear(), b.clear();
        if(now[0] == '-') {flag ^= true; a += now.substr(1);}
        else              a += now;
        b += ss[i];
        string tmp; tmp.clear(); tmp += mul(a, b);
        now.clear();
        if(tmp[0] == '-'){
            flag ^= true;
            if(flag) now += tmp.substr(1);
            else     now += tmp;
        }else{
            if(flag) now += tmp;
            else     now += "-" + tmp;
        }
        v.PB(now);
    }
    // cout << ss << endl;
    // for(int i = 0; i < ss.size(); ++ i){
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    bool ok = false;
    for(int i = 1; i < ss.size() && !ok; ++ i){
        string ans1 = v[i];
        string tmp = cal_div(ans1, "i");
        string ans3 = cal_div(v[ss.size() - 1], v[i]);
        if(ans3 == "k" && tmp == "j"){
            // cout << i << "je" << endl;
            ok = true;
        }
    }
    if(ok) cout << "YES" << endl;
    else   cout << "NO" << endl;
}

int main(){
    freopen("/Users/w/Desktop/in.txt", "r", stdin);
    freopen("/Users/w/Desktop/out.txt", "w", stdout);
    int Cas = 1;
    int T;
    cin >> T;
    while(T --){
        s.clear(), ss.clear();
        cin >> l >> x >> s;
        for(int i = 0; i < x; ++ i) ss += s;
        printf("Case #%d: ", Cas++);
        solve();
    }
    return 0;
}