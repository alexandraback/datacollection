#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i=0,_n=n; i<_n; i++)

#define EPS 1e-9

char M[100][100];
int TC,R,C,D;

struct Frac {
	int nom, den;
	Frac():nom(0),den(1){}
	Frac(int a):nom(a),den(1){}
	Frac(int a, int b):nom(a),den(b){ reduce(); }
	void reduce(){
		int g = __gcd(nom,den); nom /= g; den /= g;
		if (den < 0) den *= -1, nom *= -1;
	}
	double get(){ return (double) nom / den; }
	Frac operator*(Frac that){ return Frac(nom * that.nom, den * that.den); }
	Frac operator/(Frac that){ return Frac(nom * that.den, den * that.nom); }
	Frac operator+(Frac that){ return Frac(den*that.nom + that.den*nom, den * that.den); }
	Frac operator-(Frac that){ return Frac(-den*that.nom + that.den*nom, den * that.den); }
	bool operator<=(Frac that){ return nom * that.den <= den * that.nom; }
	bool operator<(Frac that){ return nom * that.den < den * that.nom; }
	bool operator>(Frac that){ return nom * that.den > den * that.nom; }
	bool operator==(Frac that){ return nom == that.nom && den == that.den; }
};

struct Pos {
	Frac r, c;
	Pos(){}
	Pos(Frac row, Frac col):r(row),c(col){}
	bool operator==(Pos that){ return r == that.r && c == that.c; }
};

// this point lies on the line segment (r1,c1) -> (r2,c2) with distance d from (r1,c1)
struct Point {	
	Pos p1, p2;
	double d;

	double distance(Pos p){
		Frac dr = p2.r - p1.r;
		Frac dc = p2.c - p1.c;
		double rat = d / sqrt((dr*dr + dc*dc).get());
		double r1(p1.r.get() + dr.get()*rat);
		double c1(p1.c.get() + dc.get()*rat);
		double r = r1 - p.r.get();
		double c = c1 - p.c.get();
		return sqrt(r*r + c*c);
	}

	bool inrangeC(Frac c, Frac &f){
		if (p1.c <= c && c <= p2.c || p2.c <= c && c <= p1.c){
			Frac dr = p2.r - p1.r;
			Frac dc = p2.c - p1.c;
			f = p1.r + (c - p1.c) / dc * dr;
			return true;
		}
		return false;
	}

	bool inrangeR(Frac r, Frac &f){
		if (p1.r <= r && r <= p2.r || p2.r <= r && r <= p1.r){
			Frac dr = p2.r - p1.r;
			Frac dc = p2.c - p1.c;
			f = p1.c + (r - p1.r) / dr * dc;
			return true;
		}
		return false;
	}

	// intersect mirror at (r,c)?
	bool intersectMirror(int r, int c, int k, Pos &p){
		Frac r1(r), r2(r+1), c1(c), c2(c+1);
		switch (k){
			case 0 : p.c = c1; if (inrangeC(c1,p.r)) if (r1 <= p.r && p.r <= r2) return true; break;
			case 1 : p.c = c2; if (inrangeC(c2,p.r)) if (r1 <= p.r && p.r <= r2) return true; break;
			case 2 : p.r = r1; if (inrangeR(r1,p.c)) if (c1 <= p.c && p.c <= c2) return true; break;
			case 3 : p.r = r2; if (inrangeR(r2,p.c)) if (c1 <= p.c && p.c <= c2) return true; break;
		}
		return false;
	}

	// pass through Pos p?
	bool passThrough(Pos p){
		Frac dr = p2.r - p1.r;
		Frac dc = p2.c - p1.c;
		Frac r = p.r - p1.r;
		Frac cc = r * dc / dr;	 // calculated c
		Frac c = p.c - p1.c;
		if (!(c == cc)) return false;
		double rat = d / sqrt((dr*dr + dc*dc).get());
		double rrr = p1.r.get() + dr.get() * rat;
		double ccc = p1.r.get() + dc.get() * rat;
		return rrr <= p.r.get() && p.r.get() <= p2.r.get() ||
				p2.r.get() <= p.r.get() && p.r.get() <= rrr;
	}

	bool touchesMirror(int r, int c, Pos p){
		return p == Pos(Frac(r),Frac(c)) ||
			p == Pos(Frac(r+1),Frac(c)) ||
			p == Pos(Frac(r),Frac(c+1)) ||
			p == Pos(Frac(r+1),Frac(c+1));
	}

	bool destroyedByMirror(int r, int c, Pos p){
		if (p == Pos(Frac(r),Frac(c))){
			return p1.r < p.r && p1.c < p.c;
		} else if (p == Pos(Frac(r+1),Frac(c))){
			return p1.r > p.r && p1.c < p.c;
		} else if (p == Pos(Frac(r),Frac(c+1))){
			return p1.r < p.r && p1.c > p.c;
		} else if (p == Pos(Frac(r+1),Frac(c+1))){
			return p1.r > p.r && p1.c > p.c;
		} else {
			assert(0);
		}
	}

	void reflectHor(Pos pos){
		p1.r = p1.r - (p1.r - pos.r) - (p1.r - pos.r);
		p2.r = p2.r - (p2.r - pos.r) - (p2.r - pos.r);
	}

	void reflectVer(Pos pos){
		p1.c = p1.c - (p1.c - pos.c) - (p1.c - pos.c);
		p2.c = p2.c - (p2.c - pos.c) - (p2.c - pos.c);
	}
};

