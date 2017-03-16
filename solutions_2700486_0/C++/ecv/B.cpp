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
    freopen("A.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int ntsts;
	scanf("%d", &ntsts);
	for(int ntst = 1; ntst <= ntsts; ++ntst){
		int N, X, Y;
		scanf("%d %d %d", &N, &X, &Y);
		int lay = (abs(X)+Y)/2;
		int s,t;
		double p = 0;
		for(t = 1, s= 0; t <= N; s++,t+= 4*s+1){
			if( s >= lay ){
				p = 1; goto fin;
			}
		}
		if( s != lay ) goto fin;
		int t2 = t;
		t-= 4*s+1;
		for(int j = t+1, k=0; j <= N; ++j,k+=2){
			if( k >= Y && X != 0 ){
				p += 1/(2.*min( j-t,t2-j));
			}
		}
		fin:
		printf("Case #%d: %8.7f\n", ntst, p);
	}

	//printf("%I64d\n", nr);
	return 0;
}
