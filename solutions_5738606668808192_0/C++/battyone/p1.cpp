#include "std.h"
#define DBGLEVEL 1
#include "debug.h"

char buf[1024];
char ans[1024];
int N;

ull prime(ull n)
{
    for(ull d = 2; d * d <= n; d++) if (n % d == 0) return d;
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

	ull first = (1ull << (N-1)) + 1;
	ull last = (1ull << N) - 1;
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
		ull d = prime(nb);
		if (d == nb) {
		    goto next;
		}

		div[b] = d;

	    }
	    FOR(k, N) cout << ( (n & (1ull<<(N-1-k))) ? '1' : '0');
	    FOR2(b, 2, 11) cout << " " << div[b];
	    cout << endl;
	    if (--J == 0) break;
	next:;
	}
	
	
    }
    return 0;
}
