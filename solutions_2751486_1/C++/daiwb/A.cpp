#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long LL;

string str;
int len, n, first;
int mat[1000005];
vector<pair<int, int> > mm;

bool check(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

LL doit(int pt) {
    int mark = -1;
    FOR(j,pt,mm.size()-1) {
        int tmp = ((first + j) % 2);
        if (tmp == 0) continue;
        if (mm[j].second - mm[j].first + 1 >= n) {
            mark = j;
            break;
        }
    }
    if (mark != -1) {
        int end = mm[mark].first + n - 1;
        return len - end;
    }
    return 0;
}

void run() {
    cin >> str >> n;
    len = str.length();
    REP(i,len) {
        if (check(str[i])) mat[i] = 0;
        else mat[i] = 1;
    }

    mm.clear();
    int cur = -1, cnt = 0, idx = -1;
    REP(i,len) {
        if (mat[i] != cur) {
            if (cnt != 0) {
                mm.push_back(make_pair(idx, i - 1));
            }
            cur = mat[i];
            cnt = 1;
            idx = i;
        } else {
            ++cnt;
        }
    }
    mm.push_back(make_pair(idx, len - 1));
    
    REP(i,mm.size()) {
        int cc = mm[i].second - mm[i].first + 1;
        if (cc < n) {
            FOR(j,mm[i].first,mm[i].second) mat[j] = 0;
        }
    }
    
    mm.clear();
    cur = -1, cnt = 0, idx = -1;
    REP(i,len) {
        if (mat[i] != cur) {
            if (cnt != 0) {
                mm.push_back(make_pair(idx, i - 1));
            }
            cur = mat[i];
            cnt = 1;
            idx = i;
        } else {
            ++cnt;
        }
    }
    mm.push_back(make_pair(idx, len - 1));
    
    LL res = 0;
    first = mat[0];
    REP(i,mm.size()) {
        int now = ((first + i) % 2);
        if (now == 0) {
            LL t1 = mm[i].second - mm[i].first + 1;
            LL t2 = doit(i + 1);
            res += t1 * t2;
        } else {
            LL tot = mm[i].second - mm[i].first + 1;
            LL a1 = len - (mm[i].first + n - 1);
            LL num = tot + 1 - n;
            LL a2 = a1 - (num - 1);
            LL t1 = (a1 + a2) * num / 2;
            LL t2 = (n - 1) * doit(i + 1);
            res += t1 + t2;
        }
    }
    cout << res << endl;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
