#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <map>
using namespace std;

long long length;
long long deg[50];
long long p = 2;
map<long long, int> degrees;

void createDeg() {
    deg[0] = 1;
    for (int i = 1; i < 50; i++)
        deg[i] = deg[i - 1] * p;
    for (int i = 0; i < 50; i++)
        degrees.insert(make_pair(deg[i], i));
}

long long gcd(long long a, long long b) {
    while (a && b) {
        if (a > b) a %= b;
        else b %= a;
    }
    return a + b;
}

long long rec(long long p, long long q) {
    if (p == q) return 0;
    if (p > q) return -1;
    long long nod = gcd(p, q);
    p /= nod;
    q /= nod;
    if (degrees.find(q) == degrees.end()) return -1;

    if (p == 1 && degrees.find(q) != degrees.end()) {
        return degrees[q];
    }
    else if (p < 0) return -1;
    else if (p == 0) return 1e17;

    if (q == 1) return -1;
    if (q % 2 != 0) return -1;

    long long answer = -1;
    for (int i = 1; i <= q/2; i++) {
        long long first = i;
        long long second = p - i;
        if (second < 0) break;
        long long ans_1 = rec(first, q/2LL);
        long long ans_2 = rec(second, q/2LL);
        if (ans_1 < 0 || ans_2 < 0 || (ans_1 > 1e16 && ans_2 > 1e16)) ;
        else { answer = min(ans_1, ans_2) + 1; break; }
    }

    return answer;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    createDeg();
    int test; cin >> test;
    for (int t = 1; t <= test; t++) {
        long long p, q;
        scanf("%lld%*c%lld", &p, &q);
        length = rec(p, q);
        if (length >= 0 && length < 41) {
            printf("Case #%d: %lld\n", t, length);
        }
        else {
            printf("Case #%d: impossible\n", t);
        }
    }

    return 0;
}
