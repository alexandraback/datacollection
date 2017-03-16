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

int M[1000001];

int main(){
    freopen("A.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int ntsts;
	scanf("%d", &ntsts);
	for(int ntst = 1; ntst <= ntsts; ++ntst){
		int A, N;
		vi S;
		scanf("%d %d", &A,&N);
		REP(j,N){ int ss; scanf("%d", &ss); S.push_back(ss);}
		sort( ALL(S));
		int minact = N;
		int nadd = 0;
		for(int j = 0; j < N; ++j){
			again:
			if( S[j] < A ){
				A+=S[j];
			} else {
				minact = min(minact,nadd + N-j);
				nadd++;
				if( A == 1 ) goto fail;
				A+=A-1;
				goto again;
			}
			if( nadd >= minact ) break;
		}
		if( nadd < minact ) minact = nadd;
		fail:
		printf("Case #%d: %d", ntst, minact);
		printf("\n");
	}

	//printf("%I64d\n", nr);
	return 0;
}
