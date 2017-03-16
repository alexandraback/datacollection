//#define ONLINE_JUDGE
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <iomanip>
#include <list>
#include <stack>
#include <queue>
#include <bitset>
#include <numeric>
#include <functional>

#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define rep(i, n)       for(int i = 0; i < n; i++)
#define reps(i, a, n)   for(int i = a; i < n; i++)
#define foreach(it, v)  for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define precout(a,b)    cout << fixed << setprecision((b)) << (a)
#define endl 			'\n'
#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define all(a)          a.begin(), a.end()
#define rall(a)			a.rbegin(), a.rend()
#define sz(x)			(int)x.size()
#define fastIO   		ios::sync_with_stdio(false); cin.tie(0);
string toString(long long n) { stringstream ss; ss << n; return ss.str(); }
long long toNumber(string s){ stringstream ss; long long n; ss << s; ss >> n; return n; }

int n;
vector <string> gs, gt;
void solve(string s) {
    bool chk = true;
    rep(i, n){
        chk &= (s[i] != '?');
    }
     if (chk){
        gs.pb(s);
         return;
    }
    
    for (int i = 0; i < n; i++) {
        for (char num = '0'; num <= '9'; num++) {
            if (s[i] == '?') {
                s[i] = num;
                solve(s);
                s[i] = '?';
            }
           
        }
    }
    
}

void solve1(string s) {
    bool chk = true;
    rep(i, n){
        chk &= (s[i] != '?');
    }
    if (chk){
        gt.pb(s);
        return;
    }
    
    for (int i = 0; i < n; i++) {
        for (char num = '0'; num <= '9'; num++) {
            if (s[i] == '?') {
                s[i] = num;
                solve1(s);
                 s[i] = '?';
            }
        }
    }
    
}

int main() {
#ifndef ONLINE_JUDGE
    const clock_t begin_time = clock();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    fastIO
   int t;
    cin >> t;
    for (int T = 1; T <= t; T++) {
        cout << "Case #" << T << ": ";
        string s, t;
        cin >> s >> t;
        //cout << s << " " << t << endl;
        if (s == t && s == "???") {
            cout << "000 000" << endl;
            continue;
        }
        n = sz(s);
        gs.clear();
        gt.clear();
        solve(s);
        solve1(t);
        pair<string, string> ans;
        int minD = 1e6;
        for (int i = 0; i < sz(gs); i++) {
            for (int j = 0; j < sz(gt); j++) {
                int a = toNumber(gs[i]);
                int b = toNumber(gt[j]);
                if (abs(a - b) < minD) {
                    minD = abs(a - b);
                    ans = {gs[i], gt[j]};
                } else if (abs(a - b) == minD) {
                    if (ans.ff > gs[i]) {
                        ans = {gs[i], gt[j]};
                    } else if (ans.ff == gs[i] && ans.ss > gt[j]) {
                        ans = {gs[i], gt[j]};
                    }
                }
                
            }
        }
        
        cout << ans.ff << " " << ans.ss << endl;
        
        
    }
         
    
#ifndef ONLINE_JUDGE
   	cout << endl;
    cout << "Time : ";
    cout << float( clock () - begin_time ) / CLOCKS_PER_SEC << endl;
#endif
    
    return 0;
}
