#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <set>

#define For(i,a,b) for(int i = a; i < b; i++)
#define rep(i,x) For(i,0,x)
#define foreach(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define TWO(x) (1LL<<(x))

#define ll long long

std::vector<int> shatter(ll in) {
    std::vector<int> v;
    while(in != 0) {
        v.push_back(in % 10); 
        in /= 10;
    }
    reverse(v.begin(), v.end());
    return v;
}

ll unshatter(std::vector<int> v) {
    ll res = 0;
    for(size_t i = 0; i < v.size(); i++) {
        res *= 10;
        res += v[i]; 
    }
    return res;
}

ll doit(ll in) {
    std::vector<int> v;
    while(in != 0) {
        v.push_back(in % 10); 
        in /= 10;
    }
    ll res = 0;
    for(size_t i = 0; i < v.size(); i++) {
        res *= 10;
        res += v[i];
    }
    return res;
}

int digits(ll in) {
    int res = 0;
    while(in != 0) {
        res++;
        in /= 10;
    }
    return res;
}

ll nines(ll in) {
    ll res = 0;
    for(int i = 0; i < in; i++) {
        res *= 10;
        res += 9;
    }
    return res;
}

ll make(ll dig) {
    ll res = 1;
    for(int i = 0; i < dig-1; i++)
        res *= 10;
    return res;
}

ll doitt(ll n) {
    int dig = digits(n);
    std::cerr << "digits="<<dig << std::endl;
    int curdig = 1;
    ll basecost=1;
    while(curdig < dig) {
        int before = (curdig + 1) / 2;
        int after = curdig - before;
        if(curdig != 1)
            basecost += 1;
        basecost += nines(before);
        basecost += nines(after);
        curdig++;
    }

    ll at = make(dig);

    std::cerr << "basecost="<<basecost<<std::endl;

    ll res = n - at + basecost;
    std::cerr << "normal cost="<<res<<std::endl;

    std::vector<int> v = shatter(n);
    int split = v.size() / 2;

    std::vector<int> A;
    for(int i = split; i < v.size(); i++)
        A.push_back(v[i]);
    long long acost = unshatter(A);

    std::vector<int> B;
    for(int i = split-1; i >= 0; i--)
        B.push_back(v[i]);
    long long bcost = unshatter(B);

    if(acost >= 1) {
        long long special = basecost + acost + bcost;
        std::cerr << "special="<<special << " acost="<<acost<<" bcost="<<bcost<<std::endl;
        if(special < res)
            res = special;
    }
    return res;
}

static const int MAXN=1000000;
int DP[MAXN+1];
int FROM[MAXN+1];

using namespace std;
int main() {
int nprob; cin >> nprob;
rep(tprob, nprob) {
    ll n; cin>>n;

    ll res = doitt(n);
    if(n > 1) {
        res = std::min(res, doitt(n-1) + 1);
    }

    cout << "Case #" << (tprob + 1) << ": " << res << std::endl;
} 

/*

memset(DP, 0x4f, sizeof(DP));
memset(FROM, 0, sizeof(FROM));
DP[1] = 1;

for(int i = 1; i < MAXN; i++) {
    int at = DP[i];
    if(doit(i) > i && doit(i) <= MAXN) {
        int to = doit(i);
        if(at + 1 < DP[to]) {
            FROM[to] = i;
            DP[to] = at + 1;
        }
        
    }
    int to = i + 1;
    if(at + 1 < DP[to]) {
        FROM[to] = i;
        DP[to] = at + 1;
    }
}

for(int x = 999999; x != 1; x = FROM[x]) {
    std::cout << x << std::endl;
}

int nprob; cin >> nprob;
rep(tprob, nprob) {
    int n; cin>>n;

    cout << "Case #" << (tprob + 1) << ": " << DP[n] << std::endl;
} 
*/
}
