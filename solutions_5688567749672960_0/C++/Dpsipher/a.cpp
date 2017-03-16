/**
 * author : dpsipher
 */
#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>
#include <cassert>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fill(x,y) memset(x,y,sizeof(x))
#define FOREACH(it,v)   for(typeof((v).begin()) it=(v).begin();it != (v).end();it++)
#define i(x) scanf("%d",&x)
#define u(x) scanf("%u",&x)
#define l(x) scanf("%l64d",&x)
#define ul(x) scanf("%l64u",&x)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;                         
typedef vector<int> vi;

typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<vi> vvi;

using namespace std;

ll solve(ll n) {
    if (n <= 9) return n;
    ll res = 0;
    if (n%10 == 0) return solve(n-1) + 1;
    string str = "";
    
    while(n) {
        str += n%10 + '0';
        n/=10;
    }
    string str2 = "";
    for(int i = 0;i < sz(str); i++) {
        str2 += str[sz(str)-i-1];
    }
    str = str2;
    ll v = 0;
    for (int i = ((sz(str))/2); i < sz(str); i++) {
        v += str[i] - '0';
        v*=10;
    }
    res = (v/10-1);
    v = 0;
    for (int i = (sz(str)/2)-1;i >= 0; i--) {
        v += str[i] - '0';
        v*=10;
    }
    res += (v/10-1);
    if (v/10 > 1) res++;
    res+=2;
    n = pow(10, sz(str)-1) - 1;
    return res + solve(n);
}
int main()
{
    int tests;
    i(tests);
    ll n;
    rep(testno, tests) {
        printf("Case #%d: ", testno+1);
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}

