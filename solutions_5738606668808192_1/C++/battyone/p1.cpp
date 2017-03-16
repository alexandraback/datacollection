#include "std.h"
#define DBGLEVEL 1
#include "debug.h"

char buf[1024];
char ans[1024];
int N;

#define NP 64
#define MAXP 40
int primes[NP];

int fmodprime[12][NP];

void precalc(int N)
{
    int np = 0;
    for(int n = 2; np < NP; n++)
    {
	FOR(pi, np) if (n % primes[pi] == 0) goto nx;
	primes[np++] = n;
    nx:;
    }

    FOR2(b, 2, 11)
    {
	FOR(pi, NP)
	{
	    int pr = primes[pi];
	    int r = 1;
	    FOR(p, N - 1) r = (r * b) % pr;
	    fmodprime[b][pi] = r;
	}
    }
}

ull prime(int b, ull n)
{
    FOR(pi, NP)
    {
	int pr = primes[pi];
	int fm = fmodprime[b][pi];
	if ((fm + n) % pr == 0) return pr;
    }
    return n;
}


int main() {
    int T;
    cin >> T;
    FOR(tt, T)
    {
	int N, J;
	cin >> N >> J;
	cout << "Case #"<<(tt+1)<<": ";
	cout << endl;
	precalc(N);
	//ull first = (1ull << (N-1)) + 1;
	//ull last = (1ull << N) - 1;
	ull first = 1;
	ull last = (1ull << (N-1)) - 1;

	ull lastbit = 1ull << (N-1);
	for(ull n = first; n <= last; n += 2)
	{
	    int div[12];
	    FOR2(b, 2, 11)
	    {
		ull m2 = 1;
		ull mb = 1;
		ull nb = 0;
		while (m2 <= n)
		{
		    if (n & m2) nb += mb;
		    m2 *= 2;
		    mb *= b;
		}
		ull d = prime(b, nb);
		if (d == nb) {
		    goto next;
		}

		div[b] = d;

	    }
	    ull rn; rn = lastbit + n;
	    FOR(k, N) cout << ( (rn & (1ull<<(N-1-k))) ? '1' : '0');
	    FOR2(b, 2, 11) cout << " " << div[b];
	    cout << endl;
	    if (--J == 0) break;
	next:;
	}
	
	
    }
    return 0;
}
