// CF.cpp: define el punto de entrada de la aplicaci?n de consola.
#pragma warning ( disable: 4996 )
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
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

Int gcd(Int a, Int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int main(){
	FILE *f = freopen("in.txt","r",stdin);
	FILE *g = freopen("out.txt","w",stdout);
	int ntsts;
	cin>>ntsts;
	for(int ntst = 1; ntst<=ntsts; ++ntst){
		int n = -1;
		Int P,Q;
		char c;
		cin>>P>>c>>Q;
		Int d = gcd(P,Q);
		P /= d; Q/= d;
		Int Q2 = Q;
		while(Q2>1&&Q2%2==0){
			Q2 /= 2;
		}
		if(P== 0 || Q2>1)goto fail;
		n = 1;
		while( 2*P < Q){
			n++;
			Q /= 2;
		}

		fail:
		if( n >= 1) 
			cout<<"Case #"<<ntst<<": "<<n<<endl;
		else
			cout<<"Case #"<<ntst<<": impossible"<<endl;
	}
	//printf("%I64d\n", nr);
	return 0;
}
