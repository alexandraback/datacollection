#include <bits/stdc++.h>

using namespace std;

#define Long long long
#define ld long double
#define pii pair<int, int>
#define pli pair<Long, int>

const int me = 125;
const int mod = 1.e9 + 7;
const int MAX_LOG = 20;

int t, n, k, sz;
char s[me];
vector<int> primes;
vector<Long> result[555];

void get_primes(){
    const int up = 2002;
    vector<char> used(up, 0);
    for(int i = 2; i < up; i ++)
        if(!used[i])
            for(int j = i + i; j < up; j += i)
                used[j] = 1;
    for(int i = 2; i < up; i ++)
        if(!used[i])
            primes.push_back(i);
}
inline int is_prime(int bits, int base){
    for(int i : primes){
        int r = 0;
        for(int j = 0; j < bits; j ++){
            r = r * base + s[j];
            if(r >= i)
                r %= i;
        }
        if(r == 0)
            return i;
    }
    return -1;
}
inline int is_prime2(int bits, int base){
    Long x = 0;
    for(int i = 0; i < bits; i ++)
        x = x * base + s[i];
    Long cs = (int)sqrt(x);
    for(int i : primes){
        if(i > cs)
            break;
        if(x % i == 0)
            return i;
    }
    return -1;
}
void gen(int bits, int need){
    sz = 0;
    Long from = 1LL << (bits - 1);
    for(Long i = from + 1; i < (1LL << bits); i += 2){
        if(sz > need)
            break;
        for(int j = 0; j < bits; j ++)
            s[bits - 1 - j] = (i & (1LL << j)) ? 1 : 0;
        int good = 1;
        vector<int> divisors(0);
        for(int j = 2; j <= 10 && good; j ++){
            int g;
            if(bits > 16)
                g = is_prime(bits, j);
            else g = is_prime2(bits, j);
            good &= (g != -1);
            divisors.push_back(g);
        }
        if(good){
            ++ sz;
            result[sz].push_back(i);
            for(int j : divisors)
                result[sz].push_back(j);
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    get_primes();
    scanf("%d\n", &t); /// :D
    for(int c = 0; c < t; c ++){
        scanf("%d%d", &n, &k);
        gen(n, k);
        printf("Case #%d:\n", c + 1);
        for(int i = 1; i <= k; i ++){
            for(int j = n - 1; j >= 0; j --){
                if(result[i][0] & (1LL << j))
                    printf("1");
                else printf("0");
            }
            for(int j = 1; j < result[i].size(); j ++)
                printf(" %lld", result[i][j]);
            printf("\n");
        }
    }

    return 0;
}
