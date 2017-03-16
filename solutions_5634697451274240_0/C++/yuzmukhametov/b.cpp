#define print(x) cerr << #x << " = " << toStr(x) << endl;
// -Wl,--stack,9001 
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)((x).size()))
#define rep(i, N) for (int i = 0; i < N; ++i)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
typedef long long lint;
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;
template<class T> string toStr(T x){stringstream ss;ss<< x; return ss.str(); } 
template<class T1,class T2>string toStr(pair<T1,T2>x){return toStr(x.first)+": "+toStr(x.second);}
template<class T> string containerToStr(T v) { string r = "["; foreach (it, v) { if (r != "[") r += ", "; r += toStr(*it); } return r + "]";}
template<class T> string toStr(vector<T>v){return containerToStr(v);} 
template<class T> string toStr(set<T> v) {return containerToStr(v);} 
template<class T1,class T2>string toStr(map<T1,T2>v){return containerToStr(v);}



void solve(int num) {
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 1; i < sz(s); ++i) {
        if (s[i] != s[i - 1]) {
            ++ans;
        }
    }
    if (s[sz(s) - 1] == '-') {
        ++ans;
    }
    printf("Case #%d: %d\n", num, ans);
}

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        solve(i);
    }

    return 0;
}