// simulate a ray from (r,c) in the direction to (dr,dc)
bool ok(int r, int c, int dr, int dc){
	Frac sr = Frac(r) + Frac(1,2);
	Frac sc = Frac(c) + Frac(1,2);
	Frac er = Frac(r+dr) + Frac(1,2);
	Frac ec = Frac(c+dc) + Frac(1,2);
	Pos startingPoint(sr,sc);
	Point p = (Point){ startingPoint, Pos(er, ec), 0 };
	while (p.d - EPS <= D){
		p.d = p.d + 1e-7;		// just so that it don't bounce the same mirror again

//		printf("at %lf %lf -> %lf %lf, %lf D = %d\n",
//			p.p1.r.get(), p.p1.c.get(), p.p2.r.get(), p.p2.c.get(), p.d, D);
		vector<pair<int,int> > arr;		// intersect with these mirrors
		double nearestDist = 1e100;		// nearest distance to the mirrors
		Pos pos, nearestPoint;			// nearest point that hit the nearest mirror(s)

		REP(i,R) REP(j,C) if (M[i][j]=='#'){
			pos.r = Frac(i);
			pos.c = Frac(j);
			if (p.distance(pos) > nearestDist + 2.0) continue;
			REP(k,4) if (p.intersectMirror(i,j,k,pos)){
//				printf("M %d %d, %d %lf %lf\n",i,j,k,pos.r.get(),pos.c.get());
				if (!p.passThrough(pos)) continue;
				if (p.distance(pos) + EPS < nearestDist){
					nearestDist = p.distance(pos);
					nearestPoint = pos;
					arr.clear();
					arr.push_back(make_pair(i,j));
				} else if (p.distance(pos) - EPS < nearestDist){
					arr.push_back(make_pair(i,j));
				}
			}
		}

		sort(arr.begin(), arr.end());
		arr.erase(unique(arr.begin(), arr.end()), arr.end());

//		printf("Intersect Mirrors (%lf): ",nearestDist);
//		REP(i,arr.size()) printf("(%d, %d) ",arr[i].first,arr[i].second);
//		puts("");

		if (p.passThrough(startingPoint)){
			double dis = p.distance(startingPoint);
//			printf("dis = %lf\n",dis);
			if (dis + EPS < nearestDist){
				double d = p.d + dis;
				if (d - EPS <= D) return 1;
			}
		}

		if (arr.size() == 3){	// hits corner, reflect back
//			puts("REFLECT");
			p.reflectHor(nearestPoint);
			p.reflectVer(nearestPoint);
		} else if (arr.size() == 2){
			int x = abs(arr[0].first - arr[1].first) + abs(arr[0].second - arr[1].second);
			if (x == 2){		// straight through
//				puts("STRAIGHT 2");
			} else if (x==1){	// reflect one axis
				if (arr[0].first == arr[1].first){
//					puts("REFLECT -");
					p.reflectHor(nearestPoint);
				} else {
					assert(arr[0].second == arr[1].second);
//					puts("REFLECT |");
					p.reflectVer(nearestPoint);
				}
			} else {
				assert(0);		// impossible
			}
		} else if (arr.size() == 1){
			bool touches = p.touchesMirror(arr[0].first, arr[0].second, nearestPoint);
			if (touches){	// straight through
				if (p.destroyedByMirror(arr[0].first, arr[0].second, nearestPoint))
					return 0;		// the light is destroyed
//				puts("STRAIGHT 1");
			} else {			// reflect one axis
				if (nearestPoint.r == Frac(arr[0].first)){
//					puts("REFLECT -");
					p.reflectHor(nearestPoint);
				} else if (nearestPoint.r == Frac(arr[0].first) + Frac(1)){
//					puts("REFLECT -");
					p.reflectHor(nearestPoint);
				} else if (nearestPoint.c == Frac(arr[0].second)){
//					puts("REFLECT |");
					p.reflectVer(nearestPoint);
				} else {
//					puts("REFLECT |");
					assert(nearestPoint.c == Frac(arr[0].second) + Frac(1));
					p.reflectVer(nearestPoint);
				}
			}
		} else {
			assert(0);			// where is the mirror??
		}
		p.d = p.d + nearestDist;
	}
	return 0;
}

int main(int argc, char *argv[]){
	int lo=1, hi=100;

	if (argc == 3){
		sscanf(argv[1],"%d",&lo);
		sscanf(argv[2],"%d",&hi);
	}

	scanf("%d",&TC);
	for (int tc=1; TC--; tc++){
		scanf("%d %d %d",&R,&C,&D);
		REP(i,R) scanf("%s",M[R-1-i]);

		if (lo <= tc && tc <= hi){
			int res = 0, sr,sc;
			REP(i,R) REP(j,C) if (M[i][j]=='X') sr=i,sc=j;

			REP(i,100) if (M[sr+i][sc]=='#'){ if (i*2-1 <= D) res++; break; }
			REP(i,100) if (M[sr][sc+i]=='#'){ if (i*2-1 <= D) res++; break; }
			REP(i,100) if (M[sr-i][sc]=='#'){ if (i*2-1 <= D) res++; break; }
			REP(i,100) if (M[sr][sc-i]=='#'){ if (i*2-1 <= D) res++; break; }

			int LR = max(R, max(C, D)) + 1;
			for (int i=-LR; i<=LR; i++) if (i)
				for (int j=-LR; j<=LR; j++) if (j){
					if (__gcd(abs(i),abs(j))!=1) continue;
	//				printf("\nTRY %d %d, %d %d\n",sr,sc,i,j);
					if (ok(sr,sc,i*100,j*100)){
	//					printf("ok %d %d, %d %d\n",sr,sc,i,j);
						res++;
					} else {
	//					printf("NO %d %d, %d %d\n",sr,sc,i,j);
					}
				}
			printf("Case #%d: %d\n",tc,res);
			fprintf(stderr,"Case #%d: %d\n",tc,res);
			fflush(stdout);
		}
	}
}
