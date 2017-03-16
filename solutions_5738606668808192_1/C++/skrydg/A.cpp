#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <list>
#include <iterator>
#include <functional>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <ctime>
#include <cassert>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef pair<short, short> pss;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pset set <int>*
#define vi vector <int>
#define vll vector <ll>
#define sz(a) ((int)(a.size()))
//#define clear(a) memset((a), 0, sizeof (a))


vector <int> prime;
map <string, vector <int> > is;

string gen(int n){
    string ans;
    for (int i = 0; i < n; i++){
        if (rand() & 1){
            ans += "1";
        } else {
            ans += "0";
        }
    }
    return ans;
}

int check(string &s, ll base){
    for (int i = 0; i < sz(prime); i++){
        ll rem = 0;
        for (int j = 0; j < sz(s); j++){
            rem *= base;
            rem %= prime[i];
            if (s[j] == '1'){
                rem++;
            }
        }
        if (rem % prime[i] == 0){
            return prime[i];
        }
    }
    return -1;
}

void solve(int n){
    while (1){
        string cur = gen(n - 2);
        cur = "1" + cur + "1";
        assert(sz(cur) == n);
        if (is.find(cur) != is.end()){
            continue;
        }
        
        vector <int> ans;
        bool ok = 1;
        for (int i = 2; i <= 10; i++){
            int buf = check(cur, i);
            if (buf == -1){
                ok = 0;
                break;
            }
            ans.pb(buf);
        }
        if (ok){
            is[cur] = ans;
            break;
        }
    }
}

bool is_prime(int x){
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0){
            return 0;
        }
    }
    return 1;
}

int main() {
#ifdef HOME
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand((int)time(NULL));
    for (int i = 2; i < 100 * 100; i++){
        if (is_prime(i)){
            prime.pb(i);
        }
    }
    //cout << sz(prime) << endl;
    int t;
    cin >> t;
    assert(t == 1);
    for (int i = 0; i < t; i++){
        cout << "Case #" << i + 1 << ":\n";
        int n, cnt;
        cin >> n >> cnt;
        for (int j = 0; j < cnt; j++){
            solve(n);
        }
        
        for (auto it: is){
            cout << it.fi << " ";
            for (auto it2: it.se){
                cout << it2 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
