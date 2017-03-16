#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#define MAX 3000
using namespace std;

struct Attack {
    int d, n, w, e, s, dd, dp, ds;
        
    inline bool operator<(const Attack& o) const {
        return d>o.d;
    }
    
    Attack next() {
        Attack o = *this;
        o.d += dd;
        o.n -= 1;
        o.w += dp;
        o.e += dp;
        o.s += ds;
        return o;
    }
};

priority_queue<Attack> Q;
queue<Attack> T;
map<int, int> W;

int get(int x) {
    if (W.find(x) == W.end())
        return 0;
    else
        return W[x];
}

bool attack(Attack a) {
    bool success = false;
    for(int i=a.w; i<=a.e; i++) {
        if(get(i) < a.s)
            success = true;
    }
    return success;
}

void build(Attack a) {
    for(int i=a.w; i<=a.e; i++) {
        if(get(i) < a.s)
            W[i] = a.s;
    }
}

int main() {
    int cc=0, cases; 
    cin >> cases;
    while(cc++ < cases) {
        int n; cin >> n;
        W.clear();
        for(int i=0; i<n; i++) {
            Attack a;
            cin >> a.d >> a.n >> a.w >> a.e >> a.s >> a.dd >> a.dp >> a.ds;
            a.w *= 2;
            a.e *= 2;
            a.dp *= 2;
            
            Q.push(a);
        }
        
        int answer = 0;
        while(Q.size()) {
            Attack a = Q.top(); Q.pop();
            T.push(a);
            if (attack(a)) answer++;

            while(Q.size() && Q.top().d == a.d) {
                a = Q.top(); Q.pop();
                T.push(a);
                if (attack(a)) answer++;
            }
            
            while(T.size()) {
                Attack a = T.front(); T.pop();
                build(a);
                Attack o = a.next();
                if (o.n > 0)
                    Q.push(o);
            }
        }
        
        cout << "Case #" << cc << ": " << answer << endl;
    }
}
