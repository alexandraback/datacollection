#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

#define FOR(prom, a, b) for(int prom = (a); prom < (b); prom++)
#define FORD(prom, a, b) for(int prom = (a); prom > (b); prom--)
#define FORDE(prom, a, b) for(int prom = (a); prom >= (b); prom--)

#define DRI(a) int a; scanf("%d ", &a);
#define DRII(a, b) int a, b; scanf("%d %d ", &a, &b);
#define DRIII(a, b, c) int a, b, c; scanf("%d %d %d ", &a, &b, &c);
#define DRIIII(a, b, c, d) int a, b, c, d; scanf("%d %d %d %d ", &a, &b, &c, &d);
#define RI(a) scanf("%d ", &a);
#define RII(a, b) scanf("%d %d ", &a, &b);
#define RIII(a, b, c) scanf("%d %d %d ", &a, &b, &c);
#define RIIII(a, b, c, d) scanf("%d %d %d %d ", &a, &b, &c, &d);

#define PB push_back
#define MP make_pair

#define ll long long
#define ull unsigned long long

#define MM(co, cim) memset((co), (cim), sizeof((co)))

#define DEB(x) cerr << ">>> " << #x << " : " << x << endl;

void printLine(int C, int b, int start) {
	FOR(i,0,C) {
		if(i == start) cout << 'c';
		else if(i < b) cout << '*';
		else cout << '.';
	}
	cout << endl;
}

int main ()
{
  DRI(T);
  FOR(t,1,T+1) {
  	printf("Case #%d:\n", t);
  	DRIII(R,C,M);
  	int safe = R*C-M;
  	if(R == 1) {
  		cout << 'c';
  		FOR(i,1,C) {
  			if(i < safe) cout << '.';
  			else cout << '*';
			}
			cout << endl;
			continue;
  	}
  	if(C == 1) {
  		cout << 'c' << endl;
  		FOR(i,1,R) {
  			if(i < safe) cout << '.' << endl;
  			else cout << '*' << endl;
			}
			continue;
  	}
  	if(R == 2) {
  		if(safe == 2 || (safe % 2 == 1 && safe != 1)) cout << "Impossible" << endl;
  		else {
				cout << 'c';
				FOR(i,1,C) {
					if(i < safe/2) cout << '.';
					else cout << '*';
				}
				cout << endl;
				FOR(i,0,C) {
					if(i < safe/2) cout << '.';
					else cout << '*';
				}
				cout << endl;
			}
			continue;
  	}
  	if(C == 2) {
	  	if(safe == 2 || (safe % 2 == 1 && safe != 1)) cout << "Impossible" << endl;
	  	else {
				cout << 'c';
				if(safe == 1) cout << '*';
				else cout << '.';
				cout << endl;
				FOR(i,1,R) {
					if(i < safe/2) cout << ".." << endl;
					else cout << "**" << endl;
				}
			}
			continue;
  	}
  	// template
  	if(safe == 2 || safe == 3 || safe == 5 || safe == 7) {
  		cout << "Impossible" << endl;
  		continue;
  	}
  	FOR(r,0,R-3) {
  		if(M >= C) {
  			printLine(C,C,-1);
  			M -= C;
  		} else if(M == C-1) {
  			printLine(C,C-2,-1);
  			M -= C-2;
  		} else {
  			printLine(C,M,-1);
  			M = 0;
  		}
  	}
  	if(M%3==0) {
  		printLine(C,M/3,-1);
  		printLine(C,M/3,-1);
  		printLine(C,M/3,C-1);
  	} else if(M%3==1) {
  		printLine(C,M/3+1,-1);
  		printLine(C,M/3,-1);
  		printLine(C,M/3,C-1);
  	} else {
  		if(M+1==3*C) {
				printLine(C,C,-1);
				printLine(C,C,-1);
				printLine(C,C-1,C-1);
  		} else {
				printLine(C,M/3+2,-1);
				printLine(C,M/3,-1);
				printLine(C,M/3,C-1);
			}
  	}
  }
  return 0;
}





