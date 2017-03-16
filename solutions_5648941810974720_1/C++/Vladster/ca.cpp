#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#define fi(i,a,b) for(int i=(a);i<(b); ++i)
#define fd(i,a,b) for(int i=(a);i>(b); --i)
#define fie(i,a,b) for(int i=(a);i<=(b); ++i)
#define fde(i,a,b) for(int i=(a);i>=(b); --i)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define rall(s) (s).rbegin(),(s).rend()
#define C(u) memset((u),0,sizeof((u)))
#define x first
#define y second
#define inf 1000000000
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi > vvi;
typedef pair<int, int> pii;

#define INP_FILE "A-large.in"
#define OUT_FILE "output.txt"

int cnt[26];
int ans[10];
int id(char c) { return c - 'A'; }
void check(int index, char c, string s) {
    int n = cnt[id(c)];
    fi(i, 0, s.size()) cnt[id(s[i])] -= n;
    ans[index] = n;
}
string solve(string &s) {
    fi(i, 0, 26) cnt[i] = 0;
    fi(i, 0, s.size()) cnt[id(s[i])]++;
    check(0, 'Z', "ZERO");
    check(2, 'W', "TWO");
    check(4, 'U', "FOUR");
    check(6, 'X', "SIX");
    check(8, 'G', "EIGHT");

    check(3, 'T', "THREE");
    check(7, 'S', "SEVEN");
    check(5, 'F', "FIVE");
    check(1, 'O', "ONE");
    check(9, 'I', "NINE");
    vector<char>r;
    fi(i, 0, 10) {
        fi(j, 0, ans[i]) r.push_back('0'+i);
    }
    string res(all(r));
    return res;
}


int main()
{
    freopen(INP_FILE, "r", stdin);
    freopen(OUT_FILE, "w", stdout);
    int tstCnt; cin >> tstCnt;
    for (int tst = 1; tst <= tstCnt; tst++)
    {
        string s; cin >> s;
        string t = solve(s);
        printf("Case #%d: %s\n",tst, t.c_str());
    }

    return 0;
}