#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
//typedef pair<int, int> P;
typedef long long ll;
int T;
int N;
ll P, Q;

//is power of 2
bool C(ll n) {
    while (n > 1) {
        if (n % 2 == 1) return false;
        n >>= 1;
    }
    return true;
}

//2のn乗
int C2(ll n) {
    int x = 0;
    while (n > 1) {
        x++;
        n >>= 1;
    }
    return x;
}

//2のベキ乗以外の数値を求める
ll C3(ll n) {
    while (n % 2 == 0) {
        n >>= 1;
    }
    return n;
}

int main(int argc, const char * argv[])
{
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%lld", &P);
        char c;
        scanf("%c", &c);
        scanf("%lld", &Q);
        ll x = C3(Q);
        if (P % x != 0) {
            if (!C(Q)) printf("Case #%d: impossible\n", t+1);

        } else {
            Q /= x;
            P /= x;
            int ret = C2(Q);
            while (P > 1) {
                ret--;
                P >>= 1;
            }
            printf("Case #%d: %d\n", t+1, ret);
        }
    }
    return 0;
}

