#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define MP(x, y) make_pair((x),(y))
#define FI first
#define SE second
#define LOWB(x) (x & (-x))
#define UNIQUE(a) sort(ALL(a)), (a).erase(unique(ALL(a)), (a).end())
#define HEIGHT(n) (sizeof(int) * 8 - __builtin_clz(n)) //height of range n segment tree
typedef long long llong;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T> inline T min(T a, T b, T c) {return min(min(a,b),c);}
template<class T> inline T min(T a, T b, T c, T d) {return min(min(a,b),min(c,d));}
template<class T> inline T max(T a, T b, T c) {return max(max(a,b),c);}
template<class T> inline T max(T a, T b, T c, T d) {return max(max(a,b),max(c,d));}
const int INF = 1e9;
const llong INF_LL = 4e18;
const double pi = acos(-1.0);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
string s[] = {
    "ZERO", //
    "ONE", //
    "TWO", //
    "THREE", //
    "FOUR", //
    "FIVE",
    "SIX", //
    "SEVEN", //
    "EIGHT", //
    "NINE"};
int cnt[26];

bool find(int num) {
    int tmp[26];
    memset(tmp, 0, sizeof(tmp));
    for (int i=0; i<(int)s[num].length(); i++) tmp[s[num][i] -'A']++;
    for (int i=0; i<(int)s[num].length(); i++) {
        if (cnt[s[num][i]-'A'] < tmp[s[num][i]-'A']) return false;
    }
    return true;
}

void print_cnt() {
    printf("-------\n");
    for (int i=0; i<26; i++) if (cnt[i]) printf("cnt['%c']:%d\n",i + 'A', cnt[i]);
    printf("-------\n");
}

void del_cnt(int num) {
    for (int i=0; i<s[num].length(); i++) {
        cnt[s[num][i]-'A']--;
    }
}

void process(int num, string& res) {
    while (find(num)) { del_cnt(num); res += '0' + num; }
}

string decode(string in) {
    int tot;
    memset(cnt, 0, sizeof(cnt));
    for (int i=0; i<(int)in.length(); i++) {
        cnt[in[i] - 'A']++;
    }
    tot = (int)in.length();
    string res = "";
    int cur = 0;
    process(0, res);
    process(2, res);
    process(6, res);
    process(8, res);
    process(3, res);
    process(7, res);
    process(4, res);
    process(1, res);
    process(5, res);
    process(9, res);

    sort(res.begin(), res.end());
    return res;
}

string encode(string nums) {
    string res = "";
    for (int i=0; i<nums.length(); i++) res += s[nums[i]-'0'];
    sort(res.begin(), res.end());
    return res;
}

int main() {
    //freopen("1.in", "r", stdin);
    int cas;
    cin >> cas;
    for (int t=1; t<=cas; t++) {
        string in;
        cin >> in;
        sort(in.begin(), in.end());
        string ans = decode(in);
        string _s = encode(ans);
        assert(_s == in);
        if (_s != in) {
            printf("find case:%d\n", t);
        }
        printf("Case #%d: %s\n", t, ans.c_str());
    }
    return 0;
}
