/**
 * @author - iSea_baidu @ 2016-04-09 21:00
 * @brief - From sky to the sea.
 **/

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <map>
#include <set>
#include <random>
using namespace std;

// SELF TEMPLATE CODE BGEIN

#define LOG(level, fmt, arg...) \
    fprintf(stderr, "[" #level "] [Line:%d] " fmt"\n", __LINE__, ##arg);
#define NOTICE(fmt, arg...) LOG(NOTICE, fmt, ##arg)
#define FATAL(fmt, arg...) LOG(FATAL, fmt, ##arg)
#define DEBUG(x) do { \
    stringstream ss; \
    ss << #x << ": " << x; \
    NOTICE("%s", ss.str().c_str()) \
} while(0)

#define SZ(x) ((int)((x).size()))
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repcase int t, Case = 1; for (scanf("%d", &t); t; --t)
template<class T> inline void to_min(T &a, const T b) { if (b < a) a = b; }
template<class T> inline void to_max(T &a, const T b) { if (b > a) a = b; }

// SELF TEMPLATE CODE END

int random_bit() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, 1);
    return dis(gen);
}

const int maxn = 100 + 10;

int primes[maxn], cnt = 0;
bool is_prime[maxn];

void gen_prime() {
    for (int i = 2; i < maxn; ++i) {
        if (!is_prime[i]) {
            primes[cnt++] = i;
            for (int j = (i << 1); j < maxn; j += i) {
                is_prime[j] = true;
            }
        }
    }
}

int mod(const string& s, int base, int m) {
    int ret = 0;
    for (char ch : s) {
        ret = (ret * base + ch - '0') % m;
    }
    return ret;
}

int calc_factor(const string& s, int base) {
    rep (i, cnt) {
        if (mod(s, base, primes[i]) == 0) {
            return primes[i];
        }
    }
    return -1;
}

int main() {
    gen_prime();
    repcase {
        int n, j;
        scanf("%d%d", &n, &j);
        set<string> cached_nums;
        printf("Case #%d:\n", Case++);
        rep (i, j) {
            while (true) {
                // generate a number
                string str;
                while (true) {
                    str = "1";
                    rep (k, n - 2) {
                        str += (random_bit()? '1' : '0');
                    }
                    str += '1';
                    if (cached_nums.find(str) == cached_nums.end()) {
                        break;
                    }
                }
                bool failed = false;
                vector<int> factors;
                repf (base, 2, 10) {
                    int factor = calc_factor(str, base);
                    factors.push_back(factor);
                    if (factor == -1) {
                        failed = true;
                        break;
                    }
                }
                if (!failed) {
                    printf("%s", str.c_str());
                    for (int fac : factors) {
                        printf(" %d", fac);
                    }
                    puts("");
                    cached_nums.insert(str);
                    break;
                }
            }
        }
    }
    return 0;
}