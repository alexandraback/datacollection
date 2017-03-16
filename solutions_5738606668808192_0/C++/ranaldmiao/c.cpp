#include <bits/stdc++.h>
using namespace std;
typedef long long lll;
const int P = 400000;
bitset<P> isPrime; 
bitset<32> bs;
vector<long long> vp;
lll witness[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
lll M = 1;
lll tmp[10];
lll qexp (lll b, lll e) {
	if (e == 0) return 1;
	if (e == 1) return b%M;
	lll h = qexp(b, e/2);
	h *= h;
	h %= M;
	if (e%2 == 0) return h;
	return (h*b)%M;
}
bool checkPrime(lll N) {
	if (N <= 1) return 1;
	lll s = (N-1)&(1-N), d = (N-1)/s;
	M = N;
	for (int i = 0; i < 3; ++i) {
		if (witness[i] >= N-1) break;
		lll a = qexp(witness[i], d);
		if (a == 1 || a == N-1) continue;
		bool pass = 1;
		for (lll k = 1; k < s && pass; k<<=1) {
			a*=a;
			a%=N;
			if (a == N-1) pass = false;
		}
		if (pass) return 0;
	}
	return 1;
}
int main() {
    isPrime.flip();
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i < P; ++i) {
        if (!isPrime[i]) continue;
        vp.push_back(i);
        for (int j = i+i; j < P; j+=i) isPrime[j] = 0;
    }
    int N, J;
    scanf("%d", &N);
    scanf("%d%d", &N, &J);
    printf("Case #1:\n");
    set<unsigned long> s;
    bs[0] = bs[N-1] = 1;
    while(J) {
        bool fail = 0;
        for (int i = 1; i < N-1; ++i) {
            bs[i] = rand()%2;
        }
        unsigned long t = bs.to_ulong();
        if (s.find(t) != s.end()) continue;
        else s.insert(t);
        //printf("%lld\n", t);
        memset(tmp, 0, sizeof tmp);
        for (int k = 2; k <= 10; ++k) {
            tmp[k] = 0;
            for (int i = 0; i < N; ++i) {
                tmp[k] *= k;
                if (bs[i]) ++tmp[k];
            }
            //cout << tmp[k] << " " << k << " ";
            //cin >> t;
            if (checkPrime(tmp[k])) {
                fail = 1;
                break;
            }
        }
        long long d[10];
        if (!fail) {
            //for (int i = 0; i < N; ++i) printf("%d", (int) bs[i]);
            //puts("");
            for (int k = 2; k <= 10; ++k) {
                d[k] = 0;
                for (int i = 0; i < vp.size(); ++i) {
                    if (tmp[k] % vp[i] == 0) {
                        d[k] = vp[i];
                        break;
                    }
                }
                if (d[k] == 0) {
                    fail = 1;
                    break;
                }
            }
            //if (!fail) puts("meow");
        }
        if (!fail) {
            for (int i = 0; i < N; ++i) printf("%d", (int) bs[i]);
            for (int i = 2; i <= 10; ++i) printf(" %lld", d[i]);
            puts("");
            --J;
        }
    }
}