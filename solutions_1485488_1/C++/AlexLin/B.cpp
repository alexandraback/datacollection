#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>

using namespace std;

#define Rep(i,n) for(int i = 0; i < n; ++i)
#define Rep2(i, f, t) for(int i = (f); i <= (t); ++i)
#define tr(C,it) for(__typeof__((C).begin()) it = (C).begin(); it != (C).end(); ++it)

#define toX(s) ((s) / m)
#define toY(s) ((s) % m)
#define toIdx(x, y) ((x) * m + (y))

const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const double eps = 1e-7;
const double inf = 1e30;
const int maxn = 100 + 10;
int n,m;
int Hfloor[maxn][maxn], Hceil[maxn][maxn];
int initLevel;

bool canGo(int fromX, int fromY, int toX, int toY) {
	//cout<<"See "<<fromX<<' '<<fromY<<' '<<toX<<' '<<toY<<endl;
	if(toX<0 || toY <0 || toX >= n || toY >= m) {
		return false;
	}
	bool ret = 
		Hceil[fromX][fromY] >= Hfloor[toX][toY] + 50 &&
		Hceil[toX][toY] >= Hfloor[fromX][fromY] + 50 &&
		Hceil[toX][toY] >= Hfloor[toX][toY] + 50;
	return ret;
}


double getCost(double startTime, int fromX, int fromY, int toX, int toY) {
	double waterLevel = initLevel - startTime * 10.0;
	double ret, dT;

	if(Hceil[toX][toY] < waterLevel + 50.0 - eps) {
		dT = (waterLevel - (Hceil[toX][toY] - 50.0)) / 10.0;
		return getCost(startTime + dT, fromX, fromY, toX, toY) + dT;
	} else if(Hceil[fromX][fromY] < waterLevel + 50.0 - eps) {
		dT = (waterLevel - (Hceil[fromX][fromY] - 50.0)) / 10.0;
		return getCost(startTime + dT, fromX, fromY, toX, toY) + dT;
	}
	if(startTime == 0.0) {
		return 0.0;
	}

	ret = waterLevel < Hfloor[fromX][fromY] + 20 ? 10 : 1;
	return ret;
}


const int maxnode = maxn * maxn;
double dist[maxnode + maxnode];
double rdist[maxnode];
int cntnode = 0;

#define lson(x) (((x)<<1) + 1)
#define rson(x) (((x)<<1) + 2)

int findBest() {
	int x = 0;
	while(x < cntnode - 1) {
		x = dist[lson(x)] == dist[x] ? lson(x) : rson(x);
	}
	return x - (cntnode - 1);
}

void modify(int pos, double val) {
	pos += cntnode - 1;
	dist[pos] = val;
	do {
		pos = (pos - 1) >> 1;
		dist[pos] = min(dist[lson(pos)], dist[rson(pos)]);
	}while(pos > 0);
}

void work() {
	cntnode = n * m;
	fill(dist, dist + cntnode + cntnode, inf);
	fill(rdist, rdist + cntnode, inf);
	modify(0, 0.0);
	rdist[0] = 0.0;
	int top;
	int curX, curY;
	int nextX, nextY;
	int nextNode;
	double bestDist, cost;
	while(true) {
		top = findBest();
		if(top == toIdx(n - 1, m - 1)) {
			break;
		}
		bestDist = dist[0];
		modify(top, inf);
		curX = toX(top);
		curY = toY(top);
		Rep(d, 4) {
			nextX = curX + dir[d][0];
			nextY = curY + dir[d][1];
			if(canGo(curX, curY, nextX, nextY)) {
				cost = getCost(bestDist, curX, curY, nextX, nextY);
				nextNode = toIdx(nextX, nextY);
				//cout<<"Next Node "<<nextNode<<' '<<cost<<endl;
				if(cost + bestDist < rdist[nextNode]) {
					rdist[nextNode] = cost + bestDist;
					modify(nextNode, cost + bestDist);
				}
			}
		}
	}
	printf("%.8f\n", rdist[toIdx(n - 1, m - 1)]);
}

int main() {
	int tc;
	scanf("%d", &tc);
	for(int nCase  = 1; nCase <= tc; ++nCase) {
		scanf("%d", &initLevel);
		scanf("%d%d", &n,&m);
		Rep(i, n) {
			Rep(j, m) {
				scanf("%d", Hceil[i] + j);
			}
		}
		Rep(i, n) {
			Rep(j, m) {
				scanf("%d", Hfloor[i] + j);
			}
		}
		printf("Case #%d: ", nCase);
		work();
	}
	return 0;
}

