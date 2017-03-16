#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define forn(i, n) for(int i = 0; i < (n); ++i)
#define forv(i, a) forn(i, (int)(a).size())

typedef long long lng;

int n, cnt;
const int PRIMES_CNT = 100;
int primes[] = 
{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541};

bool is_divisible(lng mask, int base, int div)
{
    lng res = 0;
    for(int i = n-1; i >= 0; --i)
    {
        res *= base;
        if(mask&(1LL<<i))
        {
            res++;
        }

        res %= div;
    }

    return res == 0;
}

int find_divisor(lng mask, int base)
{
    forn(i, PRIMES_CNT)
    {
        if(is_divisible(mask, base, primes[i]))
        {
            return primes[i];
        }
    }

    return -1;
}

bool is_good(lng mask)
{
    for(int base = 2; base <= 10; ++base)
    {
        if(find_divisor(mask, base) < 0)
        {
            return false;
        }
    }
    return true;
}

vector<pair<lng, vector<int>>> res;
void add_to_res(lng mask)
{
    vector<int> divisors;
    for(int base = 2; base <= 10; ++base)
    {
        divisors.push_back(find_divisor(mask, base));
    }

    res.emplace_back(mask, divisors);
}

void print_res()
{
    if(res.size() < cnt)
    {
        cout << "!!!FAIL!!!" << endl;
    }

    forv(i, res)
    {
        lng mask = res[i].first;
        auto& divisors = res[i].second;

        for(int r=(n-1); r>=0; --r)
        {
            cout << ((mask&(1<<r)) ? 1 : 0);
        }
        cout << " ";
        for(int div : divisors)
        {
            cout << div << " ";
        }
        cout << endl;
    }
}

void solve()
{
    for(lng mask = (1LL<<(n-1)) + 1; mask < (1LL<<n) && res.size() < cnt; mask+=2)
    {
        if(is_good(mask))
        {
            add_to_res(mask);
        }
    }

    print_res();
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    int T;
    cin >> T;
    forn(tc, T) {
        cin >> n >> cnt;
        std::cout << "Case #" << tc + 1 << ": " << endl;
        solve();
    }
    
    return 0;
}
