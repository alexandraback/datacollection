// CF.cpp: define el punto de entrada de la aplicaci?n de consola.
//
#pragma warning ( disable: 4996 )
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <iostream>

typedef std::pair<int,int> ii;
typedef long long int Int;
typedef unsigned long long int uInt;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<std::string> vs;
typedef std::vector<ii> vii;
#define sz(X) int((X).size())
#define REP(i,n) for(int i = 0; i < n; ++i)
#define FOR(i,v) for(int i = 0; i < int(v.size()); ++i)
#define ALL(v) v.begin(),v.end()
using namespace std;


int main(){
    FILE *f = freopen("A.txt","r",stdin);
	FILE *g = freopen("out.txt","w",stdout);
	int ntsts;
	cin>>ntsts;
	for(int ntst = 1; ntst <= ntsts; ++ntst){
		double F,C,X;
		cin>>C>>F>>X;
		double k = X/C-2.0/F, k2=0.;
		if(k<0.) k = 0.;
		double t1 = 0., b = X/2.0;
		for(int i = 0; ; ++i){
			t1 += C/(2+i*F);
			double c = t1+X/(2+F+i*F);
			if(c<b) b = c;
			else break;
		}
		fail:
		printf("Case #%d: %.7Lf",ntst, b);
		printf("\n");
	}

	//printf("%I64d\n", nr);
	return 0;
}
