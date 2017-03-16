/* Problem	: 
** Time		:
** Algorithm:
**/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cassert>
using namespace std;
#define MOD 1000000007
#define MAXN 1000005
#define st first
#define nd second
#define read(x) scanf("%d",&x)
#define rep(i,a,b) for(int i = a ; i <= b ; ++i)
typedef long long int64;

int main (int argc, char const* argv[]){
	if ( argc == 3 ){
		freopen(argv[1],"r",stdin);
		freopen(argv[2],"w",stdout);
	}
	int timing = clock();
	//---------------------------------
	int T; read(T);
	int64 r,t;
	for(int tt = 1 ; tt <= T ; ++tt){
		cin>>r>>t; 
		int64 s = 0, cnt = 0;
		int64 lo = r, hi = 2500000000LL;
		while(lo + 1 < hi){
			int64 mi = (lo + hi) / 2;
			int64 ss = (( mi + r ) * ( mi - r + 1)) / 2;
			if ( ss > t ){
				hi = mi;
			}else{
				lo = mi;
			}
		}
//		cout << lo <<endl;
		s = (( lo + r ) * ( lo - r + 1 )) / 2;
//		cout << s <<" " << t << endl;
		while( true ){
			if ( s + lo + 1 <= t ){
				s += ++lo;
			}else{
				break;
			}
		}
//		cout << s <<" " << t << endl;
		while( s > t ){
			s -= lo--;
		}
		printf("Case #%d: ",tt);
		cout << (lo-r+1)/2<<endl;
	}
	//---------------------------------
	assert((clock()-timing)*1000 / CLOCKS_PER_SEC<=2000);
	return 0;
}

/* DOAN Minh Quy - mquy.doan@gmail.com */
