#include <bits/stdc++.h>

#define PB push_back
#define ii pair<int, double>
#define MAX 10000000
#define INF 0x7fffffff / 2
#define ll long long
#define MOD 1000000007L
#define PI acos(-1)

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<ii> vii;
typedef vector<double> vd;
typedef vector< vector<int> > vvi;
typedef vector< vector<ll> > vvl;
typedef vector< vector<ii> > vvii;

const int MAX_PRIMES = 1000;
vi primes;
bool mark[MAX];

void sieve() {
    for(int i = 2; i < MAX && primes.size() != MAX_PRIMES; i++)
        if(!mark[i]) {
            primes.PB(i);
            for(int j = i + i; j < MAX; j += i)
                mark[j] = true;
        }
}

const int MAX_BASE = 10, TOTAL_COINJAM = 500, LENGTH = 32;

ll memo[MAX_BASE + 1][LENGTH][MAX_PRIMES];
int cases;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);/**/

    //freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    sieve();

    for(int b = 2; b <= MAX_BASE; b++)
        for(int pot = 0; pot < LENGTH; pot++)
            for(int p = 0; p < MAX_PRIMES; p++)
                if(pot == 0)
                    memo[b][pot][p] = 1;
                else
                    memo[b][pot][p] = (memo[b][pot - 1][p] * b) % primes[p];

    cout << "Case #1:\n";

    for(ll mask = ( 1ll << (LENGTH-1) ) + 1, k = 0; k < TOTAL_COINJAM ; mask += 2) {
        vi ans;
        for(int b = 2; b <= MAX_BASE; b++) {
            for(int p = 0; p < MAX_PRIMES; p++) {
                ll sum = 0;
                for(int i = 0; i < LENGTH; i++) {
                    if( (mask >> i)&1 ) {
                        sum = (sum + memo[b][i][p]) % primes[p];
                    }
                }
                if(sum == 0) {
                    ans.PB(primes[p]);
                    break;
                }
            }
        }
        if(ans.size() == 9) {
                for(int i = (LENGTH - 1); i >= 0; i--) cout << ((mask >> i)&1);
                k++;
                for(auto &x : ans) {
                    cout << " " << x;
                }
                cout << "\n";
            }
    }






}
