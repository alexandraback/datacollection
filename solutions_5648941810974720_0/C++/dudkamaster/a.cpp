#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <memory.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define forn(i,n) for (int i=0; i<int(n); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;


const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

string s;

string digit[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void read(){
    cin >> s;
}

void solve(){
    map <char, int> cnt;
    forn(i,sz(s))
        cnt[s[i]]++;
    vector <int> ans;
    while (cnt['Z']) {
        ans.pb(0);
        forn(i,sz(digit[0]))
            cnt[digit[0][i]]--;
    }
    while(cnt['W']) {
        ans.pb(2);
        forn(i,sz(digit[2]))
            cnt[digit[2][i]]--;
    }
    while(cnt['X']) {
        ans.pb(6);
        forn(i,sz(digit[6]))
            cnt[digit[6][i]]--;
    }
    while(cnt['S']) {
        ans.pb(7);
        forn(i,sz(digit[7]))
            cnt[digit[7][i]]--;
    }
    while (cnt['V']) {
        ans.pb(5);
        forn(i,sz(digit[5])) 
            cnt[digit[5][i]]--;
    }
    while (cnt['F']) {
        ans.pb(4);
        forn(i,sz(digit[4]))
            cnt[digit[4][i]]--;
    }
    while (cnt['G']) {
        ans.pb(8);
        forn(i,sz(digit[8]))
            cnt[digit[8][i]]--;
    }
    while (cnt['H']) {
        ans.pb(3);
        forn(i,sz(digit[3]))
            cnt[digit[3][i]]--;
    }
    while (cnt['O']) {
        ans.pb(1);
        forn(i,sz(digit[1])) 
            cnt[digit[1][i]]--;
    }
    forn(i,cnt['I'])
        ans.pb(9);
    sort(all(ans));
    forn(i,sz(ans))
        printf("%d", ans[i]);
    puts("");

}

int main(){
#ifdef dudkamaster
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int t;
    scanf("%d", &t);
    forn(i,t) {
        printf("Case #%d: ", i+1);
        read();
        solve();
    }
    return 0;
}
