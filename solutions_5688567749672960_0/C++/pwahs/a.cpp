#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define dbg(args...) {debug,args; cerr << endl;}

#define mp make_pair
#define mt(a,b,c) mp(a,mp(b,c))
#define P1(a) (a).first
#define P2(a) (a).second
#define T1(a) (a).first
#define T2(a) (a).second.first
#define T3(a) (a).second.second
#define INF 1e20
#define EPS 1e-8

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> tiii;

class debu{
	public:
	template<class someClass>
	debu & operator,(someClass arg){
		cerr << arg << " ";
		return *this;
	}
} debug;


void init(){
    cout << setprecision(8)<< fixed;
}

ll reverse(ll a) {
    ll b = 0;
    while (a) {
        b = b * 10ll + a%10ll;
        a/=10ll;
    }
    return b;
}

ll power(ll b, ll e) {
    ll a = 1;
    while (e > 0) {
        a *= b;
        e--;
    }
    return a;
}

//a = 10^(x-1)
ll times10(ll& a, ll& x) {
    a*=10;
    ll ans = power(10, x/2) - 1 + power(10, (x+1)/2) - 1;
    if (x > 1) ans++;
    x += 1;
    return ans;
}

int solve(int testnr){
    ll N;
    cin >> N;
    if (N < 10) return N;
    ll a = 1;
    ll steps = 1;
    ll x = 1;
    while (a * 10ll <= N) {
        steps += times10(a, x);
    }
    ll revN = reverse(N);
    if (a == N) return steps;
    if (N % power(10, (x+1)/2) == 0) {
        if (reverse(N / power(10, (x+1)/2) - 1) > 1) {
            steps += reverse(N / power(10, (x+1)/2) - 1);
            steps ++; //reverse
            steps += power(10, (x+1)/2) - 1;
        } else {
            steps += power(10, (x+1)/2);
        }
//        steps += power(10, (x+1)/2) - 1; // add 9 at the end
//        a += power(10, (x+1)/2) - 1;
//        if (a + 1 != N) {
//            steps ++; //reverse
//            steps += revN % power(10, x/2) - 2;
//            steps ++; //reverse
//        }
//        steps ++; //overflow
    } else {
        if (a + N % power(10, (x+1)/2) == N) {
            steps += N % power(10, (x+1)/2);
        } else{
            steps += revN % power(10, x/2);
            steps ++; //reverse
            steps += N % power(10, (x+1)/2) - 1;
        }
    }
    
    return steps;
    
//    return steps;
}

int main(){

    init();
    
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        cout << "Case #" << i << ": " << solve(i) << "\n";
    }
    
    return 0;
}
