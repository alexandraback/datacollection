//Coder: Balajiganapathi

#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;

// Basic macros

#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define fr(i,n)     re(i,0,n)
#define tr(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())

const int oo = 2000000009;

int n, m, k;
int p[10], num[10];
vector<string> pos;
map<int, int> match;
void check(int product, int idx) {
    if(idx == n) {
        if(match[product]) match[product] = 0;
        return;
    }
    check(product, idx + 1);
    check(product * num[idx], idx + 1);
}

void trySolve(int idx) {
    if(idx == n) {
        match.clear();
        fr(i, k) match[p[i]] = 1;
        check(1, 0);
        fr(i, k) if(match[p[i]]) return;
        string str;
        fr(i, n) str += '0' + num[i];
        pos.pu(str);     
        return;
    }
    for(int d = 2; d <= m; ++d) {
        num[idx] = d;
        trySolve(idx + 1);
    }
}

int main() {
    //freopen("sample.txt", "r", stdin); freopen("output.txt", "w", stdout);
    freopen("C-small-1-attempt0.in", "r", stdin); freopen("small0.txt", "w", stdout);
    //freopen("C-large.in", "r", stdin); freopen("large.txt", "w", stdout);

    int _T;
    scanf("%d", &_T);
    for(int _t = 1; _t <= _T; ++_t) {
        int r;
        scanf("%d %d %d %d", &r, &n, &m, &k);        
        printf("Case #%d:\n", _t);
        
        while(r--) {
            cerr << r << endl;
            pos.clear();
            fr(i, k) scanf("%d", p+i);
            trySolve(0);
            cout << pos[0] << endl;
        }
    }

	return 0;
}
