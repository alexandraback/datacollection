#include <stdio.h>
//#include <algorith>
#include <iostream>
#include <queue>

using namespace std;

class pe {
public:
	int x;
	int y;
	double time;
	pe(int x_, int y_, double time_) {
		x = x_;
		y = y_;
		time = time_;
	}
	friend bool operator<(const pe &a, const pe &b);
};
bool operator<(const pe &a, const pe &b) {
	return a.time > b.time;
}

static int vc[200][200], vf[200][200], volt[200][200], n, m;
static double h;
static priority_queue<pe> pq;


void check(int fromx, int fromy, double time, int tox, int toy)
{
	if (tox < 0 || tox >= n) return;
	if (toy < 0 || toy >= m) return;
	double hnow = h-10.0*time;
	int hc = vc[tox][toy];
	if (vf[fromx][fromy] > hc-50) return;
	if (vf[tox][toy] > hc-50) return;
	if (vf[tox][toy] > vc[fromx][fromy]-50) return;
	double tf = (h-hc+50)*0.1;
	double ts = max(tf, time);
	double tok;
	if (h-10.0*ts-vf[fromx][fromy] >= 20) tok = ts+1;
	else tok = ts+10;
	if (ts == 0) tok = 0;
	pq.push(pe(tox, toy, tok));
//	fprintf(stderr, "%d %d %lf -> %d %d %lf\n", fromx, fromy, time, tox, toy, tok);
}

int main(void)
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ti++) {
		int i, j;
		scanf("%lf %d %d", &h, &n, &m);
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				scanf("%d", &vc[i][j]);
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				scanf("%d", &vf[i][j]);
				volt[i][j] = 0;
			}
		}
		pq = priority_queue<pe>();
		pq.push(pe(0, 0, 0));
		double sol = -1;
		while (!pq.empty()) {
			pe e = pq.top();
			pq.pop();
			if (e.x == n-1 && e.y == m-1) {
				sol = e.time;
				break;
			}
			if (volt[e.x][e.y]) continue;
			volt[e.x][e.y] = 1;
			check(e.x, e.y, e.time, e.x-1, e.y);
			check(e.x, e.y, e.time, e.x+1, e.y);
			check(e.x, e.y, e.time, e.x, e.y-1);
			check(e.x, e.y, e.time, e.x, e.y+1);
		}
		printf("Case #%d: %.7lf\n", ti, sol);
	}
	return 0;
}
