#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <complex>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <ctime>

using namespace std;

#define DBG(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__);
#define DUMP(val) cerr << #val << " : " << (val) << endl

#define REP(a,b) for(a = 0; a < b; a++)
#define FOR(a,b,c) for(a = b; a < c; a++)
#define FOREACH(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)

#define PUSH(e) push_back(e)
#define POP(e) pop_back(e)
#define MP(a,b) make_pair(a,b)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SORT(a) sort((a).begin(),(b).end())
#define FILL(a,b) fill((a).begin(),(a).end(),b)

typedef pair<int,int> point;
#define F first
#define S second

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;

int gcd(int a, int b) {
    int c;
    while(a != 0) {
        c = a; a = b%a; b = c;
    }
    return b;
}

int check(int p, int q) {
    while(1) {
        int a = gcd(p,q);
        p /= a;
        q /= a;
        if(p == 0) {
            return 1;
        } else if(q&1) {
            return 0;
        }
        q /= 2;
        if(q <= p) {
            p -= q;
        }
    }
}

int solv(int p, int q) {
    
    int count = 1;
    while(1) {
        if((q&1) || (count > 40)) {
            return INT_MAX;
        }
        
        int a = gcd(p,q);
        p /= a;
        q /= a;
        
        q/=2;
        
        int lp, rp;
        lp = min(q, p);
        rp = p - lp;
        
        if(lp == q) {
            if(check(rp, q)) {
                return count;
            } else {
                return INT_MAX;
            }
        }
        p = lp;
        count++;
    }
    
}


int main()
{
    
    int T,P,Q;
    char c;
    
    cin >> T;
    for(int t = 0; t < T; ++t) {
        cin >> P >> c >> Q;
        int ret = solv(P,Q);
        if(ret != INT_MAX) {
            printf("Case #%d: %d\n", t+1, ret);
        } else {
            printf("Case #%d: impossible\n", t+1);
        }
    }
    
    
    return 0;
}

