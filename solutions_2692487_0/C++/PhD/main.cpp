#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
using namespace std;

int buf;
inline int in(){
	scanf("%d", &buf);
	return buf;
}

long long gcd(long long a, long long  b,long long  &x, long long  &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	long long x1, y1;
	long long d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a)*x1;
	y = x1;
	return d;
}

long long lcm(long a, long b){
	long long  x, y;
	return a/gcd(a, b, x, y)*b;
}


int gcd(int a, int b, int &x, int &y){
	if(a == 0){
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int g = gcd(b % a, a, x1, y1);
	x = y1 - (b/a) * x1;
	y = x1;
	return g;
}

int rev(int a, int p){
	int x, y;
	int g = gcd(a, p, x, y);
	if(g == 1){
		return  (x%p + p) % p;		
	}

}

int binpow(int a, int n, int p){
	int res = 1;
	while(n){
		if(n & 1) res = (res * a) % p;
		a = (a * a) % p;
		n >>= 1;
	}
	return res;
}

int inv(int a, int m){
	int x, y;
	int g = gcd(a, m, x, y);
	if (g == 1){
		x = (x % m + m) % m;
		return x;
	}
}

const int p = 2007;
const int maxn = 10004;

int f[maxn], g[maxn];

int main(){

	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T = in();
    for(int t = 0; t < T; ++t){
        long long cur = in(), n = in();
        multiset <int> s;
        for(int j=0;j<n;++j){
            s.insert(in());
        }
        long long res = s.size(), cura = 0;
        while(!s.empty() && cur > 1){
            int c = *s.begin();
            if(c < cur){
                cur += c;
                s.erase(s.begin());
                continue;
            }
            res = min(res, cura + (int)s.size());
            if(cur != 0){
                ++cura;
                cur = 2*cur-1;
            }
        }
        if(cur > 1) res = min(res, cura);

        printf("Case #%d: %lld\n", t+1, res);
    }

	return 0;
}