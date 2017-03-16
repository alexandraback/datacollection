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
#include <set>
#define foreach(IT,C) for(typeof(C.begin())IT=C.begin();IT!=C.end();IT++)
#define P pair<int,int>
#define L long long

using namespace std;

int a,b;
set<P> st;
int len;
int diez[9];

int rotate(int x){
	int last = x%10;
	
	x/= 10;
	x += last * diez[len-1];	

	return x;
}
long long f(int x){
	len = log10(x) + 1;
	int y = x;
	L res = 0;
	do{	
		if(y > x and y <= b)
			res ++;
		y = rotate(y);
	}while(y != x);
	return res;
}
void resuelva(){
	scanf("%d %d",&a,&b);

	L res = 0;
	for(int i=a;i<b;i++){
		res += f(i);
	}
	printf("%lld\n",res);
}
int main(){
	diez[0]=1;
	for(int i=1;i<=6;i++)
		diez[i] = diez[i-1]*10;

	int nc;
	scanf("%d",&nc);
	for(int i=1;i<=nc;i++){
		printf("Case #%d: ",i);
		resuelva();
	}
}