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

void precompute();
void init();
void solve(int);

string in;
int n;

int main() {
    input("StandingOvation.in");
    output("StandingOvation.out");
    precompute();

    int tests = 1; cin >> tests;
    f(i,1,tests) {
        init();
        solve(i);
    }

    return 0;
}
void init() {
    cin >> n;
    cin.ignore();
    cin >> in;
}

bool ok(int added) {
    int currentPeople = added;
    f(i,0,n) {
        if (currentPeople >= i) {
            currentPeople += (in[i]-'0');
        }
        else {
            return false;
        }
    }

    return true;
}

void solve(int testNumber) {
    int ans = 10000000, l=0, r=1000000, mid;

    while (l<=r) {
        mid = (r+l)/2;
        if (ok(mid)) {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    printf("Case #%d: %d\n", testNumber, ans);
}

void precompute() {

}
