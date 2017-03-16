// vudduu - Codejam 2016 Round 1B
// Problem B
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define MP          make_pair
#define S           size()
typedef long long   LL;

int cmp(string a, string b) {
    F(i, a.S) {
        if(a[i] == '?' || b[i] == '?') {
            return 0;
        }
        if(a[i] < b[i]) return -1; // a minor
        if(a[i] > b[i]) return 1; // a mayor
    }
    return 0;
}

LL getDiff(string x, string y) {
    stringstream sx(x), sy(y);
    LL a, b;
    sx >> a;
    sy >> b;
    return abs(a-b);
}

pair<string, string> createBest(string c, string j) {
    int it = 0;
    vector<pair<string, string> > v;
    while(it < c.S) {
        if(c[it] != '?') break;
        if(j[it] != '?') break;
        c[it] = j[it] = '0';
        it++;
    }
    if(it > 0) {
        c[it-1] = '0'; j[it-1] = '1';
        v.PB(createBest(c, j));
        c[it-1] = '1'; j[it-1] = '0';
        v.PB(createBest(c, j));
        c[it-1] = j[it-1] = '0';
    }
    while(it < c.S) {
        if(c[it] == '?') {
            if(j[it] == '?') {
                switch(cmp(c, j)) {
                    case -1: c[it] = '9'; j[it] = '0'; break;
                    case 1: c[it] = '0'; j[it] = '9'; break;
                    case 0:
                        c[it] = '0'; j[it] = '1';
                        v.PB(createBest(c, j));
                        c[it] = '1'; j[it] = '0';
                        v.PB(createBest(c, j));
                        c[it] = j[it] = '0';
                        break;
                }
            }
            else {
                switch(cmp(c, j)) {
                    case -1: c[it] = '9'; break;
                    case 1: c[it] = '0'; break;
                    case 0:
                        if(j[it] == '9') {
                            c[it] = '8';
                            v.PB(createBest(c, j));
                        }
                        else if(j[it] == '0') {
                            c[it] = '1';
                            v.PB(createBest(c, j));
                        }
                        else {
                            c[it] = j[it]-1;
                            v.PB(createBest(c, j));
                            c[it] = j[it]+1;
                            v.PB(createBest(c, j));
                        }
                        c[it] = j[it];
                        break;
                }
            }
        }
        else {
            if(j[it] == '?') {
                switch(cmp(j, c)) {
                    case -1: j[it] = '9'; break;
                    case 1: j[it] = '0'; break;
                    case 0:
                        if(c[it] == '9') {
                            j[it] = '8';
                            v.PB(createBest(c, j));
                        }
                        else if(c[it] == '0') {
                            j[it] = '1';
                            v.PB(createBest(c, j));
                        }
                        else {
                            j[it] = c[it]-1;
                            v.PB(createBest(c, j));
                            j[it] = c[it]+1;
                            v.PB(createBest(c, j));
                        }
                        j[it] = c[it];
                        break;
                }
            }
        }
        it++;
    }
    pair<string, string> res(c, j);
    LL xx = getDiff(c, j);
    F(i, v.S) {
        LL yy = getDiff(v[i].first, v[i].second);
        if(yy < xx) {
            res = v[i];
            xx = yy;
        }
        if(yy == xx) {
            if(v[i].first < res.first) {
                res = v[i];
            }
            if(v[i].first == res.first)
                if(v[i].second < res.second) {
                    res = v[i];
                }
        }
    }
    return res;
}

void solve() {
    string c, j;
    cin >> c >> j;
    pair<string, string> p0 = createBest(c, j);
    cout << p0.first << " " << p0.second << endl;
}

int main(){
	// freopen("in.txt", "r", stdin);
	//freopen("B-small-attempt2.in", "r", stdin);
	freopen("B-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T ;cas++) {
        printf("Case #%d: ", cas);
        solve();
    }
}
