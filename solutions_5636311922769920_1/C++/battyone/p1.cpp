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
	int K, C, S;
	cin >> K >> C >> S;

	vector<ull> ans;
	int k = 0;
	
	for (;;) 
	{
	    ull p = 0;
	    FOR(c, C)
	    {
		p *= K;
		if (k < K) p += k++;
	    }
	    ans.pb(p + 1);
	    if (k == K) break;
	}
	
	cout << "Case #"<<(tt+1)<<":";
	if (S < ans.size()) cout << " IMPOSSIBLE";
	else for(auto a: ans) cout << " " << a;
	cout << endl;
	
    }
    return 0;
}
