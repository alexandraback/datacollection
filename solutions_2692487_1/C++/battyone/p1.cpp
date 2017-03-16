#include "std.h"
#include "debug.h"
#include <string.h>

int v[128];
int mat[100][100];
char buf[1024];


int main() {
    int T;
    cin >> T; cin.getline(buf, sizeof buf);
    FOR(tt, T) {
	ZERO(mat);
	int full = 1;
	int A, n;
	cin >> A >> n; cin.getline(buf, sizeof buf);
	cerr << "Case " << tt << V(A) << V(n) << endl;
	cout << "Case #"<<(tt+1)<<": ";
	FOR(i, n) cin >> v[i];
	cin.getline(buf, sizeof buf);

	if (A == 1)
	{
	    cout << n << endl; continue;
	}

	sort(v, v + n);
	int ret = n;
	
	int r = 0;
	FOR(i, n)
	{
	    while (A <= v[i])
	    {
		A += A - 1;
		r++;
	    }
	    A += v[i];
	    ret = min(ret, r + (n - i - 1));
	    
	}
	cout << ret;

	cout << endl;
    }
    return 0;
}
