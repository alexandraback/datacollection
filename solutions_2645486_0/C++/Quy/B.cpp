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
int e,r,n,a[111];
int result;
void run(int p,int E,int mark){
	if ( p == n ){
		result = max(mark,result);
	}else{
		for(int i = 0 ; i <= E ; ++i){
			run(p+1,min(e,E-i+r),mark+i*a[p]);
		}
	}	
}
int main (int argc, char const* argv[]){
	if ( argc == 3 ){
		freopen(argv[1],"r",stdin);
		freopen(argv[2],"w",stdout);
	}
	int timing = clock();
	//---------------------------------
	int T; read(T);
	for(int tt = 1 ; tt <= T ; ++tt){
		read(e), read(r), read(n);
		for(int i = 0 ; i < n ; ++i){
			read(a[i]);
		}
		result = 0;
		run(0,e,0);
		printf("Case #%d: %d\n",tt,result);
	}
	//---------------------------------
//	assert((clock()-timing)*1000 / CLOCKS_PER_SEC<=2000);
	return 0;
}

/* DOAN Minh Quy - mquy.doan@gmail.com */
