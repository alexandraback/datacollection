/**
* Change is impossible in this fog of ignorance.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cmath>
using namespace std;

#define trace(x) {cerr << #x << "=" << x <<endl;}
#define trace2(x, y) {cerr << #x << "=" << x << " " << #y << "=" << y <<endl;}
#define track(x) {cerr << #x << ":" << endl; for (int q = 0; q < x.size(); q++) {cerr << x[q] << " ";} cerr << endl;}
#define trackarr(x, n) {cerr << #x << ":" << endl; for (int q = 0; q < n; q++) {cerr << x[q] << " ";} cerr << endl;}
#define trackvv(x) {cerr << #x << ":" << endl; for (int i = 0; i < x.size(); i++) { cerr << "i:" << i << endl; for (int j = 0; j < x[i].size(); j++){cerr << x[i][j] << " ";} cerr << endl;} cerr << endl;}
#define trackcr(x) {cerr << #x << ":" << endl; for (auto i = x.begin(); i != x.end(); i++) {cerr << *i << " ";} cerr << endl;}
template <typename Tk, typename Tv> ostream& operator<<(ostream& os, const pair<Tk, Tv> &p){os << "{" << p.first << ',' << p.second << "}";return os;}

typedef long long ll;

const int MAX = 100005;
const int MOD = 1000000000+7;
const int INF = 1000000000;

enum COMP {
    EQUAL,
    LESS,
    GREATER
};

int compare(int a, int b) {
    if (a == b) return EQUAL;
    if (a < b) return LESS;
    else return GREATER;
}

long long toVal(const char *x){
    long long sum = 0;
    for (int i = 0; x[i]; i++) {
        sum *= 10;
        sum += (x[i]-'0');
    }
    return sum;
}


string toString(int val, int n) {
    string s;
    for (int i = 0; i < n; i++) {
        s.push_back(val % 10 + '0');
        val /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}


int n;
int minDif = INF;
int Answer[2];

void solve(int i, char *a, char *b, int comp) {
    if (i==n) {
        ll av = toVal(a), bv = toVal(b);
        ll dif = abs(av-bv);
        if (dif < minDif) {
            minDif = dif;
            Answer[0] = av; Answer[1] = bv;
        } else if (dif == minDif) {
            if (av < Answer[0]) {
                Answer[0] = av; Answer[1] = bv;
            } else if (av == Answer[0]) {
                Answer[1] = bv;
            }
        }
        return;
    } else {
        if (comp == EQUAL) {
            if (a[i]=='?' && b[i]=='?') {
                a[i]=b[i]='0';
                solve(i+1, a, b, EQUAL);
                a[i]=b[i]='?';
            } else if (a[i]=='?') {
                int minx = max(0, (b[i]-'0')-1);
                int maxx = min(9, (b[i]-'0')+1);
                for (int j = minx; j <= maxx; j++) {
                    a[i]=j+'0';
                    solve(i+1, a, b, compare(a[i], b[i]));
                    a[i]='?';
                }
            } else if (b[i]=='?') {
                int minx = max(0, (a[i]-'0')-1);
                int maxx = min(9, (a[i]-'0')+1);
                for (int j = minx; j <= maxx; j++) {
                    b[i]=j+'0';
                    solve(i+1, a, b, compare(a[i], b[i]));
                    b[i]='?';
                }
            } else {
                solve(i+1, a, b, compare(a[i], b[i]));
            }
        } else if (comp == LESS){
            bool aq=false, bq=false;
            if (a[i]=='?') {a[i] = '9'; aq=true;}
            if (b[i]=='?') {b[i] = '0'; bq=true;}
            solve(i+1, a, b, comp);
            if (aq) a[i]='?';
            if (bq) b[i]='?';
        } else if (comp == GREATER) {
            bool aq=false, bq=false;
            if (a[i]=='?') {a[i] = '0'; aq=true;}
            if (b[i]=='?') {b[i] = '9'; bq=true;}
            solve(i+1, a, b, comp);
            if (aq) a[i]='?';
            if (bq) b[i]='?';
        }
    }
}

void init() {
    minDif = INF;
    Answer[0]=Answer[1]=-1;
}


void doTask() {
    init();
    char a[25], b[25];
    scanf("%s%s", a, b);
    n = strlen(a);
    solve(0, a, b, EQUAL);
    char temp[25];
    cout << toString(Answer[0], n) << " " << toString(Answer[1], n) << endl;;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        cerr << t << endl;
        printf("Case #%d: ", t);
        doTask();
    }
}
