#include <iostream>

using namespace std;

struct p {
  long long t;
  long long q;
};

long long simulate(long long cb, long long ct, long long bt, long long tt, long long b, long long t, long long n, long long m, p boxes[], p toys[], long long total) {
	if (cb == 0 && ct == 0)	if (b >= n || t >= n) return total; else return simulate(boxes[b].q, toys[t].q, boxes[b].t, toys[t].t, b + 1, t + 1, n, m, boxes, toys, total);
	if (cb == 0) if (b >= n) return total; else return simulate(boxes[b].q, ct, boxes[b].t, tt, b + 1, t, n, m, boxes, toys, total);
	if (ct == 0) if (t >= m) return total; else return simulate(cb, toys[t].q, bt, toys[t].t, b, t + 1, n, m, boxes, toys, total);
    if (bt == tt) {
       if (cb >= ct) return simulate(cb - ct, 0, bt, tt, b, t, n, m, boxes, toys, total + ct);
       else return simulate(0, ct - cb, bt, tt, b, t, n, m, boxes, toys, total + cb);
    } else {
	   long long x = simulate(cb, 0, bt, tt, b, t, n, m, boxes, toys, total);
	   long long y = simulate(0, ct, bt, tt, b, t, n, m, boxes, toys, total);
	   return max(x, y);
    }
}

void solve(long long t) {
	cout << "Case #" << t << ": ";

    long long n, m; cin >> n >> m;
  
    p boxes[n];
    p toys[m];

    for (long long i = 0; i < n; i++) cin >> boxes[i].q >> boxes[i].t;
    for (long long i = 0; i < m; i++) cin >> toys[i].q >> toys[i].t;

    cout << simulate(0, 0, 0, 0, 0, 0, n, m, boxes, toys, 0);

    cout << endl;
}

int main() {
	long long tc; cin >> tc;

	for (long long t = 1; t <= tc; t++) {
		solve(t);
	}

	return 0;
}
