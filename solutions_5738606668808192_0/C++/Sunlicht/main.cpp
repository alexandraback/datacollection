#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;

ll _sieve_size;  // 10^7 should be enough for most cases
vi primes;   // compact list of primes in form of vector<int>
const int64_t MAX = 1111111111111111;
const int64_t SMAX = 33333334;
bitset<SMAX+1> bs;


// first part

void sieve(ll upperbound) {          // create list of primes in [0..upperbound]
    _sieve_size = upperbound + 1;                   // add 1 to include upperbound
    bs.set();                                                 // set all bits to 1
    bs[0] = bs[1] = 0;                                     // except index 0 and 1
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    // cross out multiples of i starting from i * i!
        for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
        primes.push_back((int)i);  // also add this vector containing list of primes
    }
}

void pr(vector<int>& v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void pr_bin(int n){
    int k = 2, cnt = 0;
    while(n / k != 0){
        k *= 2;
        cnt++;
    }
    for(int i = cnt; i >= 0; i--){
        cout << ((n >> i) & 1);
    }
}

bool solved(int n, vector<int>& divs){
    for(int64_t i = 2; i <= 10; i++){
        int64_t based = 0, temp = n, factor = 1;
        bool succes = false;
        for(int j = 0; j < 16; j++){
            if(temp & 1){
                based += factor;
            }
            factor *= i;
            temp >>= 1;
        }
        //cout << "Based number: " << based << " in base " << i << endl;
        if(based <= SMAX){
            if(bs[based]){
                return false;
            }
        }
        for(int j = 0; j < primes.size() && (primes[j] * primes[j] < based); j++){
            if((based % primes[j]) == 0){
                divs[i-2] = primes[j];
                succes = true;
                break;
            }
        }
        if(!succes){
            return false;
        }
    }
    return true;
}

int main()
{
    sieve(SMAX);
    //cout << "done sieving" << endl;
    int cases, cas = 0;
    cin >> cases;
    while(cases--){
        cas++;
        int cnt, bits;
        cin >> bits >> cnt;
        cout << "Case #" << cas << ":" << endl;
        int n = 0;
        n += (1 << (bits-1));
        n += 1;
        //cout << n << endl;
        //cin >> cases;
        vector<int> divs (9,0);
        while(cnt && n <= (1 << bits) - 1){
            //cout << "Number n: " << n << " binary: ";
            //pr_bin(n);
            //cout << endl;
            if(solved(n,divs)){
                pr_bin(n);
                cout << " ";
                pr(divs);
                cnt--;
            }
            divs.clear();
            divs.assign(9,0);
            n += 2;
        }

    }
    return 0;
}
