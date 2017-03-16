#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <algorithm> 
#include <vector> 
#include <cmath> 
#include <map>
#include <cstring>
#include <string>
using namespace std; 

struct Position {
	double t, x, y, v, dt;
};

double D;
int N, A;
vector<Position> pos ;
vector<double> as ;


void input () {
	cin >> D >> N >> A;
	pos.clear(); as.clear();
	for ( int i=0;i<N;++i ) {
		Position p ;
		cin >> p.t >> p.x ;
		pos.push_back(p);
	}
	for ( int i=0;i<N-1;++i ) {
		pos[i].y = pos[i+1].x;
		pos[i].v = (pos[i+1].x-pos[i].x)/(pos[i+1].t-pos[i].t);
		pos[i].dt = pos[i+1].t-pos[i].t ;
		if ( pos[i].y >= D ) {
			pos[i].y = D ;
			N = i+1 ;
			pos[i].dt = (pos[i].y-pos[i].x)/pos[i].v;
			break;
		}
	}
	for ( int i=0;i<A;++i ) {
		double aa;
		cin >> aa; as.push_back(aa);
	}
}
// solve a*t^2 + b*5 + c = 0
double solve2 ( double a, double b, double c ) {
	return (-b+sqrt(b*b-4*a*c))/(2*a) ;
}
double solve22 ( double a, double b, double c ) {
	return (-b-sqrt(b*b-4*a*c))/(2*a) ;
}

double solv ( double a ) {
	double t=0, v=0, x=0 ;
	for ( int i=0;i<N;++i ) {
		double xx = pos[i].x, yy = pos[i].y ;
		double vv = pos[i].v ;
		
		if ( xx > D ) break;
		
		double dt = solve2 ( 0.5*a, v-vv, x-xx ) ;
		double hitPos = xx+vv*dt ;
		/*
		printf ( "(%.4f, %.4f, %.6f)\n", xx, yy, vv );
		
		printf ( "t: (%.6f, %.6f)\n", solve2 ( 0.5*a, v-vv, x-xx ), solve22 ( 0.5*a, v-vv, x-xx ) ) ;
		
		printf ( "hit: %.10f, ", hitPos ) ;
		//*/
		if ( hitPos > yy || hitPos < 0) {
			// 撞不到, 放開剎車
			x = (v+0.5*a*pos[i].dt)*pos[i].dt ;
			v = v + a*pos[i].dt;
			t = pos[i].t+pos[i].dt ;
		} else {
			// 撞到了, 跟上去
			v = pos[i].v ;
			x = pos[i].y ;
			t = pos[i].t+pos[i].dt ; 
		}
		// printf ( "(%.4f, %.4f, %.4f)\n", x, v, t ) ;
	}
	if ( x < D ) {
		t += solve2(0.5*a, v, x-D) ;
	}
	
	return t;
}

void solv () {
/*
	for ( int i=0;i<N;++i ) {
		printf ( "((%.4f, %.4f), %.9f, (%.4f, %.4f))\n", pos[i].x, pos[i].y, pos[i].v, pos[i].t, pos[i].dt );
	}
//*/
	for ( int i=0;i<A;++i ) {
		printf ( "%.7f\n", solv(as[i]) ) ;
	}
}

int main() 
{ 
    int T, nCase = 1 ; 
    cin >> T ; 
    while ( T-- ) { 
        input();
		
		printf ( "Case #%d:\n", nCase++ ) ; 
        solv () ;
    } 

    return 0; 
}
