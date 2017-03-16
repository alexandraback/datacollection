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
vector<int> v;
int n;

void precompute();
void init();
void solve(int);

int main() {
//    input("test.txt");
    input("PankakeHouseBig.in");
    output("PankakeHouseBig2.out");
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
    v.resize(n);

    f(i,0,n-1) {
        cin >> v[i];
    }
}

int calc(int part) {
    int divisions = 0;
    if (part >= v[n-1]) {
        return v[n-1];
    }
    else {
        int currDivs;
        f(i,0,n-1) {
            currDivs = v[i] / part;
            if (v[i] % part == 0) {
                currDivs--;
            }
            divisions += currDivs;
        }
        return divisions + part;
    }
}

void solve(int testNumber) {
    sort(v.begin(), v.end());

    int bestAns = 1000000, currAns;
    f(i,1,1000) {
        currAns = calc(i);
        bestAns = min(bestAns, currAns);
    }

    printf("Case #%d: %d\n", testNumber, bestAns);
}

void precompute() {
}
