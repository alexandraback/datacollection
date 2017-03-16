#include <bits/stdc++.h>
#define REP(x,n)  for(int x=0;x<(int)(n);x++)
#define RREP(x,n) for(int x=(int)(n)-1;x>=0;--x)
#define FOR(x,m,n) for(int x=(int)m;x<(int)(n);x++)
#define EACH(itr, cont) for(typeof((cont).begin()) itr = (cont).begin(); itr != (cont).end(); ++itr)
#define ALL(X)    (X).begin(),(X).end()
#define mem0(X)    memset((X),0,sizeof(X))
#define mem1(X)    memset((X),255,sizeof(X))

using namespace std;
typedef long long LL;

string dostuff() {
	int X, R, C;
	scanf("%i%i%i", &X, &R, &C);
	if (C < R)swap(C, R); //row smaller
	if (X > 6)return "RICHARD";// NOMINO BIG
	if ((R * C) % X != 0) return "RICHARD";// NOT DIVISIBLE
	if (X > 2 * R)return "RICHARD";// BLOCKING OMINO
	if (X > C) return "RICHARD";// LONG OMINO
	if (X == 4 && R == 2) return "RICHARD"; // SPEICAL
	if (X == 6 && R == 3) return "RICHARD"; // SPEICAL
	return "GABRIEL";
}

int main() {
	int T;
	scanf("%i", &T);
	REP(t, T) printf("Case #%i: %s\n", t + 1, dostuff().c_str());
}