#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm> // max...
#include <utility> // pair
#include <complex>
#include <climits> // int, ll...
#include <limits> // double...
#include <cmath> // abs, atan...
#include <cstring> // memset
#include <string>
#include <functional> // greater, less...
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, double> id;
typedef pair<double, int> di;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<id> vid;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef map<int, ll> mil;
typedef map<ll, ll> mll;

//#define ONLINE_JUDGE

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++)
        if (bs[i]) {
            for (ll j = i*i; j <= _sieve_size; j += i) bs[j] = 0;
            primes.push_back(i);
        }
}

bool isPrime(ll N) {
    if (N <= _sieve_size) return bs[N];
    for (int i = 0; i < primes.size(); i++)
        if (N % primes[i] == 0) return false;
    return true;
}

ll tobasek(ll x, int k) {
    ll p = 1;
    ll ret = 0;
    while (x > 0) {
        ret += (x % 2) * p;
        x /= 2;
        p *= k;
    }
    return ret;
}

string dec2bin(ll n) {
    string result;

    do result.push_back('0' + (n & 1));
    while (n >>= 1);

    reverse(result.begin(), result.end());
    return result;
}

int main() {
#ifdef ONLINE_JUDGE
    freopen("X-small-practice.in", "r", stdin);
        freopen("X-small-practice.out", "w", stdout);
        //freopen("X-large-practice.in", "r", stdin);
        //freopen("X-large-practice.out", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    sieve(10000000);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        printf("Case #%d:\n", t);

        int N, J; cin >> N >> J;

        int a = (1ULL << N-1), b = (1ULL << N) - 1;
        for (int x = a+1; x <= b && J > 0; x += 2) {
            vi divisors;
            for (int k = 2; k <= 10; k++) {
                ll y = tobasek(x, k);
                if (isPrime(y)) break;
                for (ll d = 2; d < y; d++) {
                    if (y % d == 0) {
                        divisors.push_back(d);
                        break;
                    }
                }
            }
            if (divisors.size() == 9) {
                cout << dec2bin(x) << " ";
                /*for (int k = 2; k <= 10; k++) cout << tobasek(x, k) << " ";
                cout << endl;*/
                for (int i = 0; i < 8; i++)
                    printf("%d ", divisors[i]);
                cout << divisors[8] << endl;
                J--;
            }
        }
        if (J != 0) cout << "FUCK" << endl;
    }

    return 0;
}