#include <iostream>
#include <cstdio>
#include <map>
#include <bitset>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <memory.h>
#include <bitset>

using namespace std;

#define ll long long

#define MAX_N 100
#define MAX_P_LEN 100000

ll a, b;
int A[10000005];

bool isPal(ll n) {
    vector<int> v;
    while(n) {
        v.push_back((int)(n%10));
        n/=10;
    }
    int N = v.size();
    for(int x = 0, y = N - 1;x<N && y >= 0;x++, y--) {
        if(v[x] != v[y]) return false;
    }
    return true;
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    for(ll i = 1;i * i<=100000000000000LL;i++) {
        A[(int)i] = A[(int)i - 1];
        if(isPal(i) && isPal(i * i))
            A[(int)i]++;
    }
    int T;
    scanf("%d",&T);
    for(int t = 1;t<=T;t++) {
        cin>>a>>b;
        int leftIdx = (int)sqrt(a - 1), rightIdx = (int)sqrt(b);
        printf("Case #%d: %d\n", t, A[rightIdx] - A[leftIdx]);
    }
    return 0;
}
