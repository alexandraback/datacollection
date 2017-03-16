#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i=0,_n=n; i<_n; i++)

#define EPS 1e-12
#define MAXN 55

typedef long double LD;

LD S[MAXN],P[MAXN],OS[MAXN],OP[MAXN];
int T,N,L[MAXN],OL[MAXN];

// collision time
LD calc(LD s1, LD p1, LD s2, LD p2){
	return (p1-(p2-5)) / (s2-s1);
}

// find the earliest car a that will overtake car b
LD find_earliest_collision(int &a, int &b){
	LD ret = 1e100;
	REP(i,N) REP(j,N)
		if (i!=j && S[i] > S[j]+EPS && P[i]+EPS < P[j] && L[i]==L[j])
			if (ret > calc(S[i],P[i], S[j],P[j])){
				ret = calc(S[i],P[i], S[j],P[j]);
				a = i; b = j;
			}
	return ret;
}

// all cars move by dt seconds
void move_cars(LD dt){
	REP(i,N) P[i] += S[i]*dt;

//	REP(i,N) printf("%d: %d %9Lf %9Lf\n",i,L[i],S[i],P[i]);
//	puts("");
}

bool intersect(LD p1a, LD p2a){
	LD p1b = p1a+5, p2b = p2a+5;
	return !(p1b - EPS < p2a || p2b - EPS < p1a);
}

bool switch_lane(int car){
	REP(i,N) if (i!=car && L[car] != L[i])
		if (intersect(P[car],P[i])) return false;
	L[car] = 1 - L[car];
	return true;
}

LD simulate(int mask){
	REP(i,N) S[i] = OS[i], P[i] = OP[i], L[i] = OL[i];
	int nth = 1, nn=0;
	for (LD t = 0; ; nth <<= 1, nn++){
		int car1, car2;
		LD dt = find_earliest_collision(car1, car2);
//		printf("collide %d %d %Lf\n",car1,car2,dt);
		if (dt > 1e50) return 1e100;
		move_cars(dt);
		t += dt;
		if (dt < EPS) return t;
		if (mask & nth){
			if (!switch_lane(car1)) return t;
		} else {
			if (!switch_lane(car2)) return t;
		}
		assert(nn<10);
	}
}

int main(){
	scanf("%d",&T);
	for (int tc=1; T--; tc++){
		fprintf(stderr,"Case #%d: \n",tc);
		printf("Case #%d: ",tc);

		char s[10]; scanf("%d",&N);
		REP(i,N) scanf("%s %Lf %Lf",s,&OS[i],&OP[i]), OL[i] = s[0]=='L';
		
		LD res = 0;
		REP(i,1<<10) res = max(res, simulate(i));
		if (res > 1e50) puts("Possible");
		else printf("%.6Lf\n",res);
		fflush(stdout);
	}
}
