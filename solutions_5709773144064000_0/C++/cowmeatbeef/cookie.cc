#include <iostream>
#include <sstream>
#include <cstdio>
using namespace std;

#define REP(i,a) for(int i=0;i<(a);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORE(i,a,b) for(int i=(a);i<=(b);i++)
#define SZ(x) ((int)x.size())

string l; // line of input
#define STR(s) getline(cin,l,'\n');s=l;
#define PAR(...) getline(cin,l,'\n');sscanf(l.c_str(),__VA_ARGS__);

void computeCase(int casen);

int main() {
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("B-small-attempt0.out", "wt", stdout);

	int ncases;
	PAR("%d",&ncases);

	FORE(i,1,ncases)
		computeCase(i);

	return 0;
}

void computeCase(int casen) {
	double C, F, X;
	PAR("%lf %lf %lf",&C,&F,&X);

	double cps = 2; // cookies per second
	double cookietime = X / cps; // time left to cookie-time
	double farmtime = C / cps; // time to buy cookie farm
	cps += F;
	double cookiefarmertime = farmtime + X / cps;
	while (cookiefarmertime < cookietime) {
		cookietime = cookiefarmertime; // time left to cookie-time
		farmtime += C / cps; // time to buy cookie farm
		cps += F;
		cookiefarmertime = farmtime + X / cps;
	}

	cout << "Case #" << casen << ": ";
	printf("%.7lf",cookietime);
	cout << endl;
}