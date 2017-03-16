/**
* @author Gareve
*/
#define DEBUGs
#ifndef NDEBUG	
	#define DBG(a) cout<<__LINE__<<": "<<#a<<"= "<<a<<endl;
#else
	#define DBG(a) ;
#endif
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <cmath>
#define foreach(IT,C) for(typeof(C.begin())IT=C.begin();IT!=C.end();IT++)

using namespace std;

long double vc[209];
long double sum;
int n;

const long double CERO = 0.0;
bool g(int x,long double p){
	long double points = vc[x] + p*sum;
	long double left = (1.0 - p);

	long double pp;
	long double tmp;
	for(int i=0;i<n;i++){
		if(x == i)continue;

		tmp = points - vc[i];
		if(tmp < 0.0)tmp = 0.0;
		pp = tmp / sum;
		left -= pp;
	}
	//printf("left = %.6Lf\n",left);
	return left <= CERO;
}
const long double CIEN = 100.0;
const long double DOS = 2.0;

long double f(int x){
	long double a = 0.0,b = 1.0,m;

	for(int i=1;i<=200;i++){
		m = (a + b) / 2.0;
		if(g(x,m))
			b = m;
		else
			a = m;
	}
	long double res = (a + b) / DOS;
	res *= CIEN;
	return res;
}
void resuelva(){
	scanf("%d",&n);
	sum = 0.0;
	for(int i=0;i<n;i++){
		scanf("%Lf",&vc[i]);
		sum += vc[i];
	}
	//DBG(g(0,0.2));
	long double perc;
	for(int i=0;i<n;i++){
		perc = f(i);
		printf(" %.6Lf",perc);
	}
	printf("\n");
}
int main(){
	int nc;
	scanf("%d",&nc);
	for(int i=1;i<=nc;i++){
		printf("Case #%d:",i);
		resuelva();
	}
}