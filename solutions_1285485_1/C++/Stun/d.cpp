#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

#ifndef MAXD
#define MAXD 51
#endif

#ifndef MAXDD
#define MAXDD 150
#endif

#ifndef SQR
#define SQR(x) ((x) * (x))
#endif

#ifndef SQD
#define SQD(a, b) (SQR((a.x) - (b.x)) + SQR((a.y) - (b.y)))
#endif

#ifndef EPS
#define EPS 1e-12
#endif

#ifndef MAXC
#define MAXC 31
#endif

bool M[MAXC][MAXC];
bool S[MAXDD][MAXDD];

struct point{
	int x;
	int y;
	
	point(){}
	point(int a, int b){x = a, y = b;}
};

bool operator < (point a, point b){
	point o(0,0);
	return (SQD(a,o) - SQD(b,o)) < 0;
}

point operator + (point a, point b){
	return point(a.x+b.x, a.y+b.y);
}

bool operator == (point a, point b){
	return a.x == b.x && a.y == b.y;
}

struct node{
	point lo;
	double dist;
	point from;
	node(){}
	node(point l, point f, double d){lo = l, from = f, dist = d;}
};

int gcd(int a, int b){
	a = abs(a);
	b = abs(b);

	if (a > b){
		int t = a;
		a = b;
		b = t;
	}
	
	if (a == 0) return b;
	return gcd(b % a, a);
}

void getMoveSet(vector<point> &move_set, point to){	
	if (to.x == 0){
		move_set.push_back(point(0, to.y / abs(to.y)));
		return;
	}else if (to.y == 0){
		move_set.push_back(point(to.x / abs(to.x), 0));			
		return;
	}
	point cur = point(0,0);
	int deltax = 1; //to.x / abs(to.x);
	int deltay = 1; //to.y / abs(to.y);
	int xx = to.x / abs(to.x);
	int yy = to.y / abs(to.y);
	to.x = abs(to.x);
	to.y = abs(to.y);	
	
	while(!(cur == to)){	
		// cout << cur.x << " " << cur.y << endl;		
		// cout << 2 * to.x * (cur.y + deltay) << " " << 2 * to.y * (cur.x + deltax) + (to.x - to.y) << endl;
		if (2 * to.x * (cur.y + deltay) < 2 * to.y * (cur.x + deltax) + (to.x - to.y)){
			move_set.push_back(point(0,deltay * yy));
			cur = cur + point(0,deltay);
		}else if (2 * to.x * (cur.y + deltay) == 2 * to.y * (cur.x + deltax) + (to.x - to.y)){
			move_set.push_back(point(deltax * xx,deltay * yy));
			cur = cur + point(deltax,deltay);
		}else {
			move_set.push_back(point(deltax* xx,0));
			cur = cur + point(deltax,0);							
		}
	}
}

bool isVisible(point to, point from){
	point cur;
	point cur_base;	
	point elementary = to;
	vector <point> move_set;
	// cout << from.x << " " << from.y  << " -> "<< to.x << " " << to.y << endl;
	if (to.x != 0 && to.y != 0){
		elementary = point(to.x / gcd(to.x, to.y), to.y / gcd(to.x, to.y));
	}
	getMoveSet(move_set, elementary);
	// getMoveSet(move_set, to);

	cur = cur_base = from;
	
	int idx = 0;
	int xa = 1, ya = 1;
	while(!(cur == from + to)){
		point move = move_set[idx % move_set.size()];
		cur = cur + move;
		move.x = move.x * xa;
		move.y = move.y * ya;

		if (M[cur_base.x + move.x][cur_base.y + move.y]){
			if (move.x && move.y){
				if (M[cur_base.x + move.x][cur_base.y] && M[cur_base.x][cur_base.y + move.y]){
					xa = -xa;
					ya = -ya;
				}else if (M[cur_base.x + move.x][cur_base.y]){
					xa = -xa;
					cur_base.y += move.y;
				}else if (M[cur_base.x][cur_base.y + move.y]){
					ya = -ya;
					cur_base.x += move.x;
				}else
					return false;
			}else{
				if (move.x){
					xa = -xa;
				}else{
					ya = -ya;
				}
			}
		}else{
			cur_base = cur_base + move;
		}
		// cout << cur_base.x << " " << cur_base.y << endl;		
		idx++;
		
		if ((idx % move_set.size()) == 0){
			if (S[cur.x + MAXD][cur.y + MAXD]){
				// cout << cur.x + MAXD << " " << cur.y + MAXD;
				// cout << " Here " << endl;
				return false;
			}
		}
	}
	if (cur_base == from) {
		S[cur.x + MAXD][cur.y + MAXD] = true;	
		// cout << ">>> " << cur.x + MAXD << " " << cur.y + MAXD << endl;
	}
	return (cur_base == from);
}

int main (int argc, char const *argv[])
{
	int t, h, w, d;
	
	vector<point> V;
		
	for(int i = -MAXD; i < MAXD ; i++){
		for (int j = -MAXD ; j < MAXD ; j++){
			if (!(i == 0 && j == 0) && SQD(point(0,0), point(i,j)) < SQR(MAXD))
				V.push_back(point(i,j));
		}
	}
	
	sort(V.begin(), V.end());
	
	// for (int i = 0 ; i < V.size() ; i++){
	// 	cout << V[i].x << " " << V[i].y << endl;
	// }
	
	// vector<point> move_set;
	// point test(-1,-1);
	// getMoveSet(move_set, test);
	// for (int i = 0 ; i < move_set.size() ; i++){
	// 	cout << move_set[i].x << " " << move_set[i].y << endl;
	// }
	// exit(1);	

	cin >> t;
	
	for(int casen = 1; casen <= t ; casen++){
		cin >> h >> w >> d;
		
		memset(M, 0, sizeof(bool) * MAXC * MAXC);
		memset(S, 0, sizeof(bool) * MAXDD * MAXDD);
		char in;
		point lo;
		for (int i = 1 ; i <= h ; i++){
			for (int j = 1 ; j <= w ; j++){
				cin >> in;
				if (in == '#') {
					M[i][j] = true;
				}else if (in == 'X'){
					lo = point(i, j);
				} 				
			}
		}
		int cnt = 0;
		for (int i = 0 ; i < V.size() && SQD(V[i], point(0,0)) <= SQR(d) ; i++){
			if (isVisible(V[i], lo)){
				cnt++;
			}
		}
		
		cout << "Case #" << casen << ": " << cnt << endl;
	}
	return 0;
}