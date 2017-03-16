#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

ll current = 0;
ll step,z = 0;

ll tizes (int db) {
    ll x = (ll)1;
    for (int i = 1; i<db; i++) x*=10;
    return x;
}
ll kilences (int db) {
    if (db == 0) return (ll)0;
    ll x = (ll)9;
    for (int i = 1; i<db; i++) { x = x*10+9; }
    return x;
}

int jegy (ll x) {
    int db = 0;
    while (x > 0) {
        x = x / 10;
        db++;
    }
    return db;
}

ll turn (ll x) {
    ll y = (ll)0;
    while (x > 0) {
        y = y*10 + (x % 10);
        x = x / 10;
    }
    return y;
}

ll answer(ll x) {
	if (x % 10 == 0) return answer(x-1)+1;

    if (x <= 20) return x;
    step = (ll)0;
    current = (ll)0;
    ll y = (ll)1;
    for (int i = 1; i<jegy(x); i++) {
    	//printf("i=%d\n", i);
        z = tizes(i) + kilences(i/2);
        step += z-current;
        current = z;
    	//printf("a %lld  (%lld)\n", current, step);
        if (i > 1) {
        	current = turn(current); step++;
	    	//printf("b %lld  (%lld)\n", current, step);
	    }
    }
    //printf("c %lld  (%lld)\n", current, step);
    
    z = tizes(jegy(x));
    step += z-current; current = z;
    //printf("d %lld  (%lld)\n", current, step);
    
    z += turn(x)%(tizes(jegy(x)/2+1));
    step += z-current; current = z;
    //printf("e %lld  (%lld)\n", current, step);
    
    if (current != turn(current)) {
    	current = turn(current); step++;
    	//printf("f %lld  (%lld)\n", current, step);
    }
    
    z = x;
    step += z-current;
    current = z;
    //printf("g %lld  (%lld)\n", current, step);
    return step;
}


int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i<=t; i++) {
		ll x; scanf("%lld", &x);
		printf("Case #%d: %lld\n", i, answer(x));
	}
    return 0;
}















