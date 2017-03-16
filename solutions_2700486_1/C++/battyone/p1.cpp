#include "std.h"
#include "debug.h"
#include <string.h>

int v[128];
int mat[100][100];
char buf[1024];

#define MAXX 10020
double prob[MAXX][MAXX];

void precalc()
{
    ZERO(prob);
    prob[0][0] = 1;
    FOR2(n, 1, MAXX)
    {
	prob[n][0] = prob[n][n] = prob[n-1][0] / 2;
	FOR2(p, 1, n) prob[n][p] = (prob[n-1][p-1] + prob[n-1][p]) / 2;
    }

}

int main() {
    precalc();
    int T;
    cin >> T; cin.getline(buf, sizeof buf);
    FOR(tt, T)
    {
	int N, x, y;
	cin >> N >> x >> y; cin.getline(buf, sizeof buf);
	//	cerr << "Case " << tt << V(A) << V(n) << endl;
	cout << "Case #"<<(tt+1)<<": ";
	int ph = (abs(x) + y) / 2;
	int p = 0;
	int psz = 1;
	int tot = 0;

	int tot0 = 0;
	while (p < ph)
	{
	    tot0 += 1 + 4 * p;
	    p++;
	}
	//cerr<<V(x)<<V(y)<<V(ph)<<V(tot0)<<endl;
	if (N <= tot0) { cout << "0.0" << endl; continue; }

	int tp = 1 + 4 * ph;
	int n = N - tot0;
	if (tp <= n) { cout << "1.0" << endl; continue; }
	if (y == 2*ph) { cout << "0.0" << endl; continue; }


	assert(tp < MAXX);
	double ret = 0;

	//cerr << V(ph)<<V(tot0)<<V(n)<<V(tp)<<endl;	
	//cerr << " prob:"<<vector<double>(&prob[tp][0], &prob[tp][tp+1])<<endl;

	if (ph * 2 + y + 1 <= n) { cout << "1.0" << endl; continue; }

	for(int i = (y+1); i <= n; i++) ret += prob[n][i];
	cout << ret << endl; continue;

	cout << endl;
    }
    return 0;
}
