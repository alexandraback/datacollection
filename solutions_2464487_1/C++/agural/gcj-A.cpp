/*
LANG: C++
ID: 2012agural
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <ctime>

using namespace std;
FILE *fin  = fopen("ina.in",  "r");
FILE *fout = fopen("outa.out", "w");
/*
* Keep arrays small.  Smaller than 4,000,000 integers or 2,000,000 long longs/doubles
*/

long long f(long long k, long long r) {
    return k * (2*r + 2*k - 1);
}

int main () {
	int T;
    long long r,t;
	fscanf(fin, "%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        fscanf(fin, "%lld %lld", &r, &t);
        long long tk = 1, bp = 1, tp = 1, k = 1;

        while(f(k, r) < t) {
            bp = k;
            k *= 2;
            tp = k;
        }

        while(f(k, r) > t || f(k+1, r) <= t) {
            k = (bp + tp)/2;
            if(f(k, r) <= t) bp = k;
            else tp = k;
        }
        fprintf(fout, "Case #%d: %lld\n", tc, k);
    }

	return 0;
}


