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
vi num;

vii expr(int F, int R, int C, int mR){
	for(int c = C; c>=2; --c){
		int f = min(F/c,R);
		for(; f>=mR; --f){
			int F1 = F-f*c;
			if( F1 == 0){
				return vii(1,ii(f,c));
			}
			vii res = expr(F1,R-f,c-1,1);
			if( sz(res) > 0){
				res.push_back(ii(f,c));
				return res;
			}
		}
	}
	return vii();
}

int main(){
    FILE *f = freopen("A.txt","r",stdin);
	FILE *g = freopen("out.txt","w",stdout);
	int ntsts;
	cin>>ntsts;
	for(int ntst = 1; ntst <= ntsts; ++ntst){
		int R,C,M;
		bool sw = false;
		cin>>R>>C>>M;
		int F = R*C-M;
		vs B = vs(R,string(C,'*'));
		vii res;
		if( C == 1 ){
			res = vii(1,ii(F,1));
		} else if( R == 1 ){
			res = vii(1,ii(1,F));
		} else if( M+1 == R*C){
			res = vii(1,ii(1,1));
		} else {
			res = expr(F,R,C,2);
			if( sz(res) == 0){
				res = expr(F, C, R, 2);
				for(auto &i:res)
					swap(i.first,i.second);
			}
		}
		fail:
		printf("Case #%d:\n",ntst);
		if( sz(res) == 0 ){
			printf("Impossible\n",ntst);
		} else {
			int br = 0;
			for(int t = sz(res)-1; t>=0; --t){
				ii p = res[t];
				for(int r = br; r < br+p.first; ++r)
				for(int c = 0; c < p.second; ++c){
					B[r][c] = '.';
				}
				br += p.first;
			}
			B[0][0] = 'c';
			for(auto s:B)
				printf("%s\n",s.c_str());
		}
	}

	//printf("%I64d\n", nr);
	return 0;
}
