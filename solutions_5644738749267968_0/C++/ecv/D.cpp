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
typedef std::vector<double> vd;
typedef std::vector<vi> vvi;
typedef std::vector<std::string> vs;
typedef std::vector<ii> vii;
#define sz(X) int((X).size())
#define REP(i,n) for(int i = 0; i < n; ++i)
#define FOR(i,v) for(int i = 0; i < int(v.size()); ++i)
#define ALL(v) v.begin(),v.end()
using namespace std;

int war( const vd &a, const vd &b, int M){
	int i=a.size()-M,j=0;
	int N = b.size();
	for(; i<N ; ++i,++j){
		j = int(std::lower_bound(b.begin()+j,b.begin()+M,a[i])-b.begin());
		if(j >= M)
			return N-i;
	}
	return 0;
}
int dwar(vd a,vd b){
	int N = a.size(), j = 0, k=0;
	for(int i = 0; i<N;++i){
		if(a[i] > b[k]){
			k++;
		}
	}
	return k;
}

int main(){
    FILE *f = freopen("A.txt","r",stdin);
	FILE *g = freopen("out.txt","w",stdout);
	int ntsts;
	cin>>ntsts;
	for(int ntst = 1; ntst <= ntsts; ++ntst){
		int N;
		cin>>N;
		vd a(N),b(N);
		for(auto &i:a) cin>>i; sort(a.begin(),a.end());
		for(auto &i:b) cin>>i; sort(b.begin(),b.end());

		int dw,w;

		w = war(a,b,N); 
		dw = dwar(a,b);


		fail:
		printf("Case #%d: %d %d\n",ntst,dw,w);
	}

	//printf("%I64d\n", nr);
	return 0;
}
