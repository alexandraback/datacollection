#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;
long p[111] = {};
long long b,n ;

long maxar() {
    long res = 0;
    for (int i = 0; i < n; i ++)
        if (res < p[i] ) res = p[i];
    return res;
}

bool hasbit(long long t, long i){
    long long temp = 1; temp = 1 << i;
    if (t & temp) return 1;
    return 0;
}

long solve() {
    long long t = 1;
    if (n > (t << (b-2))) {
        cout <<"IMPOSSIBLE";
        return 0;
    }
    cout <<"POSSIBLE\n";
    for (int i = 0; i <= b; i ++ )
        p[i] = 0;

    if (n == (t << (b-2))) {
        n = n - 1;
        p[b] = 1;
    }

    for (int i = 2; i <= b-1; i ++ ) {
        if (hasbit(n,b-i-1))
            p[i] = 1;
    }
    for (int i = 1; i <= b; i ++)
        cout << p[i];
    cout << endl;
    for (int i = 2; i < b; i ++) {
        for (int j = 1; j <= b; j ++ ) cout << ((j <= i) ? 0 : 1);
        cout << endl;
    }
    for (int j = 1; j <= b; j ++)cout << 0;

}

int main () {
	long t = 0;
	freopen("B-small-attempt1-2.in","r",stdin); freopen("out.out","w",stdout);

	cin >> t;
	for (int i = 0; i < t; i ++) {
		cin >> b >> n ;
		printf("Case #%d: ", i + 1);
		solve();
		printf("\n");
	}
	return 0;
}
