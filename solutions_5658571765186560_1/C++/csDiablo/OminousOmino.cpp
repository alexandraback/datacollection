#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

#define f(i,beg,end) for(int i=beg; i<=end; i++)
#define F(i,beg,end) for(int i=beg; i>=end; i--)

#define input(file) freopen(file,"r",stdin)
#define output(file) freopen(file,"w",stdout)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll mod = 1000000000 + 7;

int r, c, x;

void precompute();
void init();
void solve(int);

int main() {
//    input("test.txt");
    input("OminousOminoBig.in");
    output("OminousOminoBig.out");
    precompute();

    int tests = 1; cin >> tests;
    f(i,1,tests) {
        init();
        solve(i);
    }

    return 0;
}
void init() {
    cin >> x >> r >> c;
}

bool are(int a, int b) {
    return (r==a && c==b) || (r==b && c==a);
}

int getIndex() {
    if ((r*c)%x != 0 || max(r,c)<x) {
        return 0;
    }
    if (x==1) {
        return 1;
    }
    if (x==2) {
        return 1;
    }
    if (x==3) {
        if (are(3,1)) {
            return 0;
        }
        else {
            return 1;
        }
    }
    if (x==4) {
        if (are(4,1) || are(4,2)) {
            return 0;
        }
        else {
            return 1;
        }
    }
    if (x==5) {
        if (are(5,1) || are(5,2) || are(5,3)) {
            return 0;
        }
        else {
            return 1;
        }
    }
    if (x==6) {
        if (are(6,1) || are(6,2) || are(6,3)) {
            return 0;
        }
        else {
            return 1;
        }
    }
    if (x>=7) {
        return 0;
    }
}

void solve(int testNumber) {
    string ans[2] = {"RICHARD", "GABRIEL"};
    int ind = getIndex();
    printf("Case #%d: %s\n", testNumber, ans[ind].c_str());
}

void precompute() {

}
