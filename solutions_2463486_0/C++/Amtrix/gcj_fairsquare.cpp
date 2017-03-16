#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
using namespace std;

typedef long long ll;

const ll maxn = 100000000000000LL;
const int maxnr = 10000000;


int tmp[100];
bool isPalindromic(int n) {
    int sz = 0;
    while (n)
        tmp[sz++] = n%10, n /= 10;

    for (int i = 0; i < sz; ++i)
        if (tmp[i] != tmp[sz-1-i])
            return false;
    return true;
}
bool isPalindromic(ll n) {
    int sz = 0;
    while (n)
        tmp[sz++] = n%10, n /= 10;

    for (int i = 0; i < sz; ++i)
        if (tmp[i] != tmp[sz-1-i])
            return false;
    return true;
}

int main() {
    freopen("Ulaz.txt","r",stdin);
    freopen("Izlaz.txt","w",stdout);
    vector<ll>nice;
    for (int i = 1; i <= maxnr; ++i) {
        if (!isPalindromic(i)) continue;
        ll q = i*(ll)i;
        if (isPalindromic(q))
            nice.push_back(q);
    }


    int tests; scanf("%d",&tests);
    for (int t = 1; t <= tests; ++t) {
        ll a,b;
        cin >> a >> b;
        int sol = 0;
        for (int i = 0; i < nice.size(); ++i)
            if (a <= nice[i] && nice[i] <= b)
                sol++;
        printf("Case #%d: %d\n",t,sol);
    }

    return 0;
}
