#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
#include <ctime>
#include <stack>
#include <list>
#include <cassert>
#include <iomanip>
#include <deque>
#include <sstream>
#include <fstream>
typedef pair<int,int> pii;
#define rep(i,j,n) for(i=j;i<n;i++)
#define pb push_back
#define ff first
#define ss second 
#define lli long long int
const int maxn = 1e4 + 100;
bool divi[maxn];
vector <int> primes;
lli check_base(lli num, lli base) {
    lli val = 0;
    lli tmp = 1;
    while (num) {
        if (num&1) {
            val += tmp;
        }
        num /= 2;
        tmp = tmp*base;
    }
    for (int i = 0; i < primes.size() and primes[i] < val; i++) {
        if (val%primes[i] == 0) {
            return primes[i];
        }
    }
    return 0;
}

int main() {
        
    ios::sync_with_stdio(false);
    
    //clock_t start = std::clock();
    freopen ("inp.txt","r",stdin);
    freopen ("out.txt","w",stdout);
    //cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
    int t,ca = 1;
    cin >> t;

    for (int i = 2; i < maxn; i++) {
        if (divi[i]) continue;
        for (int j = i*i; j < maxn; j += i) {
            divi[j] = 1;
        }
        primes.pb(i);
    }


    while (t--) {
        cout << "Case #" << ca << ": " << endl;
        ca++;
        int n,k;
        n = 16, k = 500;
        int cnt = 0;
        for (lli i = (1ll<<n)-1; i > (1ll<<(n-1)); i -= 2) {
            vector <lli> proof;
            for (lli j = 2; j <= 10; j++) {
                lli x = check_base(i,j);
                if (x == 0) break;
                else proof.pb(x);
            }
            if (proof.size() == 9) {
                cnt++;
                lli tp = i;
                string op = "";
                while (tp) {
                    if (tp&1) {
                        op.pb('1');
                    } else {
                        op.pb('0');
                    }
                    tp /= 2;
                }
                reverse(op.begin(),op.end());
                op = op + op;
                cout << op << " ";
                for (int i = 0; i < 9; i++)
                    cout << proof[i] << " \n"[i == 8];
            }
            if (cnt == k) break;
        }
    }
    
    return 0;
        
}