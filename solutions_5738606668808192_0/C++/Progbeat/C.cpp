#include <algorithm>
#include <iostream>
#include <assert.h>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)      (a).begin(),(a).end()
#define sz(a)       int((a).size())
#define FOR(i,a,b)  for(int i=a;i<b;++i)
#define REP(i,n)    FOR(i,0,n)
#define UN(v)       sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)     memset(a,b,sizeof a)
#define pb          push_back
#define X           first
#define Y           second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> point;

void run() {
	int n, m;
    cin >> n >> m;
    const int L = 32768;
    vi primes;
    for (int x = 2; x < L; ++x) {
        bool ok = true;
        for (int y = 2; y * y <= x; ++y) {
            if (x % y == 0) {
                ok = false;
                break;
            }
        }
        if (ok) primes.pb(x);
    }
    cout << endl;
    for (ll p = (1ll << (n - 1)) + 1; (p < 1ll << n) && m > 0; p += 2) {
        vi divs;
        for (int b = 2; b <= 10; ++b) {
            bool ok = false;
            for (int d : primes) {
                int x = 0;
                REP (i, n) {
                    x = x * b % d;
                    if ((p >> i) & 1) {
                        x = (x + 1) % d;
                    }
                }
                if (x == 0) {
                    ok = true;
                    divs.pb(d);
                    break;
                }
            }
            if (!ok) break;
        }
        if (sz(divs) == 9) {
            --m;
            REP (i, n) {
                cout << ((p >> i) & 1);
            }
            for (int d : divs) {
                cout << ' ' << d;
            }
            cout << endl;
        }
    }
    assert(m == 0);
}

int main(){
	cout.precision(12);
	cout.setf(ios::fixed);
	int a = 0, b = 0;
	for(cin >> b; a++ < b ; run()) 
		printf("Case #%d:", a);
	return 0;
}
